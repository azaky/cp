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

int ntc, n, udah[111];
char s[111][111];

int comp(int a, int b){
	int la = strlen(s[a]), lb = strlen(s[b]), ret = 0;
	while (ret < la && ret < lb && s[a][ret] == s[b][ret]) ++ret;
	return ret;
}

int main(){
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%d",&n);
		REP(i,n) scanf("%s",s[i]);
		vector<int> ans;
		ans.PB(0);
		int total = strlen(s[0]);
		REP(i,n) udah[i] = 0;
		udah[0] = 1;
		FOR(i,1,n-1){
			int next = -1;
			REP(j,n) if (!udah[j]){
				if (next == -1) next = j;
				else if (comp(ans.back(),j) > comp(ans.back(),next)) next = j;
			}
			udah[next] = 1;
			total += strlen(s[next]) - comp(ans.back(),next);
			ans.PB(next);
		}
		printf("%d\n",total);
		FORIT(it,ans) printf("%s\n",s[*it]);
	}
	
	return 0;
}
