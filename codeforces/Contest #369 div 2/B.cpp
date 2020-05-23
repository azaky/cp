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

int n;
ll a[555][555];

bool check(ll sum) {
	FOR(i, 1, n) {
		ll s = 0;
		FOR(j, 1, n) {
			s += a[i][j];
		}
		if (s != sum) {
			return false;
		}
	}
	FOR(j, 1, n) {
		ll s = 0;
		FOR(i, 1, n) {
			s += a[i][j];
		}
		if (s != sum) {
			return false;
		}
	}
	ll s = 0;
	FOR(i, 1, n) {
		s += a[i][i];
	}
	if (s != sum) {
		return false;
	}
	s = 0;
	FOR(i, 1, n) {
		s += a[i][n + 1 - i];
	}
	if (s != sum) {
		return false;
	}
	return true;
}

int main(){
	scanf("%d", &n);
	pii pos;
	FOR(i, 1, n) FOR(j, 1, n) {
		scanf("%I64d", &a[i][j]);
		if (a[i][j] == 0) {
			pos = MP(i, j);
		}
	}

	if (n == 1) {
		puts("1");
		return 0;
	}

	ll sum = 0;
	FOR(i, 1, n) {
		if (i != pos.A) {
			FOR(j, 1, n) {
				sum += a[i][j];
			}
			break;
		}
	}
	ll summissing = 0;
	FOR(j, 1, n) {
		summissing += a[pos.A][j];
	}
	a[pos.A][pos.B] = sum - summissing;
	if (a[pos.A][pos.B] < 1 || a[pos.A][pos.B] > 1000000000000000000LL) {
		puts("-1");
		return 0;
	}

	if (check(sum)) {
		cout << a[pos.A][pos.B] << endl;
	} else {
		puts("-1");
	}
	
	return 0;
}
