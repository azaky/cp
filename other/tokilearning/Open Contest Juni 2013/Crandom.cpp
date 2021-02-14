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

#define MAXN 1222
int n, a[MAXN], ans[MAXN];

int random(int a, int b){return rand()%(b-a+1)+a;}
int ask(void){
	printf("ask"); REP(i,n) printf(" %d",a[i]); printf("\n"); fflush(stdout);
	int ret; scanf("%d",&ret); return ret;
}
void get(int x){
	int l = 1, r = 1000, m, k;
	while (l < r){
//		m = (l+r+1)/2;
		m = random(l,r);
		a[x] = m;
		k = ask();
		if (k == 1) r = m-1;
		else if (k == 0) l = m;
	}
	ans[x] = l;
	a[x] = 1;
}

int main(){
	srand(time(0));
	puts("init");fflush(stdout);
	scanf("%d",&n);
	REP(i,n) a[i] = 1;
	REP(i,n) get(i);
	printf("answer"); REP(i,n) printf(" %d",ans[i]); printf("\n"); fflush(stdout);
	
	return 0;
}
