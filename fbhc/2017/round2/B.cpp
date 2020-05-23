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

#define MAXN 1100100
#define MAXX 10000000

struct BIT {
	int *bit;

	BIT() {
		bit = new int[MAXX + 5];
	}

	~BIT() {
		delete[] bit;
	}

	void reset() {
		FOR(i, 0, MAXX) bit[i] = 0;
	}

	int _query(int k) {
		int sum = 0;
		for (int x = k; x > 0; x -= (x & -x)) {
			sum += bit[x];
		}
		return sum;
	}

	int _query(int l, int r) {
		if (l > r) return 0;
		return _query(r) - (l >= 1 ? _query(l - 1) : 0);
	}

	void _update(int k, int v) {
		for (int x = k; x <= MAXX; x += (x & -x)) {
			bit[x] += v;
		}
	}

	void insert(int x) {
		_update(x, +1);
	}

	void remove(int x) {
		_update(x, -1);
	}

	int findLeft(int x) {
		int t = _query(1, x - 1);
		if (t == 0) {
			return 0;
		}

		int l = 1, r = x - 1;
		while (l < r) {
			int m = (l + r) / 2;
			if (_query(1, m) == t) {
				r = m;
			} else {
				l = m + 1;
			}
		}

		return l;
	}

	int findRight(int x) {
		int t = _query(x + 1, MAXX);
		if (t == 0) {
			return 0;
		}

		int l = x + 1, r = MAXX;
		while (l < r) {
			int m = (l + r + 1) / 2;
			if (_query(m, MAXX) == t) {
				l = m;
			} else {
				r = m - 1;
			}
		}

		return l;
	}
} bit;

db intersect(pii p1, pii p2) {
	if (p1.A == 0 || p2.A == 0) {
		return 0;
	}

	if (p2.A <= p1.A) {
		fprintf(stderr, "NGACO OY\n");
		exit(1);
	}

	int k = p1.B + p2.B - (p2.A - p1.A);
	if (k < 0) return 0;

	return (db)k * k / 4;
}


int ntc, n, ax, bx, cx, ay, by, cy, idx[MAXX + 5];
pii p[MAXN];

db remove(int x) {
	int i = idx[x];
	// printf("removing p[%d] = (%d, %d) at %d\n", i, p[i].A, p[i].B, x);
	int il = idx[bit.findLeft(x)];
	int ir = idx[bit.findRight(x)];
	bit.remove(x);
	return (db)p[i].B * p[i].B + intersect(p[il], p[ir]) - intersect(p[il], p[i]) - intersect(p[i], p[ir]);
}

int fr[4] = {0, 25, 5, 75};

int main(){
	scanf("%d", &ntc);

	FOR(itc, 1, ntc) {
		fprintf(stderr, "processing tc %d\n", itc);
		scanf("%d", &n);
		scanf("%d%d%d%d", &p[1].A, &ax, &bx, &cx);
		scanf("%d%d%d%d", &p[1].B, &ay, &by, &cy);

		FOR(i, 2, n) {
			p[i].A = ((ll)ax * p[i - 1].A + bx) % cx + 1;
			p[i].B = ((ll)ay * p[i - 1].B + by) % cy + 1;
		}

		FOR(i, 0, MAXX) {
			idx[i] = 0;
		}

		FOR(i, 1, n) {
			if (idx[p[i].A]) {
				fprintf(stderr, "ERROR PAK, ada x yang dobel\n");
				exit(1);
			}
			idx[p[i].A] = i;
		}

		bit.reset();

		db area = 0, prevArea = 0;
		db ans = 0;
		FOR(i, 1, n) {
			int x = p[i].A;
			bool valid = true;
			while (valid) {
				int l = bit.findLeft(x);
				if (l == 0) break;

				int il = idx[l];
				assert(il != 0);
				assert(l < x);
				if (x - l <= p[il].B - p[i].B) {
					valid = false;
				} else if (x - l <= p[i].B - p[il].B) {
					area -= remove(l);
					// printf("area after removing = %.2lf\n", area);
				} else {
					break;
				}
			}
			while (valid) {
				int r = bit.findRight(x);
				if (r == 0) break;

				int ir = idx[r];
				assert(ir != 0);
				assert(x < r);
				if (r - x <= p[ir].B - p[i].B) {
					valid = false;
				} else if (r - x <= p[i].B - p[ir].B) {
					area -= remove(r);
					// printf("area after removing = %.2lf\n", area);
				} else {
					break;
				}
			}

			if (valid) {
				int l = bit.findLeft(x);
				int r = bit.findRight(x);
				int il = idx[l];
				int ir = idx[r];
				// printf("l = %d, r = %d, il = %d (%d, %d), ir = %d (%d, %d)\n", l, r, il, p[il].A, p[il].B, ir, p[ir].A, p[ir].B);
				area += (db)p[i].B * p[i].B + intersect(p[il], p[ir]) - intersect(p[il], p[i]) - intersect(p[i], p[ir]);
				bit.insert(x);
			} else {
				// puts("no change");
			}

			// printf("area after placing p[%d] = (%d, %d) = %.2lf\n", i, p[i].A, p[i].B, area);
			if (area < prevArea) {
				fprintf(stderr, "ERROR PAK, area < 0. itc = %d, i = %d. area = %.2lf, prevArea = %.2lf\n", itc, i, area, prevArea);
				exit(1);
			}

			ans += area;
			prevArea = area;
		}

		printf("Case #%d: %.2lf\n", itc, ans);

		// vector<pii> s;

		// FOR(i, 1, n) {
		// 	printf("(%d, %d)\n", p[i].A, p[i].B);
		// 	if (!s.empty() && p[i].A - s.back().A <= s.back().B - p[i].B) {
		// 		continue;
		// 	}
		// 	bool valid = true;
		// 	while (!s.empty() && valid) {
		// 		// last in current
		// 		if (p[i].A - s.back().A <= p[i].B - s.back().B) {
		// 			s.pop_back();
		// 			continue;
		// 		}

		// 		// current in last
		// 		if (p[i].A - s.back().A <= s.back().B - p[i].B) {
		// 			valid = false;
		// 		} else {
		// 			break;
		// 		}
		// 	}

		// 	if (valid) {
		// 		s.push_back(p[i]);
		// 	}
		// }

		// pii last = MP(-10000000, 0);
		// ll area = 8;

		// FORIT(it, s) {
		// 	pii cur = *it;

		// 	if (cur.A - last.A < cur.B + last.B) {
		// 		ll k = cur.B + last.B - (cur.A - last.A);
		// 		area -= k * k;
		// 	}

		// 	area += (ll) cur.B * cur.B * 4;

		// 	last = cur;
		// }

		// printf("Case #%d: %lld.%d\n", itc, area / 4, fr[area & 3]);
	}
	
	return 0;
}