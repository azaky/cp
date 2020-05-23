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
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<LL,LL> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (LL i = 0; i < n; ++i)
#define REPD(i,n) for (LL i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (LL i = a; i <= b; ++i)
#define FORD(i,a,b) for (LL i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

#define MAXN 211111
LL n, k;
LL a, b, c, r;
LL m[MAXN], last[MAXN];
LL BIT[MAXN];

void update(LL _k, LL val){ for (LL x = _k; x <= k+1; x += x & -x) BIT[x] += val; }
LL query(LL _k){ LL sum = 0; for (LL x = _k; x > 0; x -= x & -x) sum += BIT[x]; return sum; }

int main(){
	LL ntc; cin >> ntc;
	FOR(itc,1,ntc){
		cin >> n >> k;
		cin >> a >> b >> c >> r;
		
		RESET(m,-1);
		m[0] = a;
		FOR(i,1,k-1) m[i] = (b*m[i-1]+c) % r;

		RESET(last,-1);
		REP(i,k) if (0 <= m[i] && m[i] <= k) last[m[i]] = i;
		
		RESET(BIT,0);
		FOR(i,0,k) if (last[i] != -1) update(i+1,+1);
		
		puts("HEHE");
		
		//FOR(j,0,k) printf("%d ",query(j+1)-query(j)); puts("");
		FOR(i,k,2*k){
			//printf("HEHE %I64d\n",i);
			//printf("INSERTING %d-th ELEMENT\n",i);
			LL l = 1, r = k+1;
			while (l < r){
				//cout << l << " " << r << endl;
				LL mid = (l+r)/2;
				LL cot = (LL)query(mid);
				//puts("HEHE");
				//assert(cot <= mid);
				if (cot == mid) l = mid+1;
				else if (cot < mid-1 || cot - query(mid-1) == 1) r = mid-1;
				else {
					//puts("HEHE");
					m[i] = mid-1;
					break;
				}
				//puts("HEHE");
			}
			//puts("HEHE");
			if (m[i] == -1){
				m[i] = l-1;
			}
			//assert(m[i] != -1);
			//printf("m[%d] = %d\n",i,(LL)m[i]);
			last[m[i]] = i;
			update(m[i]+1,+1);
			if (m[i-k] <= k) if (last[m[i-k]] == i-k) update(m[i-k]+1,-1);
			//FOR(j,0,k) printf("%d ",query(j+1)-query(j)); puts("");
		}
		//FOR(i,0,2*k) printf("%d ",(LL)m[i]); printf("\n");
		printf("Case #%d: %d\n",(int)itc,(int)m[(n-1-k)%(k+1)+k]);
	}
	
	return 0;
}
