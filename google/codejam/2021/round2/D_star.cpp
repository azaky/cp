#include <bits/stdc++.h>
using namespace std;

typedef __uint128_t T;

int r, c, F, S;

int a[10][10], b[10][10], y[10][10];
int t1[10][10], t2[10][10];

T pack(int x[][10]) {
  T t = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int k = i*c + j;
      if (x[i][j]) {
        t ^= T(1) << k;
      }
    }
  }
  return t;
}

void unpack(int x[][10], T t) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int k = i * c + j;
      if (t & (T(1) << k)) {
        x[i][j] = 1;
      } else {
        x[i][j] = 0;
      }
    }
  }
}

int diff(T a, T b) {
  int cc[2] = {0};
  unpack(t1, a);
  unpack(t2, b);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (t1[i][j] != t2[i][j]) {
        cc[t1[i][j]]++;
      }
    }
  }
  return S * min(cc[0], cc[1]) + F * abs(cc[0] - cc[1]);
}

void print(int x[][10]) {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      printf("%d", x[i][j]);
    }
    puts("");
  }
}

void solve() {
  scanf("%d%d%d%d", &r, &c, &F, &S);
  for (int i = 0; i < r; ++i) {
    static char buffer[100];
    scanf("%s", buffer);
    for (int j = 0; j < c; ++j) {
      if (buffer[j] == 'G') {
        a[i][j] = 1;
      } else {
        a[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < r; ++i) {
    static char buffer[100];
    scanf("%s", buffer);
    for (int j = 0; j < c; ++j) {
      if (buffer[j] == 'G') {
        b[i][j] = 1;
      } else {
        b[i][j] = 0;
      }
    }
  }

  T A = pack(a);
  T B = pack(b);

  priority_queue<pair<int, T>> pq;
  map<T, int> f, g;

  f[A] = diff(A, B);
  g[A] = 0;
  pq.push(make_pair(-f[A], A));

  int best = -1;

  while (!pq.empty()) {
    auto current = pq.top(); pq.pop();

    T Y = current.second;
    int cost = -current.first;

    if (cost != f[Y]) continue;

    unpack(y, Y);

    // print(y);
    // printf("cost = %d\n", cost);
    // puts("");

    if (Y == B) {
      if (best == -1 || cost < best) {
        best = cost;
        break;
      }
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        auto check = [&](int add) -> void {
          T X = pack(y);
          int cg = g[Y] + add;
          if (g.count(X) == 0 || cg < g[X]) {
            g[X] = cg;
            int cf = cg + diff(X, B);
            f[X] = cf;
            pq.push(make_pair(-cf, X));
          }
        };

        //flip
        y[i][j] = 1-y[i][j];
        check(F);
        y[i][j] = 1 - y[i][j];

        // swap
        if (i > 0 && y[i][j] != y[i-1][j]) {
          swap(y[i][j], y[i-1][j]);
          check(S);
          swap(y[i][j], y[i-1][j]);
        }
        if (j > 0 && y[i][j] != y[i][j-1]) {
          swap(y[i][j], y[i][j-1]);
          check(S);
          swap(y[i][j], y[i][j-1]);
        }
      }
    }
  }

  printf("%d\n", best);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}