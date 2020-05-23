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
char temp[1001000];
pair<string, int> a[MAXN];
int spre[MAXN], ssuf[MAXN], n;

int longestPrefix(string &a, string &b) {
	int pre = 0;
	while (pre < SZ(a) && pre < SZ(b) && a[pre] == b[pre]) pre++;
	return pre;
}

int main(){
	scanf("%d", &n);
	REP(i, n) {
		scanf("%s", temp);
		a[i] = MP(string(temp), i+1);
	}
	sort(a, a+n);
	
	if (n % 2 == 0) {
		int v = 0;
		for (int i = 0; i < n; i += 2) {
			v += longestPrefix(a[i].A, a[i+1].A);
		}
		printf("%d\n", v);
		for (int i = 0; i < n; i += 2) {
			printf("%d %d\n", a[i].B, a[i+1].B);
		}
	}
	else {
		// calculate prefix and suffix sum
		for (int i = 1; i < n; i += 2) {
			if (i == 1) {
				spre[i] = longestPrefix(a[i-1].A, a[i].A);
			}
			else {
				spre[i] = spre[i-2] + longestPrefix(a[i-1].A, a[i].A);
			}
		}
		for (int i = n-2; i > 0; i -= 2) {
			if (i == n-2) {
				ssuf[i] = longestPrefix(a[i+1].A, a[i].A);
			}
			else {
				ssuf[i] = ssuf[i+2] + longestPrefix(a[i+1].A, a[i].A);
			}
		}
		int v = -1;
		int pos = -1;
		for (int i = 0; i < n; i += 2) {
			int up = i == 0 ? 0 : spre[i-1];
			int down = i == n-1 ? 0 : ssuf[i+1];
			if (up + down > v) {
				v = up + down;
				pos = i;
			}
		}
		printf("%d\n", v);
		for (int i = 0; i < n; i += 2) {
			if (i == pos) {
				i--;
			}
			else {
				printf("%d %d\n", a[i].B, a[i+1].B);
			}
		}
	}
	
	return 0;
}
