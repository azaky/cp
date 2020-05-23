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

#define MAXN 1100

int x[MAXN], y[MAXN], n;
map<int, vector<int> > mpx, mpy;
vector<int> adj[MAXN];

bool compx(int i, int j) {
	return x[i] < x[j];
}

bool compy(int i, int j) {
	return y[i] < y[j];
}

int direction(int a, int b) {
	long long area = x[a] * y[b] - x[b] * y[a];
	int c = adj[b][0] == a ? adj[b][1] : adj[b][0];
	while (c != a) {
		area += x[b] * y[c] - x[c] * y[b];
		int temp = c;
		c = adj[c][0] == b ? adj[c][1] : adj[c][0];
		b = temp;
	}
	area += x[b] * y[c] - x[c] * y[b];
	return area > 0 ? +1 : -1;
}

char getdir(int a, int b) {
	if (x[b] > x[a]) {
		return 'E';
	} else if (x[b] < x[a]) {
		return 'W';
	} else if (y[b] > y[a]) {
		return 'N';
	} else if (y[b] < y[a]) {
		return 'S';
	} else {
		exit(1);
	}
}

void print(int a, int b) {
	putchar(getdir(a, b));
	int c = adj[b][0] == a ? adj[b][1] : adj[b][0];
	while (c != a) {
		putchar(getdir(b, c));
		int temp = c;
		c = adj[c][0] == b ? adj[c][1] : adj[c][0];
		b = temp;
	}
	putchar(getdir(b, c));
}

int main(){
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;

		FOR(i, -10000, 10000) {
			mpx[i].clear();
			mpy[i].clear();
		}
		REP(i, n) {
			scanf("%d%d", &x[i], &y[i]);
			mpx[x[i]].push_back(i);
			mpy[y[i]].push_back(i);
			adj[i].clear();
		}
		FORIT(it, mpx) {
			vector<int> v = it->B;
			sort(ALL(v), compy);
			// if (SZ(it->B)) {
			// 	printf("x = %d\n", it->A);
			// 	FORIT(itt, v) {
			// 		printf("%d ", *itt);
			// 	}
			// 	puts("");
			// }
			for (int i = 1; i < SZ(v); i += 2) {
				adj[v[i]].PB(v[i - 1]);
				adj[v[i - 1]].PB(v[i]);
				// printf("connecting (%d, %d) and (%d, %d)\n", x[v[i - 1]], y[v[i - 1]], x[v[i]], y[v[i]]);
			}
		}
		FORIT(it, mpy) {
			vector<int> v = it->B;
			sort(ALL(v), compx);
			// if (SZ(it->B)) {
			// 	printf(" = %d\n", it->A);
			// 	FORIT(itt, v) {
			// 		printf("%d ", *itt);
			// 	}
			// 	puts("");
			// }
			for (int i = 1; i < SZ(v); i += 2) {
				adj[v[i]].PB(v[i - 1]);
				adj[v[i - 1]].PB(v[i]);
				// printf("connecting (%d, %d) and (%d, %d)\n", x[v[i - 1]], y[v[i - 1]], x[v[i]], y[v[i]]);
			}
		}
		REP(i, n) {
			if (SZ(adj[i]) != 2) {
				printf("i = %d, adj = %d\n", i, SZ(adj[i]));
				exit(1);
			}
		}
		if (direction(0, adj[0][0]) < 0) {
			print(0, adj[0][0]);
		} else {
			print(0, adj[0][1]);
		}
		putchar('\n');
	}
	
	return 0;
}