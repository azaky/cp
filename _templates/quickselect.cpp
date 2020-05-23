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

typedef int tipe;

/** Select the k-th element of a after sorted **/
/* average complexity: O(N) */
tipe quickSelect(vector<tipe> a, int k) {
	int n = a.size();
	tipe pivot = a[rand() % n];
	int l = 0, r = n-1;
	while (l <= r) {
		while (a[l] < pivot) l++;
		while (a[r] > pivot) r--;
		if (l <= r) {
			swap(a[l], a[r]);
			l++; r--;
		}
	}
	FOR(i, 0, r) {
		assert(a[i] <= pivot);
	}
	FOR(j, l, n-1) {
		assert(a[j] >= pivot);
	}
	if (r < k-1 && k-1 < l) {
		return pivot;
	}
	else if (k-1 <= r) {
		return quickSelect(vector<tipe>(a.begin(), a.begin()+r+1), k);
	}
	else {
		return quickSelect(vector<tipe>(a.begin()+l, a.begin()+n), k-l);
	}
}

int main(){
	srand(time(0));
	vector<int> a;
	REP(i, 1000000) {
		a.PB(rand()*10000 + rand());
	}
	vector<int> s = a;
	sort(ALL(s));
	while (1) {
		int k;
		scanf("%d", &k);
		if (k == 0) break;
		printf("%d-th element is %d\n", k, quickSelect(a, k));
		printf("real %d-th element is %d\n", k, s[k-1]);
	}
	
	return 0;
}
