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

#define MAXN 1000100

priority_queue<pii> values;
int top[MAXN], n;
ll t;

int main(){
	cin >> n >> t;
	
	FOR(i, 1, n) {
		values.push(MP(i, 1));
	}
	top[1] = n;
	
	ll ans = (ll) n * (ll) (n+1LL) / 2LL;
	
	for (int k = 1; ; k++) {
		vector<pii> affected;
		ll total = 0;
		int v = 1;
		while (true) {
			pii p = values.top();
			if (p.A > v) {
				total += (ll) (p.A - v);
				v += k+1;
				affected.PB(p);
				values.pop();
			}
			else {
				v -= k+1;
				break;
			}
		}
		if (total > t) {
			top[k+1] = (v-1) / (k+1) + 1;
			for (int i = 1; i <= v; i += k+1) {
				values.push(MP(i, k+1));
			}
			FORIT(it, affected) {
				top[it->B]--;
			}
			ans -= total - t;
		}
		else {
			cout << ans << endl;
			cout << k-1 << endl;
			int temp = 0;
			REP(i, k-1) {
				temp += top[i+1];
				printf("%d", temp);
				if (i == k-2) {
					printf("\n");
				}
				else {
					printf(" ");
				}
			}
			
			break;
		}
	}
	
	return 0;
}
