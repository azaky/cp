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
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

const int MAXN = 111111;
int n, k;
LL a1[MAXN], a2[MAXN], a3[MAXN], a4[MAXN], ip[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%I64d.%I64d.%I64d.%I64d",&a1[i],&a2[i],&a3[i],&a4[i]);
	REP(i,n) ip[i] = (a1[i]<<24LL)|(a2[i]<<16LL)|(a3[i]<<8LL)|a4[i];
	for (LL t = 1; t < 32; ++t){
		LL mask = ((1LL<<t)-1)<<(32LL-t);
		map<LL,int> haha;
		int cot = 0;
		REP(i,n) if (!haha[ip[i]&mask]) haha[ip[i]&mask] = ++cot;
		if (cot == k){
			printf("%I64d.%I64d.%I64d.%I64d\n",mask>>24LL,(mask>>16LL)%256LL,(mask>>8LL)%256LL,mask%256LL);
			return 0;
		}
	}
	puts("-1");
	
	return 0;
}
