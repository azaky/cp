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
ll a, b, w, x, c, bb[MAXN], pos[MAXN], cycle, start, tcycle, tstart;

bool bisa (ll t) {
	ll ct = c - t;
	ll at = a;
	if (t < start) {
		FOR(i,1,t) if (bb[i] < x) at --;
	}
	else {
		REP(i,(t - start + 1) % cycle) {
			if (bb[i + start] < x) at --;
		}
		at -= tstart;
		at -= (t - start + 1) / cycle * tcycle;
	}
	
	//printf("at t = %I64d, a = %I64d, c = %I64d\n",t,at,ct);
	return ct <= at;
}

int main(){
	cin >> a >> b >> w >> x >> c;
	
	// calc cycle
	RESET(pos,-1);
	
	bb[1] = b;
	pos[b] = 1;
	int k = 1;
	while (true) {
		k++;
		bb[k] = bb[k-1] < x ? bb[k-1] + (w-x) : bb[k-1]-x;
		if (pos[bb[k]] != -1) {
			cycle = k - pos[bb[k]];
			start = pos[bb[k]];
			break;
		}
		else {
			pos[bb[k]] = k;
		}
	}
	//printf("k = %I64d\n",(ll)k);
	k--;
	
	FOR(i,1,k) {
		if (i < start) {
			if (bb[i] < x) tstart++;
		}
		else {
			if (bb[i] < x) tcycle++;
		}
	}
	
	//printf("tstart = %I64d, tcycle = %I64d\n",tstart,tcycle);
	
	ll l = 0, r = 1000000000000000000LL, m;
	while (l < r) {
		m = (l+r) / 2LL;
		if (bisa(m)) {
			r = m;
		}
		else {
			l = m+1;
		}
	}
	
	cout << l << endl;
	
	return 0;
}
