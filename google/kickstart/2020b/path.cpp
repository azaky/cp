#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
#define MAXN 2020

char s[MAXN];

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  stack<pair<long long, long long> > d;
  stack<long long> m;
  d.emplace(0, 0);
  m.push(1);
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if ('2' <= c && c <= '9') {
      i++;
      d.emplace(0, 0);
      m.push(c - '0');
      continue;
    }
    if (c == ')') {
      pair<long long, long long> dt = d.top(); d.pop();
      long long mt = m.top(); m.pop();
      dt.first *= mt; dt.first %= MOD;
      dt.second *= mt; dt.second %= MOD;
      d.top().first += dt.first;
      d.top().first %= MOD;
      d.top().second += dt.second;
      d.top().second %= MOD;
      continue;
    }
    if (c == 'N') {
      d.top().second += MOD-1;
      d.top().second %= MOD;
    }
    if (c == 'S') {
      d.top().second++;
      d.top().second %= MOD;
    }
    if (c == 'W') {
      d.top().first += MOD-1;
      d.top().first %= MOD;
    }
    if (c == 'E') {
      d.top().first++;
      d.top().first %= MOD;
    }
  }
  long long w = d.top().first + 1;
  long long h = d.top().second + 1;
  printf("%lld %lld\n", w, h);
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve();
  }
}