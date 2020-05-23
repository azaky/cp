/* DELAPAN.3gp */
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

int ntc, n, p[3];

string genAns(int winner) {
	vector<int> pp;
	pp.PB(winner);
	REP(iround, n) {
		vector<int> temppp;
		REP(i, SZ(pp)) {
			temppp.PB(pp[i]);
			temppp.PB((pp[i] + 1) % 3);
		}
		pp = temppp;
	}
	string ans = "";
	REP(i, SZ(pp)) {
		ans += "RPS"[pp[i]];
	}
	for (int size = 1; size < (1 << n); size <<= 1) {
		for (int i = 0; i < (1 << n); i += (size << 1)) {
			if (ans.substr(i, size) > ans.substr(i + size, size)) {
				// printf("swapping [%s] [%s]\n", ans.substr(i, size).c_str(), ans.substr(i + size, size).c_str());
				REP(j, size) {
					swap(ans[i + j], ans[i + size + j]);
				}
			}
		}
	}
	return ans;
}

int main(){
	// n = 12;
	// string a12 = genAns(0);
	// REP(i, SZ(a12)) {
	// 	if (a12[i] == 'R') {
	// 		p[0]++;
	// 	} else if (a12[i] == 'P') {
	// 		p[1]++;
	// 	} else {
	// 		p[2]++;
	// 	}
	// }
	// printf("%d %d %d\n", p[0], p[1], p[2]);
	OPEN("A-large");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d", &n, &p[0], &p[1], &p[2]);
		string ans = "IMPOSSIBLE";
		REP(winner, 3) {
			int ps[3] = {0};
			ps[winner] = 1;
			REP(iround, n) {
				int tempps[3] = {0};
				REP(i, 3) {
					tempps[i] += ps[i];
					tempps[(i + 1) % 3] += ps[i];
				}
				REP(i, 3) {
					ps[i] = tempps[i];
				}
			}
			if (p[0] == ps[0] && p[1] == ps[1] && p[2] == ps[2]) {
				ans = genAns(winner);
			}
		}
		printf("Case #%d: %s\n", itc, ans.c_str());
	}
	
	return 0;
}
