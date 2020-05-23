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

#define MAXN 111111
int n, m, k, _a[MAXN], _b[MAXN];
map<int,int> ca, cb, used;
vector<int> v;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	REP(i,n){
		scanf("%d",&_a[i]);
		if (!used[_a[i]]){
			v.PB(_a[i]); used[_a[i]] = 1;
		}
		ca[_a[i]] ++;
	}
	REP(i,m){
		scanf("%d",&_b[i]);
		if (!used[_b[i]]){
			v.PB(_b[i]); used[_b[i]] = 1;
		}
		cb[_b[i]] ++;
	}
	sort(ALL(v));
	int alice = 0;
	REPD(i,SZ(v)){
		int a = ca[v[i]], b = cb[v[i]], d = min(a,b);
		a -= d; b-= d;
		if (a > 0){
			alice += a;
		}
		else if (b > 0){
			if (alice <= 0) alice -= b;
		}
	}
	if (alice > 0) puts("YES"); else puts("NO");
	
	
	return 0;
}
