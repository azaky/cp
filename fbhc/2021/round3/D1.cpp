#include <bits/stdc++.h>
using namespace std;

const int dr[4] = {0, 0, 1, -1};
const int dc[4] = {1, -1, 0, 0};

int R, C;
vector<vector<int>> H, S;

int toi(int r, int c) {
  return C * r + c;
}
pair<int,int> top(int x) {
  return make_pair(x / C, x % C);
}

map<int,vector<int>> mH, mS;
vector<int> V;

void solve(int itc) {
  scanf("%d%d", &R, &C);
  H.resize(R);
  S.resize(R);
  mH.clear();
  mS.clear();
  V.clear();
  for (int i = 0; i < R; ++i) {
    H[i].resize(C);
    S[i].resize(C);
  }
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      scanf("%d", &H[i][j]);
      mH[H[i][j]].push_back(toi(i, j));
      V.push_back(H[i][j]);
    }
  }
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      scanf("%d", &S[i][j]);
      mS[S[i][j]].push_back(toi(i, j));
      V.push_back(S[i][j]);
    }
  }
  sort(V.rbegin(), V.rend());
  V.resize(unique(V.begin(), V.end()) - V.begin());

  vector<int> p(R*C), sz(R*C, 0), a(R*C, 0);
  for (int i = 0; i < R*C; ++i) {
    p[i] = i;
  }

  function<int(int)> findSet = [&](int x) -> int {
    if (p[x] == x) return x;
    return p[x] = findSet(p[x]);
  };

  int ans = 0;

  for (int v : V) {
    // First, check for S.
    for (int x : mS[v]) {
      auto pp = top(x);
      int r = pp.first, c = pp.second;
      if (H[r][c] <= S[r][c]) continue;

      int s = findSet(x);
      if (sz[s] == 0) sz[s]++;
      ans++;
    }
    // Then, activate cells.
    for (int x : mH[v]) {
      auto pp = top(x);
      int r = pp.first, c = pp.second;
      assert(!a[x]);
      a[x] = 1;
      // join with neighbors
      for (int d = 0; d < 4; ++d) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        int nx = toi(nr, nc);
        if (a[nx]) {
          int sx = findSet(x);
          int snx = findSet(nx);
          if (sx != snx) {
            p[sx] = snx;
            sz[snx] += sz[sx];
          }
        }
      }
    }
  }

  printf("%d %d\n", ans, sz[findSet(0)]);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve(itc);
  }
}