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
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 111
int ntc, itc, n, k, a[MAXN], add, best, x[MAXN];

void dfs(int p, int total){
	if (total >= best) return;
	if (p == n){
		best = total;
		return;
	}
	for(x[p]=p==0?a[p]:max(x[p-1],a[p]);;x[p]++){
		if (total + x[p]-a[p] > best) break;
		bool iya = true;
		REP(i,p) if (x[i]+x[p] == 0){
			iya = false;
			break;
		} else if (__gcd(x[i],x[p]) != 1){
			iya = false;
			break;
		}
		/* curang? */
		if ((double)clock()/CLOCKS_PER_SEC > 10.*(db)itc) break;
		if (iya) dfs(p+1,total + x[p]-a[p]);
	}
}

int main(){
	//OPEN("preventing_alzheimers");
	
	scanf("%d",&ntc);
	for(itc=1;itc<=ntc;++itc){
		scanf("%d%d",&n,&k);
		REP(i,n) scanf("%d",&a[i]);
		add = 0;
		REP(i,n){
			if (a[i] % k == 0){
				a[i] /= k;
			}
			else {
				add += k - (a[i]%k);
				a[i] /= k;
				a[i] ++;
			}
		}
		REP(i,n) x[i] = a[i];
		best = 0x7FFFFFFF;
		dfs(0,0);
		printf("Case #%d: %d\n",itc,add+best*k);
		fprintf(stderr,"Case #%d done!\n",itc);
	}
	
	return 0;
}
