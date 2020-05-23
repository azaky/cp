#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define MAXC 2000000

int n, k, ans;
char s[MAXC+5];
int v[MAXC+5][26], c[MAXC+5];

int dfs(int x, int d) {
  int t = c[x];
  for (int i = 0; i < 26; ++i) {
    if (v[x][i] != -1) {
      t += dfs(v[x][i], d+1);
    }
  }
  ans += d * (t / k);
  return t % k;
}

void solve() {
  scanf("%d%d", &n, &k);
  int nnodes = 1;
  memset(v[0], -1, sizeof(v[0]));
  c[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s), node = 0;
    for (int j = 0; j < len; ++j) {
      int ch = s[j] - 'A';
      if (v[node][ch] == -1) {
        memset(v[nnodes], -1, sizeof(v[nnodes]));
        c[nnodes] = 0;
        v[node][ch] = nnodes++;
      }
      node = v[node][ch];
    }
    c[node]++;
  }
  ans = 0;
  dfs(0, 0);
  printf("%d\n", ans);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}