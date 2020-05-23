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

#define MAXN 2002
int ntc, n, d, f[MAXN], p[MAXN], v[MAXN];

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d%d",&n,&d);
		FOR(i,1,n) scanf("%d",&f[i]);
		FOR(i,1,n) p[i] = 2100000000;
		FOR(i,1,n) v[i] = 0;
		p[1] = 0;
		priority_queue<pii> pq;
		FOR(i,1,n) pq.push(MP(-p[i],i));
		while (!pq.empty()){
			int k = pq.top().B; pq.pop();
			if (v[k]) continue; v[k] = 1;
			FOR(i,k-d,k+d){
				if (i < 1 || i > n) continue;
				if (p[k] + f[k]*f[i] < p[i]){
					p[i] = p[k] + f[k]*f[i];
					pq.push(MP(-p[i],i));
				}
			}
		}
		printf("%d\n",p[n]);
	}
	
	return 0;
}
