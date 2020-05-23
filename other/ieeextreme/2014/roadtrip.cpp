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
#define INF 1100100
int ntc, n, f, len, t, rmq[MAXN<<2];
pii a[MAXN];

void build(int v, int l, int r) {
	//printf("build v = %d, l = %d, r = %d\n", v, l, r);
	if (l == r) {
		rmq[v] = l;
	}
	else {
		int m = (l+r)>>1;
		int vl = v<<1;
		int vr = vl|1;
		build(vl, l, m);
		build(vr, m+1, r);
		if (a[rmq[vl]].B < a[rmq[vr]].B) {
			rmq[v] = rmq[vl];
		}
		else {
			rmq[v] = rmq[vr];
		}
	}
}
int query(int v, int l, int r, int x, int y) {
	if (y < l || r < x) {
		return -1;
	}
	if (x <= l && r <= y) {
		return rmq[v];
	}
	else {
		int m = (l+r)>>1;
		int vl = v<<1;
		int vr = vl|1;
		int ql = query(vl, l, m, x, y);
		int qr = query(vr, m+1, r, x, y);
		if (ql == -1 || a[ql].B > a[qr].B) {
			return qr;
		}
		else {
			return ql;
		}
	}
}

int main(){
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d%d%d%d", &n, &f, &t, &len);
		FOR(i, 1, n) {
			scanf("%d%d", &a[i].A, &a[i].B);
		}
		if (len <= t) {
			puts("0");
			continue;
		}
		if (n == 0) {
			if (len <= t) {
				puts("0");
			}
			else {
				puts("-1");
			}
			continue;
		}
		sort(a+1, a+n+1);
		// build segment tree here
		build(1, 1, n);
		int last = 0;
		ll cost = 0;
		a[0].B = INF;
		FOR(i, 1, n) {
			if (a[i].A > t) break;
			if (a[i].B < a[last].B) {
				last = i;
			}
		}
		if (last == 0) {
			puts("-1");
			continue;
		}
		t -= a[last].A;
		while (true) {
			//printf("now we are at [%d], total cost = [%I64d], fuel = [%d]\n", last, cost, t);
			// get stations with distance <= f from lastpos
			int l = last+1, r = n;
			while (l < r) {
				int m = (l + r + 1) >> 1;
				if (a[m].A <= f) {
					l = m;
				}
				else {
					r = m - 1;
				}
			}
			l = last+1;
			// from l to r
			if (l > r) {
				// check if we can reach len
				if (len - a[last].A <= f) {
					int dis = len - a[last].A;
					dis -= t;
					if (dis < 0) dis = 0;
					cost += (ll)dis * (ll)a[last].B;
					cout << cost << endl;
				}
				else {
					puts("-1");
				}
				break;
			}
			else {
				int tmp = query(1, 1, n, l, r);
				//printf("query(%d, %d) = %d\n", l, r, tmp);
				// kalau min(l..r) kurang dari last:
				// menuju ke stop terdekat dengan cost <= last
				if (a[tmp].B < a[last].B) {
					tmp = l;
					while (a[tmp].B > a[last].B) {
						tmp++;
					}
					int dis = a[tmp].A - a[last].A;
					if (t < dis) {
						cost += (ll)(dis - t) * (ll)a[last].B;
						t = 0;
					}
					else {
						t -= dis;
					}
					last = tmp;
				}
				// kalau min(l..r) >= last:
				// kalau len bisa dicapai dari sini:
				// langsung aja ke sana
				else if (len - a[last].A <= f) {
					int dis = len - a[last].A;
					if (t < dis) {
						cost += (ll)(dis - t) * (ll)a[last].B;
					}
					cout << cost << endl;
					break;
				}
				// else: menuju ke min(l..r), fullin gas
				else {
					cost += (ll)(f - t) * (ll)a[last].B;
					t = f - (a[tmp].A - a[last].A);
					last = tmp;
				}
			}
		}
	}
	
	return 0;
}
