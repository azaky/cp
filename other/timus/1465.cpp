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

int g[11111],n;

const int ikhsan[] = {0,4,8,14,20,24,28,34,38,42};

int main(){
	set<int> s;
	s.insert(0);
	s.insert(12);
	s.insert(16);
	s.insert(20);
	s.insert(30);
	scanf("%d",&n);
	if (n < 42){
		REP(i,10) if (ikhsan[i] == n){
			puts("Black");
			return 0;
		}
		puts("White");
	}
	else if (EXIST((n-42)%34,s)) puts("Black"); else puts("White");
	return 0;
	
	freopen("1465.out","w",stdout);
	g[0] = 0;
	g[1] = 1;
	g[2] = 1;
	for (n = 3; n <= 10001; ++n){
		s.clear();
		s.insert(g[n-2]);
		for (int l = 0, r = n-3; l <= n-3; ++l, --r) s.insert(g[l]^g[r]);
		while (EXIST(g[n],s)) g[n]++;
	}
	int last = 0;
	set<int> lasts;
	REP(i,10001) if (!g[i]){
//		printf("g[%2d] = %d\n",i,g[i]);
		if (!EXIST(i-last,lasts)) lasts.insert(i-last);
		printf("%d\n",i-last);
		last = i;
	}
	FORIT(it,lasts) printf("%d ",*it); puts("");
		
	
	return 0;
}
