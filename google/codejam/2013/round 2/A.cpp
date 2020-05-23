#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
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
#define MOD 1000002013LL

unsigned ll price(ll people,ll length){
	return (people * ((length * (length-1) / 2LL) % MOD)) % MOD;
}
#define MAXN 11111
ll n, m, a[MAXN], b[MAXN], p[MAXN], tot[MAXN];
vector < pair<ll,ll> > s;

int main(){
	int ntc; scanf("%d",&ntc);
	FOR(itc,1,ntc){
		cin >> n >> m;
		REP(i,m) cin >> a[i] >> b[i] >> p[i];
		ll actualprice = 0;
		REP(i,m) actualprice = (actualprice + price(p[i],b[i]-a[i])) %MOD;
		ll bestprice = 0;
		map <ll,ll> haha, udah;
		vector <ll> val;
		REP(i,m){
			haha[a[i]] += p[i];
			haha[b[i]] -= p[i];
			if (!EXIST(a[i],udah)){
				udah[a[i]] = 1;
				val.PB(a[i]);
			}
			if (!EXIST(b[i],udah)){
				udah[b[i]] = 1;
				val.PB(b[i]);
			}
		}
		sort(ALL(val));
		int k = SZ(val)-1;
		tot[0] = haha[val[0]];
		FOR(i,1,k) tot[i] = haha[val[i]] + tot[i-1];
		
//		REP(i,k+1) printf("%I64d ",tot[i]); puts("");
		
		assert(tot[k] == 0);
		
		s.clear();
		s.PB(MP(tot[0],val[0]));
		FOR(i,1,k){
			if (tot[i] == s[SZ(s)-1].A) ;
			else if (tot[i] > s[SZ(s)-1].A) s.PB(MP(tot[i],val[i]));
			else
			while (tot[i] < s[SZ(s)-1].A){
				if (SZ(s) == 1){
					bestprice += price(s[SZ(s)-1].A-tot[i],val[i]-s[SZ(s)-1].B);
					bestprice %= MOD;
					s[SZ(s)-1].A = tot[i];
					break;
				}
				if (tot[i] > s[SZ(s)-2].A){
					bestprice += price(s[SZ(s)-1].A-tot[i],val[i]-s[SZ(s)-1].B);
					bestprice %= MOD;
					s[SZ(s)-1].A = tot[i];
					break;
				}
				else if (tot[i] == s[SZ(s)-2].A){
					bestprice += price(s[SZ(s)-1].A-tot[i],val[i]-s[SZ(s)-1].B);
					bestprice %= MOD;
					s.pop_back();
					break;
				}
				else if (tot[i] < s[SZ(s)-2].A){
					bestprice += price(s[SZ(s)-1].A-s[SZ(s)-2].A,val[i]-s[SZ(s)-1].B);
					bestprice %= MOD;
					s.pop_back();
				}
			}
		}
		printf("Case #%d: %I64d\n",itc,(bestprice-actualprice+MOD)%MOD);
	}
		
	return 0;
}
