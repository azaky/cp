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

#define MAXN 111111
char _s[MAXN];
int n, a[MAXN], s[MAXN];

int main(){
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	scanf("%d",&n);
	scanf("%s",_s);
	FOR(i,1,n){
		if (_s[i-1] == '*') a[i] = 1; else a[i] = -1;
	}
	//sum
//	puts("HUMBALA");
	FOR(i,1,n) s[i] = s[i-1] + (a[i] == 1);
	int x = 1, y, t = 0, last = 1, best = 0, ansx, ansy;
	for (y = 1; y <= n; ++y){
		t += a[y];
//		printf("t = %d, y = %d\n",t,y);
		if (a[y] == 1) last = y;
//		printf("[%d-%d]\n",x,last);
		int harusnya = s[last] - s[x-1];
		int tapi = 2 + (last-x+1) - (s[last]-s[x-1]);
		if (harusnya-tapi > best){
			ansx = x;
			ansy = last;
			best = harusnya-tapi;
		}
		if (t <= 0 && a[y] == 1){
			x = y;
			t = 1;
		}
	}
//	printf("[%d..%d]\n",ansx,ansy);
	
	if (best == 0){
		printf("%d\n",s[n]);
		bool heiho = false;
		FOR(i,1,n){
			if (a[i] == 1){
				if (heiho) printf("Ctrl+%d\n",i);
				else {
					printf("%d\n",i);
					heiho = true;
				}
			}
		}
	}
	else {
		printf("%d\n",s[n]-best);
		printf("%d\n",ansx);
		printf("Shift+%d\n",ansy);
		FOR(i,ansx,ansy){
			if (a[i] == -1) printf("Ctrl+%d\n",i);
		}
		FOR(i,1,ansx-1){
			if (a[i] == 1) printf("Ctrl+%d\n",i);
		}
		FOR(i,ansy+1,n){
			if (a[i] == 1) printf("Ctrl+%d\n",i);
		}
	}
	
	return 0;
}
