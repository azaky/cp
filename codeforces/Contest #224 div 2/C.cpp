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

#define MAXN 100100
int n, a[MAXN];
vector<int> ans;

int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	sort(a, a+n);
	if (n == 1) {
		puts("-1");
		return 0;
	}
	else if (n == 2) {
		ans.PB(a[0] + a[0] - a[1]);
		ans.PB(a[1] + a[1] - a[0]);
		if ((a[0] + a[1]) % 2 == 0) ans.PB((a[0] + a[1]) / 2);
	}
	else {
		//first try
		int d = (a[n-1] - a[0]) / n;
		int miss = 0;
		map<int,int> hoho;
		REP(i,n) hoho[a[i]]++;
		
		REP(i,n+1) {
			int x = a[0] + i * d;
			if (!hoho[x]) {
				miss++;
			}
			else {
				hoho[x]--;
			}
		}
		
		if (miss == 1) {
			REP(i,n+1) if (a[i] != a[0] + i*d || i == n) {
				ans.PB(a[0] + i*d);
				break;
			}
		}
		
		else {
			d = (a[n-1] - a[0]) / (n - 1);
			bool bener = true;
			REP(i,n) if (a[i] != a[0] + i*d) {
				bener = false;
				break;
			}
			if (bener) {
				ans.PB(a[0] - d);
				ans.PB(a[n-1] + d);
			}
		}
	}
	
	sort(ALL(ans));
	//int nans = SZ(ans);
	int nans = unique(ALL(ans)) - ans.begin();
	
	printf("%d\n",nans);
	REP(i,nans) printf("%d ",ans[i]);
	printf("\n");
	
	
	return 0;
}
