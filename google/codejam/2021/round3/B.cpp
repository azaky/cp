#include <bits/stdc++.h>
using namespace std;

#define MAXN 1111
#define INF 0x3FFFFFFF

int res[MAXN][MAXN];

/** Maximum Flow **/
/* Edmond Karp | complexity : O(|V|*(|V|+|E|)) */
void augment(int v, int minEdge, int& s, int& f, vector<int>& p) {
  if (v == s) { f = minEdge; return; }
  else if (p[v] != -1) {
    augment(p[v], min(minEdge, res[p[v]][v]), s, f, p); res[p[v]][v] -= f; res[v][p[v]] += f;
  }
}
int maxFlowEdmondKarp(int n, int source, int target) {
  int mf = 0;
  while (1) {
    int f = 0;
    vector<int> dist(n + 5, INF);
    dist[source] = 0;
    queue<int> q; q.push(source);
    vector<int> p; p.assign(n + 5, -1);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == target) break;
      for (int v = 0; v < n; v++)
        if (res[u][v] > 0 && dist[v] == INF)
          dist[v] = dist[u] + 1, q.push(v), p[v] = u;
    }
    augment(target, INF, source, f, p);
    if (f == 0) break;
    mf += f;
  }
  return mf;
}


void solve() {
  int R, C;
  scanf("%d%d", &R, &C);
  vector<int> S(R), D(C);

  int Ssum = 0, Dsum = 0;
  for (int i = 0; i < R; ++i) {
    scanf("%d", &S[i]);
    Ssum += S[i];
  }
  for (int i = 0; i < C; ++i) {
    scanf("%d", &D[i]);
    Dsum += D[i];
  }

  memset(res, 0, sizeof(res));
  // 0: source
  // 1-R: R
  // R + 1-C: C
  // R + C +1: sink
  int source = 0;
  int sink = R + C + 1;
  for (int i = 0; i < R; ++i) {
    res[0][i+1] = S[i];
  }
  for (int j = 0; j < C; ++j) {
    res[R + j+1][sink] = D[j];
  }
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      res[i+1][R + j+1] = 1;
    }
  }

  int mf = maxFlowEdmondKarp(R + C + 2, source, sink);
  if (mf != Ssum || mf != Dsum) {
    puts("IMPOSSIBLE");
    return;
  }

  vector<vector<char>> A(R, vector<char>(C, '\\'));

  // puts("");
  // for (int i = 0; i < R; ++i) {
  //   for (int j = 0; j < C; ++j) {
  //     printf("%d ", res[i+1][R+j+1]);
  //   }
  //   putchar('\n');
  // }

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (res[i+1][R+j+1] == 0) {
        A[i][j] = '/';
      }
    }
  }

  auto printBoard = [&]() {
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < C; ++j) {
        putchar(A[i][j]);
      }
      putchar('\n');
    }
  };

  auto findSquare = [&]() -> pair<int,pair<int,int>> {
    for (int s = 1; s <= min(R, C)/2; ++s) {
      for (int i = 0; i + 2*s <= R; ++i) {
        for (int j = 0; j + 2*s <= C; ++j) {
          bool square = true;
          for (int k = 0; k < s && square; ++k) {
            // left-top
            if (A[i + (s-1) - k][j + k] == '\\') square = false;
            // top-right
            if (A[i + k][j + s + k] == '/') square = false;
            // right-bottom
            if (A[i + s + (s-1) - k][j + s + k] == '\\') square = false;
            // left-bottom
            if (A[i + s + k][j + k] == '/') square = false;
          }
          if (square) {
            return make_pair(s, make_pair(i, j));
          }
        }
      }
    }
    return make_pair(0, make_pair(0, 0));
  };

  while (true) {
    // printBoard();

    auto square = findSquare();

    int s = square.first;
    int i = square.second.first;
    int j = square.second.second;

    if (s == 0) break;
    
    // printf("found square s = %d, (%d, %d)\n", s, i, j);

    swap(A[i][j + s-1], A[i][j + s]);
    swap(A[i + 2*s - 1][j + s-1], A[i + 2*s - 1][j + s]);
  }

  puts("POSSIBLE");
  printBoard();
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}