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

#define MAXSUM 100100
#define MAXN 2222

int ntc;
int a[MAXN], pos1[MAXSUM], prev1[MAXSUM], pos2[MAXSUM], prev2[MAXN];

int calculateSum(int n, int a[], int pos[], int prevv[]) {
	int sum = 0;

	REP(i, n) {
		sum += a[i];
	}

	FOR(i, 1, sum) {
		pos[i] = 0;
	}
	pos[0] = 1;

	REP(i, n) {
		for (int j = sum - a[i], now = sum; j >= 0; j--, now--) {
			if (!pos[now] && pos[j]) {
				prevv[now] = i;
				pos[now] = 1;
			}
		}
	}

	return sum;
}

vector<int> extract(int n, int pos[]) {
	vector<int> p;
	FOR(i, 0, n) {
		if (pos[i]) {
			p.PB(i);
		}
	}
	return p;
}

void printVector(const vector<int> &a) {
	REP(i, a.size()) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void solve() {
	int n;

	scanf("%d", &n);
	REP(i, n) {
		scanf("%d", &a[i]);
	}

	int n1 = n / 2;
	int n2 = n - n1;
	int sum1 = calculateSum(n1, a, pos1, prev1);
	int sum2 = calculateSum(n2, a + n1, pos2, prev2);

	// prepare for the binary search
	vector<int> p1 = extract(sum1, pos1);
	vector<int> p2 = extract(sum2, pos2);
	// printVector(p1);
	// printVector(p2);

	// DO IT!
	int sum = sum1 + sum2;
	int halfSum = sum / 2;
	int lo = p2.size() - 1;
	int bestDiff = halfSum + 101010;
	int ans1, ans2;

	REP(i, p1.size()) {
		while (lo >= 0 && p1[i] + p2[lo] > halfSum) {
			lo--;
		}
		int hi = lo + 1;
		if (hi >= p2.size()) {
			hi = p2.size() - 1;
		}

		int sumLo = p1[i] + p2[lo];
		int diffLo = abs(sumLo - halfSum);
		if (diffLo < bestDiff) {
			bestDiff = diffLo;
			ans1 = p1[i];
			ans2 = p2[lo];
		}
		int sumHi = p1[i] + p2[hi];
		int diffHi = abs(sumHi - halfSum);
		if (diffHi < bestDiff) {
			bestDiff = diffHi;
			ans1 = p1[i];
			ans2 = p2[hi];
		}
	}

	// prev1intf("ans1 = %d, ans2 = %d\n", ans1, ans2);

	ll ans = (ll)(ans1 + ans2) * (ll)(sum - ans1 - ans2);
	vector<int> posAns(n, 0);
	while (ans1 > 0) {
		int x = prev1[ans1];
		assert(pos1[ans1]);
		assert(posAns[x] == 0);
		// printf("prev1[%d] = %d\n", ans1, prev1[ans1]);
		posAns[x] = 1;
		ans1 -= a[x];
	}
	while (ans2 > 0) {
		int x = prev2[ans2] + n1;
		assert(pos2[ans2]);
		assert(posAns[x] == 0);
		// printf("prev2[%d] = %d\n", ans2, prev2[ans2]);
		posAns[x] = 1;
		ans2 -= a[x];
	}
	ll sumR = 0, sumD = 0;
	printf("%lld\n", ans);
	REP(i, n) {
		if (posAns[i]) {
			printf("R");
			sumR += a[i];
		} else {
			printf("D");
			sumD += a[i];
		}
	}
	printf("\n");
	assert(sumR * sumD == ans);
}

int main() {
	scanf("%d", &ntc);
	REP(itc, ntc) {
		solve();
	}

	return 0;
}