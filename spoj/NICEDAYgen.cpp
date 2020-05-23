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
int a[MAXN], b[MAXN], c[MAXN];

int main(){
	srand(time(NULL));
	int ntc = 10;
	printf("%d\n",ntc);
	FOR(itc,1,ntc){
		int n = 100000;
		printf("%d\n",n);
		FOR(i,1,n) a[i] = b[i] = c[i] = i;
		random_shuffle(a+1,a+1+n);
		random_shuffle(b+1,b+1+n);
		random_shuffle(c+1,c+1+n);
		FOR(i,1,n) printf("%d %d %d\n",a[i],b[i],c[i]);
	}
	
	return 0;
}
