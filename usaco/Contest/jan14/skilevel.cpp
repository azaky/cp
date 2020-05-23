/*
ID: a_zaky01
PROG: skilevel
LANG: C++
*/

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

int main(){
	//OPEN("skilevel");
	
/*
	scanf("%d%d%d",&n,&m,&t);
	FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
	
	//calculates diff
	nd = 0;
	FOR(i,1,n) FOR(j,1,m) {
		if (i < n) d[nd++] = abs(a[i][j], a[i+1][j]);
		if (j < m) d[nd++] = abs(a[i][j], a[i][j+1]);
	}
	sort(d, d + nd);
	
	FOR(i,1,n) FOR(j,1,m) {
		if (marked[i][j]) continue;
		
		//do binary search
		int l = 0, r = nd-1;
		while (l < r) {
			area = 0;
			
			dfs(
		}
	}
*/
	int n, m, t;
	
	freopen("skilevel.in","w",stdout);
	
	n = 480;
	m = 500;
	t = 1240;
	
	printf("%d %d %d\n",n,m,t);
	
	srand(time(0));
	
	FOR(i,1,n) {
		FOR(j,1,m-1) printf("%d ",rand()%1000000);
		printf("%d\n",rand()%1000000);
	}
	
	FOR(i,1,n) {
		FOR(j,1,m-1) printf("%d ",rand()%2);
		printf("%d\n",rand()%2);
	}
	
	return 0;
}

/* Generated by UsacoTemp v3.0 */
