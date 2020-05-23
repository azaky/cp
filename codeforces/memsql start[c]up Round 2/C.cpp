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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

int dp[111][5][5];
int r, n;

int grundy(int k, int a, int b){
	if (dp[k][a][b] != -1) return dp[k][a][b];
	set<int> hehe;
	//ambil bulet paling atas/bawah
	if (a){
		hehe.insert(grundy(k-1,a,b));
	}
	if (b){
		hehe.insert(grundy(k-1,a,b));
	}
	//ambil kiri
	FOR(i,1,k){
		int k1, a1, b1, k2, a2, b2;
		if (i == 1){
			if (a == 0 || a == 2){
				k1 = a1 = b1 = 0;
			}
			if (a == 1){
				k1 = 0;
				a1 = 1;
				b1 = 0;
			}
		}
		else {
			k1 = i-2;
			a1 = a;
			b1 = 1;
		}
		if (i == k){
			if (b == 0 || b == 2){
				k2 = a2 = b2 = 0;
			}
			if (b == 1){
				k2 = 0;
				a2 = 0;
				b2 = 1;
			}
		}
		else {
			k2 = k-i-1;
			a2 = 1;
			b2 = b;
		}
		hehe.insert(grundy(k1,a1,b1)^grundy(k2,a2,b2));
	}
	//ambil kanan
	FOR(i,1,k){
		int k1, a1, b1, k2, a2, b2;
		if (i == 1){
			if (a == 0 || a == 1){
				k1 = a1 = b1 = 0;
			}
			if (a == 2){
				k1 = 0;
				a1 = 2;
				b1 = 0;
			}
		}
		else {
			k1 = i-2;
			a1 = a;
			b1 = 2;
		}
		if (i == k){
			if (b == 0 || b == 1){
				k2 = a2 = b2 = 0;
			}
			if (b == 2){
				k2 = 0;
				a2 = 0;
				b2 = 2;
			}
		}
		else {
			k2 = k-i-1;
			a2 = 2;
			b2 = b;
		}
		hehe.insert(grundy(k1,a1,b1)^grundy(k2,a2,b2));
	}
	int ret = 0;
	while (EXIST(ret,hehe)) ++ret;
	return dp[k][a][b] = ret;
}

int main(){
	//calculate grundy
	RESET(dp,-1);
	dp[0][0][0] = dp[0][1][1] = dp[0][2][2] = 0;
	dp[0][1][2] = dp[0][2][1] = 1;
	dp[0][1][0] = dp[0][0][1] = dp[0][2][0] = dp[0][0][2] = 1;
	FOR(i,1,100){
		REP(_a,3) REP(_b,3) grundy(i,_a,_b);
	}
	//huahahaha
	scanf("%d%d",&r,&n);
	if (n == 0){
		if (dp[r][0][0]) puts("WIN"); else puts("LOSE");
		return 0;
	}
	vector<pii> aufar;
	REP(i,n){
		int _p, _h;
		scanf("%d%d",&_p,&_h);
		aufar.PB(MP(_p,_h));
	}
	sort(ALL(aufar));
	int ans = 0;
	//atas
	if (aufar[0].A != 1){
		ans ^= dp[aufar[0].A-2][0][aufar[0].B];
	}
	//bawah
	if (aufar.back().A != r){
		ans ^= dp[r-aufar.back().A-1][aufar.back().B][0];
	}
	FOR(i,1,SZ(aufar)-1){
		int k, a, b;
		k = aufar[i].A - aufar[i-1].A - 3;
		if (k == -1 && aufar[i].B == aufar[i-1].B) ans ^= 1;
		if (k < 0) continue;
		a = aufar[i-1].B;
		b = aufar[i].B;
		ans ^= dp[k][a][b];
	}
	if (ans) puts("WIN"); else puts("LOSE");
	return 0;
}
