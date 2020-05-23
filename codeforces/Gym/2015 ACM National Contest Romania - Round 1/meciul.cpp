/* DELAPAN.3gp */
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

/* -------------- end of DELAPAN.3gp's template -------------- */

#define MAXN 100100

int n, m, p[MAXN], enemy[MAXN];

int findSet(int x) {
	if (p[x] == x) {
		return x;
	} else {
		return p[x] = findSet(p[x]);
	}
}

int main(){
	int ntc;

	OPEN("meciul");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d", &n, &m);
		FOR(i, 1, n) {
			p[i] = i;
			enemy[i] = 0;
		}
		FOR(i, 1, m) {
			int a, b;
			scanf("%d%d", &a, &b);
			int fa = findSet(a);
			int fb = findSet(b);
			if (fa == fb) {
				puts("NO");
				continue;
			}
			if (enemy[fa]) {
				p[fb] = findSet(enemy[fa]);
				if (enemy[fb]) {
					p[findSet(enemy[fb])] = fa;
				}
			} else if (enemy[fb]) {
				p[fa] = findSet(enemy[fb]);
				if (enemy[fa]) {
					p[findSet(enemy[fa])] = fb;
				}
			} else {
				enemy[fa] = fb;
				enemy[fb] = fa;
			}
			puts("YES");
		}
	}
	
	return 0;
}
