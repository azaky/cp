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

int n, r, y, njuri, udah[111], d[111];
char t[111];
vector<int> ans;

void joget(int k, int prev, int yakin, int total){
	if (k == r){
		ans.PB(total);
		return;
	}
	FOR(i,1,n){
		if (udah[i]) continue;
		udah[i] = 1;
		int add = d[i];
		if (t[prev] == 'P') add *= 2;
		else if (t[prev] == 'L') add /= 2;
		if (yakin) add += y;
		joget(k+1,i,yakin|(t[i] == 'Y'),total+add);
		udah[i] = 0;
	}
}

int main(){
	char subsoal[11]; scanf("%s %d",subsoal,&n);
	scanf("%d%d%d%d",&n,&r,&y,&njuri);
	FOR(i,1,n){
		scanf("%d",&d[i]);
		t[i] = getchar();
		while (t[i] != 'B' && t[i] != 'P' && t[i] != 'L' && t[i] != 'Y') t[i] = getchar();
	}
	
	joget(0,0,0,0);
	sort(ALL(ans));

	REP(i,njuri){
		int h;
		scanf("%d",&h);
		printf("%d\n",(int)(ans.end()-upper_bound(ALL(ans),h)));
	}
	
	return 0;
}
