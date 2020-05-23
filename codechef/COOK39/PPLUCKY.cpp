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

#define MAXN 111111
char _s[MAXN];
int ntc, n, a[MAXN], v[MAXN], k[MAXN], p[MAXN], bit[MAXN];

int query(int x){
	int sum = 0;
	for (; x > 0; x -= x & -x) sum += bit[x];
	return sum;
}
void update(int x, int v){
	for (; x <= n; x += x & -x) bit[x] += v;
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d",&n);
		scanf("%s",_s);
		FOR(i,1,n) a[i] = _s[i-1] - '0';
		FOR(i,1,n) k[i] = 0;
		// stacking!
		vector<int> s;
		FOR(i,1,n){
			if (a[i] == 4){
				s.PB(i);
				v[SZ(s)-1] = 1;
			}
			else {
				if (s.empty()) continue;
				k[s[SZ(s)-1]] = v[SZ(s)-1];
				p[s[SZ(s)-1]] = i;
				MX(v[SZ(s)-2],v[SZ(s)-1]+1);
				s.pop_back();
			}
		}
		//calculate
		vector<pii> q;
		FOR(i,1,n) if (k[i]) q.PB(MP(k[i],-i));
		sort(ALL(q));
		FOR(i,1,n) bit[i] = 0;
		FOR(i,1,n) update(i,1);
		ll ans = 0;
		FORIT(it,q){
			ans += (ll) query(-it->B);
//			printf("pos = %d, value = %d\n",-it->B,query(-it->B));
			update(-it->B,-1); update(p[-it->B],-1);
		}
		cout << ans << endl;
	}
	
	return 0;
}
