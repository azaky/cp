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

vector<int> nekops(vector<int> &a) {
	int n = SZ(a);
	int cur, occ;
	vector<int> ret;
	REP(i, n) {
		if (i == 0) {
			cur = a[i];
			occ = 1;
		}
		else if (a[i] == cur) {
			occ++;
		}
		else {
			ret.PB(occ);
			ret.PB(cur);
			cur = a[i];
			occ = 1;
		}
	}
	ret.PB(occ);
	ret.PB(cur);
	return ret;
}

int k, len[1111], x;

int main(){
	scanf("%d", &k);
	vector<vector<int> > ans;
	vector<int> init;
	while (scanf("%d", &x) == 1) {
		init.PB(x);
	}
	ans.PB(init);
	FOR(i, 1, k) {
		ans.PB(nekops(ans.back()));
	}
	int maxlen = 0;
	FOR(i, 0, k) {
		len[i] = SZ(ans[i]) - 1;
		FORIT(it, ans[i]) {
			int x = *it;
			while (x > 0) {
				len[i]++;
				x /= 10;
			}
		}
		MX(maxlen, len[i]);
	}
	FOR(i, 0, k) {
		int ldot = (maxlen - len[i]) / 2;
		int rdot = ldot;
		if ((maxlen - len[i]) % 2) ldot++;
		REP(j, ldot) printf(".");
		REP(j, SZ(ans[i])-1) printf("%d ", ans[i][j]);
		printf("%d", ans[i].back());
		REP(j, rdot) printf(".");
		printf("\n");
	}
	printf("%d\n", SZ(ans.back()));
	
	return 0;
}
