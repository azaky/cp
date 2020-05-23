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

#define MAXN 100100
int n, m, ans, ntc, nh, p[MAXN], size[MAXN], hsize[MAXN];
vector<int> child[MAXN], hchild[MAXN];

int dfs0(int v) {
	size[v] = 1;
	FORIT(it, child[v]) {
		size[v] += dfs0(*it);
	}
	return size[v];
}

void dfs(int depth, int v) {
	if (hchild[v].empty()) {
		assert(depth != 0);
		ans += depth * hsize[v];
		return;
	}
	assert(SZ(hchild[v]) == 2);
	FORIT(it, hchild[v]) {
		dfs(depth + 1, *it);
	}
}

int main(){
	OPEN("i2");
	
	scanf("%d", &ntc);
	
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		FOR(i, 2, n) {
			scanf("%d", &p[i]);
		}
		
		// RESET EVERYTHING HERE
		FOR(i, 1, n) {
			child[i].clear();
			size[i] = 0;
		}
		ans = 0;
		
		FOR(i, 2, n) {
			child[p[i]].PB(i);
		}
		
		// Calculates size of subtree
		/*
		FORD(i, n, 1) {
			size[i] = 1;
			FORIT(it, child[i]) {
				size[i] += size[*it];
			}
		}
		*/
		dfs0(1);
		
		// Start huffman?
		FOR(v, 1, n) {
			if (child[v].empty()) {
				continue;
			}
			if (SZ(child[v]) == 1) {
				//ans += size[child[v][0]];
				continue;
			}
			
			priority_queue<pair<int,int> > huft;
			m = SZ(child[v]);
			REP(i, m) {
				hsize[i] = size[child[v][i]];
				huft.push(MP(-hsize[i], i));
			}
			REP(i, 2*m+1) {
				hchild[i].clear();
			}
			nh = m;
			
			while (SZ(huft) > 1) {
				pii a = huft.top(); huft.pop();
				pii b = huft.top(); huft.pop();
				hsize[nh] = hsize[a.B] + hsize[b.B];
				hchild[nh].PB(a.B);
				hchild[nh].PB(b.B);
				huft.push(MP(-hsize[nh], nh));
				nh++;
			}
			pii top = huft.top();
			dfs(0, top.B);
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
