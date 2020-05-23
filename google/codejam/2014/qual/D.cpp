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

int war(vector<db> naomi, vector<db> ken) {
	assert(SZ(naomi) == SZ(ken));
	int n = SZ(naomi);
	int score = 0;
	for (int i = 0, j = 0; i < n && j < n; i++, j++) {
		if (naomi[i] > ken.back()) break;
		while (naomi[i] > ken[j]) j++;
		score++;
	}
	return n - score;
}

int deceitfulwar(vector<db> naomi, vector<db> ken) {
	assert(SZ(naomi) == SZ(ken));
	int n = SZ(naomi);
	int score = 0;
	for (int i = 0, j = 0; i < n && j < n; i++, j++) {
		if (naomi[i] > ken.back()) break;
		while (naomi[i] > ken[j]) j++;
		score++;
	}
	return n - score;
}

int main(){
	int ntc;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		int n;
		scanf("%d", &n);
		vector<db> naomi(n), ken(n);
		REP(i, n) scanf("%lf", &naomi[i]);
		REP(i, n) scanf("%lf", &ken[i]);
		sort(ALL(naomi));
		sort(ALL(ken));
		
		int z = war(naomi, ken);
		int y = 0;
		
		for (int i = 0, j = 0; i < n; i++) {
			if (naomi[i] < ken[j]) continue;
			j++;
			y++;
		}
		
		printf("Case #%d: %d %d\n", itc, y, z);
	}
	
	return 0;
}
