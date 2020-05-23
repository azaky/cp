#include <vector>
#include <map>
#include <set>
#include <queue>
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
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

//prefefined macros
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

ll power(ll a, ll b, ll c){
	if (b == 0) return 1;
	ll t = power(a, b/2, c);
	t = (t*t)%c;
	if (b%2) t = (t*a)%c;
	return t;
}

ll n, x, r[5555555], m[5555555], ans;
vector<ll> f;

int main(){
	cin >> n >> x;
	
	FOR(i,1,n-1) if (n % i == 0) f.PB(i);
	
	n++;
	
	REP(i,n) r[i] = power(i,n-1,n);
	
	REP(ii,n){
		int i = (x-1-ii)%n;
		if (r[i] != 1) continue;
		m[i] = (x/n)*n + i;
		while (x <= m[i]) m[i] -= n;
//		printf("%I64d->%I64d\n",(ll)i,m[i]);
		REPD(j,SZ(f)) if (power(m[i],f[j],n) == 1){
			m[i] = 0;
			break;
		}
		if (m[i]){
			printf("%I64d\n",m[i]);
			return 0;
		}
	}
	
	puts("-1");
	//ans = 0;
	//REP(i,n) if (m[i]) MX(ans,m[i]);
	//if (ans) cout << ans; else cout << -1;
	//cout << endl;
		
	
	return 0;
}
