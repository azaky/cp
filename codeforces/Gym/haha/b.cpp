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

#define MAXN 1000
#define MAXM 1000

int n,m, ans;
char s[MAXM+5], a[MAXN+5][MAXM+5];
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d", &n, &m);
	RESET(a,'-');
	for (int i = 1; i <= n; i++) {
		scanf("%s", s);
		for (int j = 1; j <= m; j++) a[i][j] = s[j-1];
	}
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '+') {
				int k = 0;
				for (int l = 0; l < 4; l++) {
					if (a[i+dr[l]][j+dc[l]] == '-') ++k;
				}
				if (k) ++ans;
			}
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}
