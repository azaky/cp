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

#define MAXN 2020
int ntc, n, a[MAXN], nt, node[MAXN*32][2], ans;

void insert(int x){
	int cur = 0;
	REPD(i,31){
		int bit = (x & (1 << i)) >> i;
		if (node[cur][bit] == -1){
			nt++;
			node[nt][0] = node[nt][1] = -1;
			node[cur][bit] = nt;
		}
		cur = node[cur][bit];
	}
}
int findmax(int x){
	int cur = 0;
	int ret = 0;
	REPD(i,31){
		int bit = (x & (1 << i)) >> i;
		if (node[cur][1-bit] == -1){
			cur = node[cur][bit];
		}
		else {
			cur = node[cur][1-bit];
			ret ^= (1 << i);
		}
	}
	return ret;
}

int main(){
	scanf("%d",&ntc);
	while (ntc--){
		scanf("%d",&n);
		REP(i,n) scanf("%d",&a[i]);
		//clear the trie
		nt = 0;
		node[0][0] = node[0][1] = -1;
		//insert a0
		insert(a[0]);
		ans = 0;
		FOR(i,1,n-2){
			FOR(j,i+1,n-1) MX(ans,findmax(a[i]^a[j]));
			insert(a[i]);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
