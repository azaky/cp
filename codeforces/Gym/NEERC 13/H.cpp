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
#include <limits>
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

#define MAXN 100100
int n, a[MAXN], sxor[MAXN], next[MAXN][33];
int bit[MAXN];


int query(int k) {
	int ret = 0;
	for (int x = k; x > 0; x -= x & -x) {
		ret += bit[x];
	}
	return ret;
}

void update(int k, int v) {
	for (int x = k; x <= n; x += x & -x) {
		bit[x] += v;
	}
}

int main(){
	OPEN("hack");
	
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", &a[i]);
	}
	// calculates xor
	sxor[0] = 0;
	FOR(i, 1, n) {
		sxor[i] = sxor[i-1] ^ a[i];
	}
	// calculates next
	REP(i, 31) {
		next[n+1][i] = n+1;
	}
	FORD(i, n, 1) {
		REP(j, 31) {
			next[i][j] = next[i+1][j];
			if ((a[i] & (1 << j)) == 0) {
				next[i][j] = i;
			}
		}
	}
	
	// collecting queries
	vector<pair<int, pii> > q;
	FOR(i, 1, n) {
		//calculates ranges
		vector<int> nnext(next[i], next[i] + 31);
		sort(ALL(nnext));
		vector<pii> ranges;
		int last = i;
		REP(j, 31) {
			if (last == nnext[j]) continue;
			ranges.PB(MP(last, nnext[j]-1));
			last = nnext[j];
		}
		if (last <= n) {
			ranges.PB(MP(last, n));
		}
		//printf("i = %d\n", i);
		// calculates answer (this time for real)
		int num = a[i];
		FORIT(it, ranges) {
			num &= a[it->A];
			q.PB(MP(num ^ sxor[i-1], *it));
			//printf("%d..%d : %d\n", it->A, it->B, num ^ sxor[i-1]);
		}
	}
	
	// precalc vector pos
	map<int, vector<int> > pos;
	FOR(i, 1, n) {
		if (!EXIST(sxor[i], pos)) {
			pos[sxor[i]] = vector<int>();
		}
		pos[sxor[i]].PB(i);
	}
	
	// calculates answer
	ll ans = 0;
	sort(ALL(q));
	int last = -1;
	FORIT(it, q) {
		if (it->A != last) {
			// erase BIT
			if (EXIST(last, pos)) {
				vector<int> ppos = pos[last];
				FORIT(iit, ppos) {
					update(*iit, -1);
				}
			}
			last = it->A;
			// update BIT
			if (EXIST(last, pos)) {
				vector<int> ppos = pos[last];
				FORIT(iit, ppos) {
					update(*iit, +1);
				}
			}
		}
		//printf("query: %d (%d..%d)\n", it->A, (it->B).A, (it->B).B);
		//FOR(i, 1, n) printf("%d ", query(i) - query(i-1)); printf("\n");
		ans += (ll)(query((it->B).B) - query((it->B).A - 1));
	}
	
	cout << ans << endl;
	
	return 0;
}
