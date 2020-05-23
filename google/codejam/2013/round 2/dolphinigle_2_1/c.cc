// Authored by dolphinigle
// GCJ 2013 2

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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>

#define FORN(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define REP(X,Y,Z) for (int (X) = (Y);(X) < (Z);++(X))

#define RE(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define FOR(X,Y,Z) for (int (X) = (Y);(X) <= (Z);++(X))

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

int a[5050];
int b[5050];
int used[5050];

int ais[5050];
int bis[5050];

int ada[2500][2500];
int boleh[2500];
int filled[2500];

int main() {
  int ntc;
  cin >> ntc;
  
  FORN(itc, ntc) {
    cout << "Case #" << (itc+1) << ":";
    int n;
    cin >> n;
    vint seq;
    FORN(i, 2500) FORN(j, 2500) ada[i][j] = 0;
    FORN(i, n) {
      cin >> a[i];
    }
    FORN(i, n) {
      cin >> b[i];
    }
    FORN(i, 2500) boleh[i] = 0;
    FORN(i, n) FORN(j, n) if (i != j && a[i] <= a[j] && b[i] <= b[j]) boleh[j] += 1;
    FORN(i, n) ada[a[i]][b[i]] += 1;
    FORN(i, n) filled[i] = 0;
    FOR(i, 1, n) {
      FORN(j, n) ais[j] = bis[j] = 1;
      FOR(j, 0, n-1) {
        if (j) ais[j] = ais[j-1];
        if (filled[j]) ais[j] = max(a[j]+1, ais[j]);
      }
      for (int j = n-1; j >= 0; --j) {
        if (j != n-1) bis[j] = bis[j+1];
        if (filled[j]) bis[j] = max(bis[j], b[j]+1);
      }
      FORN(j, n) if (!boleh[j] && !filled[j] && a[j] == ais[j] && b[j] == bis[j]) {
        ada[ais[j]][bis[j]] -= 1;
        filled[j] = i;
        FORN(k, n) if (a[k] >= a[j] && b[k] >= b[j]) boleh[k] -= 1;
        break;
      }
    }
    FORN(i, n) {
      cout << " " << filled[i];
    }
    cout << endl;
  }
  return 0;
}
