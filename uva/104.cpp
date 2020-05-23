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

db a[111][111], ans, best[111];
int n;

int main(){
	while (scanf("%d",&n) == 1){
		FOR(i,1,n) FOR(j,1,n) if (i == j) a[i][j] = 1.; else scanf("%lf",&a[i][j]);
		vector<int> ans;
		FOR(s,1,n){
			/* do bfs from s */
			FOR(i,1,n) best[i] = a[s][i];
			queue<pair<vector<int>,db> > q;
			vector<int> temp;
			temp.PB(s); temp.PB(0);
			FOR(i,1,n){
				if (i == s) continue;
				temp[1] = i;
				q.push(MP(temp,a[s][i]));
			}
			vector<int> _ans;
			while (!q.empty()){
				pair<vector<int>,db> _top = q.front(); q.pop();
				int c = _top.A.back();
//				FORIT(it,_top.A) printf("%d ",*it); printf(": %.3lf, c = %d, s = %d\n",_top.B,c,s);
				if (c == s && _top.B > 1.01){
					_ans = _top.A;
					break;
				}
				if (SZ(_top.A) > n) continue;
				vector<int> _temp = _top.A;
				int _n = SZ(_temp);
				_temp.PB(0);
				FOR(i,1,n){
					if (_top.B * a[c][i] > best[i]){
						best[i] = _top.B * a[c][i];
						_temp[_n] = i;
						q.push(MP(_temp,best[i]));
					}
				}
			}
			if (!_ans.empty()) if (SZ(_ans) < SZ(ans) || ans.empty()) ans = _ans;
		}
		if (!ans.empty()){
			FORIT(it,ans){
				if (it != ans.begin()) printf(" ");
				printf("%d",*it);
			}
			puts("");
		}
		else puts("no arbitrage sequence exists");
	}
	
	return 0;
}
