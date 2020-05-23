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

pair<ll,ll> p;
ll m, ans;

int main(){
	scanf("%I64d%I64d%I64d",&p.A,&p.B,&m);
	if (max(p.A,p.B) <= 0){
		if (max(p.A,p.B) >= m) puts("0"); else puts("-1");
		return 0;
	}
	ans = 0;
	if (p.A < p.B) swap(p.A,p.B);
	while (p.A < m){
		if (p.B < 0){
			ll add = (-p.B)/p.A;
			p.B += p.A * add;
			if (p.B < 0){
				p.B += p.A;
				add++;
			}
			ans += add;
		}
		else{
			p.B += p.A;
			ans++;
		}
		if (p.A < p.B) swap(p.A,p.B);
//		printf("[%I64d][%I64d]\n",p.A,p.B);
	}
	printf("%I64d\n",ans);
	return 0;
}
