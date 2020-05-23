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

#define MAXN 111
int n, a[MAXN][MAXN], v[MAXN][MAXN], area;
string s;

void fill(int c, int x, int y){
	if (x == 0 || y == 0 || x > n || y > n) return;
	if (v[x][y] || a[x][y] != c) return;
	v[x][y] = 1;
	area ++;
	fill(c,x-1,y);
	fill(c,x+1,y);
	fill(c,x,y-1);
	fill(c,x,y+1);
}

int main(){
	getline(cin,s);
	{
		stringstream line(s);
		line >> n;
	}
	if (!n) return 0;
	RESET(a,0);
	FOR(i,1,n-1){
		getline(cin,s);
		stringstream line(s);
		int x, y;
		while (line >> x >> y){
			a[x][y] = i;
//			printf("%d %d\n",x,y);
		}
	}
//	printf("BOO\n");
	bool good = true;
	RESET(v,0);
	FOR(i,1,n) FOR(j,1,n){
		if (v[i][j]) continue;
		area = 0;
		fill(a[i][j],i,j);
		if (area != n) good = false;
	}
	if (good) puts("good"); else puts("wrong");
	
	main();
}
