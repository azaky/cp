#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n, a[MAXN];
vector<int> adj[MAXN];

int main() {
  scanf("%d", &n);
  bool allzero = true;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (a[i]) allzero = false;
  }
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  if (allzero || (n == 2 && a[1] && a[2])) {
    puts("NO");
  } else {
    puts("YES");
  }
}