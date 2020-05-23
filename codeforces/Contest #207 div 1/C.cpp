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

int n, a[1111111], c[10], ans, total;

int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%d",&a[i]);
		total += a[i];
		c[a[i]]++;
	}
	if (total == 1 || total == 2 || total == 5){
		puts("-1");
		return 0;
	}
	ans = 1000000000;
	for(int i = 0; 3*i <= total; ++i){
		if ((total - 3*i) % 4 != 0) continue;
		int j = (total - 3*i) / 4;
		int moves = 0;
		if (i < c[3] && j < c[4]){
			/* impossible kale */
		}
		else if (i < c[3] && j >= c[4]){
			int c1 = c[1];
			int c2 = c[2];
			int c3 = c[3]-i;
			/* mau buat 4*(j-c[4]) */
			int t = j-c[4];
			if (t <= c3) moves = t;
			else if (t <= c3+c2) moves = c3 + 2 * (t-c3);
			else moves = c1 + c2 + c3 - t;
		}
		else if (i >= c[3] && j < c[4]){
			int c1 = c[1];
			int c2 = c[2];
			int c4 = c[4]-j;
			int t = i-c[3];
			if (t <= c2 + c4) moves = t-c4;
			else if (t <= c1 + c2 + c4) moves = c4 + (c1 + c2 + c4 - t);
			else moves = c4;
		}
		else {
			int c1 = c[1];
			int c2 = c[2];
			int t3 = i-c[3];
			int t4 = j-c[4];
			if (t4 > c2) moves = c1 + c2 - t3 - t4;
			else if (t3 + t4 < c2) moves = 2*t4 + t3;
			else moves = c1 + c2 - t3 - t4;
		}
		MN(ans,moves);
	}
	printf("%d\n",ans);
	
	return 0;
}
