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

#define FIRST "BitLGM"
#define SECOND "BitAryo"
void ans(const char *s){
	puts(s);
	exit(0);
}
#define MAXN 311

bool dp2[MAXN][MAXN],visit2[MAXN][MAXN],dp3[MAXN][MAXN],visit3[MAXN][MAXN];

int _max(int a, int b){
	if (a < b) return b; return a;
}

bool win2(int a, int b){
	if (a == b && a == 0) return false;
	if (a == b) return true;
	if (visit2[a][b]) return dp2[a][b]; else visit2[a][b] = true;
	FOR(i,1,_max(a,b)){
		if (i <= a){
			if (!win2(a-i,b)) return dp2[a][b] = true;
		}
		if (i <= b){
			if (!win2(a,b-i)) return dp2[a][b] = true;
		}
		if (i <= a && i <= b){
			if (!win2(a-i,b-i)) return dp2[a][b] = true;
		}
	}
	return dp2[a][b] = false;
}
int main(){
	int a[3], n;
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	if (n == 1){
		if (a[0]) ans(FIRST); else ans(SECOND);
	}
	if (n == 2){
		if (win2(a[0],a[1])) ans(FIRST); else ans(SECOND);
	}
	if (n == 3){
		if ((a[0] ^ a[1]) == a[2]) ans(SECOND); else ans(FIRST);
	}
	
	return 0;
}
