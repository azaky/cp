#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

int ntc, n, r, o, y, g, b, v;
char ans[1111];
int p[10], d[1111][1111];

bool check() {
	REP(i, n) {
		int j = (i + 1) % n;
		if (!ans[i] || !ans[j]) return false;
		if (d[ans[i]][ans[j]]) return false;
	}
	return true;
}

int main(){
	d['R']['R'] = 1;
	d['O']['O'] = 1;
	d['Y']['Y'] = 1;
	d['G']['G'] = 1;
	d['B']['B'] = 1;
	d['V']['V'] = 1;
	d['O']['R'] = d['R']['O'] = 1;
	d['O']['Y'] = d['Y']['O'] = 1;
	d['G']['Y'] = d['Y']['G'] = 1;
	d['G']['B'] = d['B']['G'] = 1;
	d['V']['B'] = d['B']['V'] = 1;
	d['V']['R'] = d['R']['V'] = 1;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d%d%d%d", &n, &r, &o, &y, &g, &b, &v);

		vector<pair<int, char> > a;
		a.PB(MP(r, 'R'));
		a.PB(MP(o, 'O'));
		a.PB(MP(y, 'Y'));
		a.PB(MP(g, 'G'));
		a.PB(MP(b, 'B'));
		a.PB(MP(v, 'V'));

		REP(i, 6) {
			p[i] = i;
		}

		bool possible = false;
		do {
			vector<pair<int, char> > b;
			REP(i, 6) b.PB(a[p[i]]);
			int pos = 0;
			RESET(ans, 0);
			REP(i, 6) {
				REP(j, b[i].A) {
					while (ans[pos]) {
						pos++;
						pos %= n;
					}
					ans[pos] = b[i].B;
					pos += 2;
					pos %= n;
				}
			}
			if (check()) {
				possible = true;
				break;
			}
		} while (next_permutation(p, p + 6));

		if (possible) {
			printf("Case #%d: %s\n", itc, ans);
		} else {
			printf("Case #%d: IMPOSSIBLE\n", itc);
		}
	}
	
	return 0;
}