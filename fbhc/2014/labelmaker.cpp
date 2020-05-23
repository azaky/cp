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
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 55
int ntc, ans[MAXN], len;
ll x, n, p[MAXN], total;
char s[MAXN];

int main(){
	//OPEN("labelmaker");
	
	scanf("%d",&ntc);
	FOR(itc,1,ntc){
		scanf("%s%I64d",s,&x);
		n = (ll)strlen(s);
		sort(s,s+(int)n);
		/* finding length */
		p[0] = 1; len = 0;
		total = 0;
		while (x > 0){
			len++;
			p[len] = p[len-1] * n;
			x -= p[len];
		}
		x += p[len];
		x--;
		/* find the answer */
		REPD(i,len){
			ans[i] = x % n;
			x /= n;
		}
		printf("Case #%d: ",itc);
		REP(i,len) printf("%c",s[ans[i]]);
		printf("\n");
	}
	
	return 0;
}
