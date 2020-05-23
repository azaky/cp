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

int x[11], ans[11], c[11], n, rem;
char s[1111111];

int main(){
	x[0] = 1;
	x[1] = 6;
	x[2] = 8;
	x[3] = 9;
	do {
		int num = 1000*x[0] + 100*x[1] + 10*x[2] + x[3];
		ans[num%7] = num;
	} while (next_permutation(x,x+4));
	
	scanf("%s",s);
	n = strlen(s);
	REP(i,n){
		c[s[i]-'0']++;
	}
	c[1]--; c[6]--; c[8]--; c[9]--;
	n -= 4;
	rem = 0;
	FOR(i,1,9){
		REP(j,c[i]){
			rem = 10*rem + i;
			rem %= 7;
			printf("%d",i);
		}
	}
	rem *= 10000;
	rem %= 7;
	rem = 7-rem;
	rem %= 7;
	printf("%d",ans[rem]);
	REP(j,c[0]) printf("0");
	printf("\n");
	
	return 0;
}
