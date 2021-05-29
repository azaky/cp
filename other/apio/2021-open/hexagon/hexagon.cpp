#include "hexagon.h"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll multiplicativeInverse(ll a, ll m) {
  ll x = 0, y = 1, lastx = 1, lasty = 0, b = m;
  while (b != 0) {
    ll q = a / b;
    ll temp = a;
    a = b;
    b = temp % b;
    temp = x;
    x = lastx - q * x;
    lastx = temp;
    temp = y;
    y = lasty - q * y;
    lasty = temp;
  }
  return ((lastx % m) + m) % m;
}


const int dd[6][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1} };

#define MOD 1000000007LL

#define BOUND 1100

int grid[BOUND + 1][BOUND + 1];
int dis[BOUND + 1][BOUND + 1];

int draw_territory(int N, int A, int B, vector<int> D, vector<int> L) {
  memset(grid, 0, sizeof(grid));

  // subtask 1 & 2
  if (N == 3) {
    assert(L[0] == L[1] && L[1] == L[2]);
    ll L1 = (ll)L[0] * (L[0] + 1) / 2 % MOD;
    ll L2 = L1 * (2 * L[0] + 1) % MOD * multiplicativeInverse(3, MOD) % MOD;
    ll LL1 = (L1 + L[0] + 1) % MOD;
    ll ans = ((ll)A * LL1 + (ll)B * (L1 + L2)) % MOD;

    return ans;
  }

  // first, determine boundary
  int minr = 0, maxr = 0, minc = 0, maxc = 0;
  int r = 0, c = 0;
  for (int i = 0; i < N; ++i) {
    r += dd[D[i]-1][0] * L[i];
    c += dd[D[i]-1][1] * L[i];
    minr = min(minr, r);
    maxr = max(maxr, r);
    minc = min(minc, c);
    maxc = max(maxc, c);
  }

  r = -minr + 1, c = -minc + 1;
  grid[r][c] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < L[i]; ++j) {
      r += dd[D[i]-1][0];
      c += dd[D[i]-1][1];
      assert(r > 0 && r < BOUND && c > 0 && c < BOUND);
      grid[r][c] = 1;
    }
  }
  assert(r == -minr + 1 && c == -minc + 1);

  // fill outside
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  while (!q.empty()) {
    int cr = q.front().first;
    int cc = q.front().second;
    q.pop();
    for (int d = 0; d < 6; ++d) {
      int nr = cr + dd[d][0];
      int nc = cc + dd[d][1];
      if (nr < 0 || nr > BOUND) continue;
      if (nc < 0 || nc > BOUND) continue;
      if (grid[nr][nc]) continue;
      grid[nr][nc] = -1;
      q.emplace(nr, nc);
    }
  }

  long long ans = 0;

  dis[r][c] = 0;
  grid[r][c] = 2;
  q.emplace(r, c);
  while (!q.empty()) {
    r = q.front().first;
    c = q.front().second;
    q.pop();

    int cdis = dis[r][c];
    ans += A + (ll)B * cdis;
    ans %= MOD;

    // fprintf(stderr, "now at (%d, %d), dis = %d\n", r, c, cdis);

    for (int d = 0; d < 6; ++d) {
      int nr = r + dd[d][0];
      int nc = c + dd[d][1];
      if (grid[nr][nc] == -1) continue;
      if (grid[nr][nc] == 2) continue;
      dis[nr][nc] = cdis + 1;
      grid[nr][nc] = 2;
      q.emplace(nr, nc);
    }
  }

  return ans;
}
