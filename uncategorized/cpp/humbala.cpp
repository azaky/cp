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

int n, a[10][10], nstep;
bool found;
char step[1000];

void dfs(int ns){
	if (found) return;
	//cek found
	bool match = true;
	REP(i,n) REP(j,n) if (a[i][j] != i*n+j && a[i][j] != -1) match = false;
	if (match){
		found = true;
		printf("SOLUTION: %s\n",step);
		return;
	}
	//cek step
	if (ns == nstep) return;
	//brute!
	REP(i,n) REP(j,n) if (a[i][j] == -1){
		if (i > 0){
			a[i][j] = a[i-1][j];
			a[i-1][j] = -1;
			step[ns] = 'D';
			dfs(ns+1);
			a[i-1][j] = a[i][j];
			a[i][j] = -1;
		}
		if (j > 0){
			a[i][j] = a[i][j-1];
			a[i][j-1] = -1;
			step[ns] = 'R';
			dfs(ns+1);
			a[i][j-1] = a[i][j];
			a[i][j] = -1;
		}
		if (i < 3){
			a[i][j] = a[i+1][j];
			a[i+1][j] = -1;
			step[ns] = 'U';
			dfs(ns+1);
			a[i+1][j] = a[i][j];
			a[i][j] = -1;
		}
		if (j < 3){
			a[i][j] = a[i][j+1];
			a[i][j+1] = -1;
			step[ns] = 'L';
			dfs(ns+1);
			a[i][j+1] = a[i][j];
			a[i][j] = -1;
		}
		step[ns] = 0;
	}
}


int main(){
	scanf("%d",&n);
	REP(i,n) REP(j,n){
		scanf("%d",&a[i][j]);
		a[i][j]--;
	}
	for (nstep = 0; ; ++nstep){
		found = false;
		dfs(0);
		if (found){
			break;
		}
		printf("%d steps are insufficient!\n",nstep);
	}
	
	return 0;
}
