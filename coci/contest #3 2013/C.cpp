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
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 1111
char num[MAXN][100],s[50][100];
int n,ans,len;

int main(){
	strcpy(num[1],"one");
	strcpy(num[2],"two");
	strcpy(num[3],"three");
	strcpy(num[4],"four");
	strcpy(num[5],"five");
	strcpy(num[6],"six");
	strcpy(num[7],"seven");
	strcpy(num[8],"eight");
	strcpy(num[9],"nine");
	strcpy(num[10],"ten");
	strcpy(num[11],"eleven");
	strcpy(num[12],"twelve");
	strcpy(num[13],"thirteen");
	strcpy(num[14],"fourteen");
	strcpy(num[15],"fifteen");
	strcpy(num[16],"sixteen");
	strcpy(num[17],"seventeen");
	strcpy(num[18],"eighteen");
	strcpy(num[19],"nineteen");
	FOR(i,20,99){
		if (i < 30){
			strcpy(num[i],"twenty");
		}
		else if (i < 40){
			strcpy(num[i],"thirty");
		}
		else if (i < 50){
			strcpy(num[i],"forty");
		}
		else if (i < 60){
			strcpy(num[i],"fifty");
		}
		else if (i < 70){
			strcpy(num[i],"sixty");
		}
		else if (i < 80){
			strcpy(num[i],"seventy");
		}
		else if (i < 90){
			strcpy(num[i],"eighty");
		}
		else if (i < 100){
			strcpy(num[i],"ninety");
		}
		if (i % 10 != 0){
			strcat(num[i],num[i%10]);
		}
	}
	FOR(i,100,999){
		strcpy(num[i],num[i/100]);
		strcat(num[i],"hundred");
		if (i > 200 && i%100 != 0){
			strcat(num[i],num[i%100]);
		}
	}
	scanf("%d",&n);
	len = 0;
	REP(i,n){
		scanf("%s",s[i]);
		if (s[i][0] != '$'){
			len += strlen(s[i]);
		}
	}
	for(ans=1;;++ans){
		if (len+(int)strlen(num[ans])==ans) break;
	}
	REP(i,n){
		if (i) printf(" ");
		if (s[i][0] == '$') printf("%s",num[ans]);
		else printf("%s",s[i]);
	}
	printf("\n");
	
	return 0;
}
