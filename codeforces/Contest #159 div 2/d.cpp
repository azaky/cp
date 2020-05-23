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
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

const int MAXN = 100100;

int n, a[MAXN], b[MAXN], mul[MAXN], sign[MAXN], MUL;

int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) mul[i] = 1;
	b[n-1] = a[n-1]; sign[n-1] = 1;
	REPD(i,n-1){
		if (a[i] >= b[i+1]){
			sign[i] = 1; mul[i+1] = -1;
		}
		else{
			sign[i] = -1;
		}
		b[i] = abs(a[i]-b[i+1]);
	}
	MUL = 1;
	REP(i,n){
		MUL *= mul[i];
		if (sign[i] * MUL == 1) printf("+"); else printf("-");
	}
	puts("");
	
	return 0;
}
