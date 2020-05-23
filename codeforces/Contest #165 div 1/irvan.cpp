// Authored by dolphinigle
// Codeforces 165
// 1 Feb 2012

#include <vector>
#include <list>
#include <map>
#include <set>

#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define SZ(Z) ((int)(Z).size())
#define ALL(W) (W).begin(), (W).end()
#define PB push_back

#define MP make_pair
#define A first
#define B second

#define INF 1023123123
#define EPS 1e-11

#define MX(Z,Y) Z = max((Z),(Y))
#define MN(X,Y) X = min((X),(Y))

#define FORIT(X,Y) for(typeof((Y).begin()) X = (Y).begin();X!=(Y).end();X++)

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> vint;

int incom[205000];
int outcom[205000];
int ans[205000];

vint adj[205000];
vint cost[205000];
vint id[205000];
vint dir[205000];
int ashar[205000];

int main() {
  int n, m;
  cin >> n >> m;
  FORN(i, m) ans[i] = -1;
  FORN(i, m) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    if (a == 0) {
      ans[i] = 0;
      incom[b] += c;
    } else if (b == 0) {
      ans[i] = 1;
      incom[a] += c;
    } else if (a == n-1) {
      ans[i] = 1;
      outcom[b] += c;
    } else if (b == n-1) {
      ans[i] = 0;
      outcom[a] += c;
    } else {
      outcom[a] += c;
      outcom[b] += c;
      adj[a].PB(b);
      cost[a].PB(c);
      id[a].PB(i);
      dir[a].PB(0);
      adj[b].PB(a);
      cost[b].PB(c);
      id[b].PB(i);
      dir[b].PB(1);
    }
  }
  ashar[0] = -1;
  ashar[n-1] = -1;

  // who is guilty?
  stack<int> guilty;
  for (int i = 1; i < n-1; ++i) {
    if (incom[i] == outcom[i]) {
      guilty.push(i);
      ashar[i] = 1;
    }
  }

  while (!guilty.empty()) {
    int target = guilty.top();
    guilty.pop();
    if (incom[target] != outcom[target]) {
      // ....??
      assert(false);
    }
    FORN(i, SZ(adj[target])) {
      if (ans[id[target][i]] == -1) {
        ans[id[target][i]] = dir[target][i];
        int c = cost[target][i];
        int nex = adj[target][i];
        incom[nex] += c;
        outcom[nex] -= c;
        if (!ashar[nex] && incom[nex] == outcom[nex]) {
          ashar[nex] = 1;
          guilty.push(nex);
        }
      }
    }
  }

  FORN(i, m) {
    printf("%d\n", ans[i]);
    assert(ans[i] != -1);
  }
    
}
