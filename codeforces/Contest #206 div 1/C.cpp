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

#define MAXN 300300
int n, k, a[MAXN];

int main(){
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	n = unique(a,a+n) - a;
	if (k >= a[0]){
		printf("%d\n",a[0]);
		return 0;
	}
	//list possible answers
	vector<int> pos;
	map<int,int> udah;
	FOR(d,0,k){
		int x = a[0]-d;
		for (int i = 1; i*i <= x; ++i){
			if (x % i != 0) continue;
			if (i > k){
				if (!udah[i]){
					udah[i] = 1;
					pos.PB(i);
				}
			}
			if (x/i > k){
				if (!udah[x/i]){
					udah[x/i] = 1;
					pos.PB(x/i);
				}
			}
		}
	}
	sort(ALL(pos));
	reverse(ALL(pos));
	REP(x,SZ(pos)){
		bool bener = true;
		REP(i,n) if (a[i] % pos[x] > k){
			bener = false;
			break;
		}
		if (bener){
			printf("%d\n",pos[x]);
			break;
		}
	}
	
	
	return 0;
}
