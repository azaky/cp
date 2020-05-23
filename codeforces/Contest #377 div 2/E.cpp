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

#define MAXN 200100

int n, m, s[MAXN], ansa[MAXN], ans[MAXN], ansu, ansc;
pii p[MAXN];

int main(){
	scanf("%d%d", &n, &m);
	REP(i, n) {
		scanf("%d", &p[i].A);
		p[i].B = i;
	}
	REP(i, m) scanf("%d", &s[i]);

	sort(p, p + n);
	// <<power, -adapter>, idx>
	priority_queue<pair<pii, int> > pq;
	REP(i, m) {
		pq.push(MP(MP(s[i], 0), i));
	}

	RESET(ans, -1);
	RESET(ansa, 0);
	ansu = ansc = 0;
	REPD(i, n) {
		pair<pii, int> top = pq.top();
		while (top.A.A > p[i].A && !pq.empty()) {
			pq.pop();
			if (top.A.A > 1) {
				top.A.A = (top.A.A + 1) / 2;
				top.A.B--;
				pq.push(top);
			}
			if (!pq.empty()) {
				top = pq.top();
			}
		}
		if (top.A.A == p[i].A) {
			assert(!pq.empty());
			pq.pop();
			ans[p[i].B] = top.B;
			ansc++;
			ansu -= top.A.B;
			ansa[top.B] = -top.A.B;
			if (pq.empty()) break;
		}
	}

	printf("%d %d\n", ansc, ansu);
	REP(i, m) {
		printf("%d", ansa[i]);
		if (i < m - 1) putchar(' '); else putchar('\n');
	}
	REP(i, n) {
		printf("%d", ans[i] + 1);
		if (i < n - 1) putchar(' '); else putchar('\n');
	}
	
	return 0;
}