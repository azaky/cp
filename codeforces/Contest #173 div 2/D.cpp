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

bool dp2[MAXN][MAXN],visit2[MAXN][MAXN],dp3[MAXN][MAXN][MAXN],visit3[MAXN][MAXN][MAXN];

bool win2(int a, int b, int m){
	if (a == b && a == 0) return false;
	if (a == b) return true;
	if (visit2[a][b]) return dp2[a][b]; else visit2[a][b] = true;
	FOR(i,1,max(a,b)){
		if (i <= a){
			if (!win2(a-i,b,m)) return dp2[a][b] = true;
		}
		if (i <= b){
			if (!win2(a,b-i,m)) return dp2[a][b] = true;
		}
		if (i <= a && i <= b && m){
			if (!win2(a-i,b-i,m)) return dp2[a][b] = true;
		}
	}
	return dp2[a][b] = false;
}
bool win3(int a, int b, int c){
	if (a > b) return win3(b,a,c);
	if (b > c) return win3(a,c,b);
	if (a == b && b == c && a == 0) return false;
	if (a == b && b == c) return true;
	//if (a == 0) return win2(b,c,0);
	if (visit3[a][b][c]) return dp3[a][b][c]; else visit3[a][b][c] = true;
	FOR(i,1,c){
		if (i <= a){
			if (!win3(a-i,b,c)) return dp3[a][b][c] = true;
		}
		if (i <= b){
			if (!win3(a,b-i,c)) return dp3[a][b][c] = true;
		}
		if (i <= c){
			if (!win3(a,b,c-i)) return dp3[a][b][c] = true;
		}
		if (i <= a && i <= b && i <= c){
			if (!win3(a-i,b-i,c-i)) return dp3[a][b][c] = true;
		}
	}
	return dp3[a][b][c] = false;
}

int main(){
	int a[3], n;
	//scanf("%d",&n);
	//REP(i,n) scanf("%d",&a[i]);
	FOR(i,0,30) FOR(j,i,30) FOR(k,j,30) if (!win3(i,j,k)) printf("%d %d %d\n",i,j,k);
	if (n == 1){
		if (a[0]) ans(FIRST); else ans(SECOND);
	}
	if (n == 2){
		if (win2(a[0],a[1],1)) ans(FIRST); else ans(SECOND);
	}
	if (n == 3){
		if (win3(a[0],a[1],a[2])) ans(FIRST); else ans(SECOND);
	}
	
	return 0;
}
