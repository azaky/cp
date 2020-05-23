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

#define MOD 21092013

int ntc;
string s, t;

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		cin >> s >> t;
		
		// alter s!
		vector<char> ss;
		FORIT(it, s) {
			if (*it == 'U') {
				if (!ss.empty()) ss.pop_back();
			}
			else {
				ss.PB(*it);
			}
		}
		
		int lnode = 0, rnode = 0, lrnode = 1, idle = 0;
		FORIT(it, t) {
			if (*it == 'U') {
				if (!ss.empty()) {
					if (ss.back() == 'L') {
						rnode = (rnode + 1) % MOD;
					}
					else if (ss.back() == 'R') {
						lnode = (lnode + 1) % MOD;
					}
					else assert(false);
					ss.pop_back();
				}
			}
			else if (*it == 'L') {
				int _lnode = lnode;
				int _rnode = rnode;
				int _lrnode = lrnode;
				lnode = 0;
				rnode = (_lrnode + _rnode) % MOD;
				lrnode = (_lrnode + _lnode) % MOD;
				idle = (idle + _lnode) % MOD;
			}
			else if (*it == 'R') {
				int _lnode = lnode;
				int _rnode = rnode;
				int _lrnode = lrnode;
				lnode = (_lrnode + _lnode) % MOD;
				rnode = 0;
				lrnode = (_lrnode + _rnode) % MOD;
				idle = (idle + _rnode) % MOD;
			}
			else assert(false);
		}
		
		printf("Case %d: %d\n", itc, (lnode + rnode + lrnode + idle) % MOD);
	}
	
	return 0;
}
