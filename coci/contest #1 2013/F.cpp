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

#define MAXN 100100
int n, k, t[MAXN];
char s[MAXN], w[MAXN];

int main(){
	scanf("%d",&n);
	scanf("%s",s);
	s[n++] = '#'; s[n] = 0;
	scanf("%d",&k);
	REP(_i,k){
		scanf("%s",w);
		//create t
		int len = strlen(w);
		int pos = 2, cnd = 0;
		t[0] = -1; t[1] = 0;
		while (pos < len){
			if (w[pos-1] == w[cnd]){
				t[pos++] = ++cnd;
			}
			else if (cnd > 0){
				cnd = t[cnd];
			}
			else {
				t[pos++] = 0;
			}
		}
//		REP(i,len) printf(" %c ",w[i]); printf("\n");
//		REP(i,len) printf("%2d ",t[i]); printf("\n");
		
		ll ans = 0;
		//usual KMP algorithm
		int m = 0, i = 0;
		while (m + i < n){
			if (m == n-1) break;
			//we're comparing w[i] and s[m+i]
			++ans;
			if (w[i] == s[m+i]){
				//character match!
				if (i == len-1){
					//we're done
					break;
				}
				++i;
			}
			else {
				//character unmatch!
				//we're skipping i-t[i] characters
				ans += (ll)(i-t[i]-1);
				m += i-t[i];
				if (t[i] > -1){
					i = t[i];
					ans += (ll)i;
				}
				else {
					i = 0;
				}
			}
		}
		cout << ans << endl;
	}
	
		
	
	return 0;
}
