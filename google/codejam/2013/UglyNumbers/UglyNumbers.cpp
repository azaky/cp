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

const int ugly[4] = {2, 3, 5, 7};

int ntc, n, a[50], v[50][220];
ll dp[50][220], ans;
char s[50];

ll calc (int k, int r, int jos) {
	if (k == 0){
		if (r == 0) return 1;
		else return 0;
	}
	if (v[k][r]) return dp[k][r];
	v[k][r] = 1; dp[k][r] = 0;
	int ten = 1, reza = 0;
	FORD(i,k,1) {
		/* calculates BIGNUM % jos */
		reza += ten * a[i];
		ten *= 10;
		reza %= jos;
		ten %= jos;
		/* calculates DP */
		/* plus */
		dp[k][r] += calc(i-1,(r-reza+jos)%jos,jos);
		/* minus */
		if (i != 1) dp[k][r] += calc(i-1,(r+reza)%jos,jos);
	}
	return dp[k][r];
}

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%s",s);
		n = strlen(s);
		REP(i,n) a[i+1] = s[i]-'0';
		/* dp[pos][rem] */
		ans = 0;
		REP(mask,16){
			if (mask == 0) continue;
			int jos = 1, parity = -1;
			REP(i,4) if (mask & (1 << i)){
				jos *= ugly[i];
				parity *= -1;
			}
			RESET(v, 0);
			dp[0][0] = 1;
			v[0][0] = 1;
			ans += (ll)parity * calc(n,0,jos);
		}
		printf("Case #%d: %I64d\n",itc,ans);
	}
		
	return 0;
}
