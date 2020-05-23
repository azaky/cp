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

#define MAXN 50500
#define MOD 1000000007
char a[MAXN], b[MAXN];
int n, na, nb;
ll ten, t[MAXN], tenth, sa[MAXN], sb[MAXN], cda, cdb, cd[MAXN][11], ans, add;

int main(){
	scanf("%s %s",a,b);
	na = strlen(a);
	nb = strlen(b);
	n  = max(na, nb);
	/* performs a-- */
	a[na-1]--;
	REPD(i,na){
		if (a[i] < '0'){
			a[i] = '9';
			a[i-1]--;
		}
	}
	//printf("a-1 = %s\n",a);
	t[0] = 1;
	ten = 1;
	FOR(i,1,n){
		if (i > na){
			sa[i] = sa[i-1];
		}
		else {
			sa[i] = (sa[i-1] + (ll)(a[na-i]-48)*ten) % MOD;
		}
		if (i > nb){
			sb[i] = sb[i-1];
		}
		else {
			sb[i] = (sb[i-1] + (ll)(b[nb-i]-48)*ten) % MOD;
		}
		ten *= 10LL;
		ten %= MOD;
		t[i] = ten;
	}
	sa[n+1] = sa[n];
	sb[n+1] = sb[n];
	tenth = 700000005;
	FOR(i,1,n){
		REP(d,10){
			cda = (sa[n]-sa[i])*tenth;
			cda %= MOD;
			if (i <= na){
				if (a[na-i]-48 == d){
					cda += sa[i-1]+1;
				}
				else if (a[na-i]-48 > d){
					cda += t[i-1];
				}
				cda %= MOD;
			}
			else if (d == 0){
				cda += sa[i-1]+1;
				cda %= MOD;
			}
			cdb = (sb[n]-sb[i])*tenth;
			if (i <= nb){
				if (b[nb-i]-48 == d){
					cdb += sb[i-1]+1;
				}
				else if (b[nb-i]-48 > d){
					cdb += t[i-1];
				}
				cdb %= MOD;
			}
			else if (d == 0){
				cdb += sb[i-1]+1;
				cdb %= MOD;
			}
			cd[i][d] = (cdb - cda + MOD) % MOD;
			//printf("cda = %10I64d, cbd = %10I64d, cd[%d][%d] = %10I64d\n",cda,cdb,i,d,cd[i][d]);
		}
	}
	ans = 0;
	FOR(i,1,n){
		REP(d1,10) REP(d2,10){
			add = d1 - d2;
			if (add < 0) add = -add;
			add *= cd[i][d1];
			add %= MOD;
			add *= cd[i][d2];
			add %= MOD;
			ans += add;
			ans %= MOD;
		}
	}
	cout << ans << endl;
	
	return 0;
}
