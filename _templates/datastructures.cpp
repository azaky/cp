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

/** Disjoint Set **/
/* complexity: amortized O(n) */
void initSet(int n, int *p){
	for (int i = 0; i < n; ++i) p[i] = i;
}
int findSet(int x, int *p){
	if (p[x] == x) return x;
	else return p[x] = findSet(p[x], p);
}
void unionSet(int x, int y, int *p){
	/* joins parent of x to parent of y, not the other way around */
	p[findSet(x, p)] = findSet(y, p);
}

/** Longest Increasing Subsequence **/
/* complexity: O(n log n) */
int longestIncreasingSubsequence (const vector<int> &a){
	set<int> s;
	set<int>::iterator it;
	for (int i = 0; i < (int)a.size(); ++i){
		s.insert(a[i]);
		it = s.find(a[i]); it++;
		if (it != s.end()) s.erase(it);
	}
	return (int)s.size();
}


int main(){
	int n, x;
	vector<int> a;
	scanf("%d",&n);
	REP(i,n) scanf("%d",&x), a.PB(x);
	printf("%d\n",longestIncreasingSubsequence(a));
	
	return 0;
}
