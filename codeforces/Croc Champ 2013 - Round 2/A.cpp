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

int n, zz, oz, zo, oo, f, s;
char a[2111111], b[2111111];

int main(){
	scanf("%d",&n);
	scanf("%s%s",a,b);
	REP(i,2*n){
		if (a[i] == '0' && b[i] == '0') zz++;
		if (a[i] == '1' && b[i] == '0') oz++;
		if (a[i] == '1' && b[i] == '1') oo++;
		if (a[i] == '0' && b[i] == '1') zo++;
	}
	REP(i,n){
		//first
		if (oo){f++; oo--;}
		else if (oz){f++; oz--;}
		else if (zo){zo--;}
		else if (zz){zz--;};
		//second
		if (oo){s++; oo--;}
		else if (zo){s++; zo--;}
		else if (oz){oz--;}
		else if (zz){zz--;};
	}
	if (f > s) puts("First"); else if (f < s) puts("Second"); else puts("Draw");
	
	return 0;
}
