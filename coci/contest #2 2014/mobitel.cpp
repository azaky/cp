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

int x[10], key[10];
char s[100];

int main(){
	FOR(i, 1, 9) {
		scanf("%d", &x[i]);
		key[x[i]] = i;
	}
	scanf("%s", s);
	int n = strlen(s);
	int last = -1;
	REP(i, n) {
		int now, t;
		if (s[i] <= 'c') {
			now = 2; t = s[i] - 'a' + 1;
		}
		else if (s[i] <= 'f') {
			now = 3; t = s[i] - 'c';
		}
		else if (s[i] <= 'i') {
			now = 4; t = s[i] - 'f';
		}
		else if (s[i] <= 'l') {
			now = 5; t = s[i] - 'i';
		}
		else if (s[i] <= 'o') {
			now = 6; t = s[i] - 'l';
		}
		else if (s[i] <= 's') {
			now = 7; t = s[i] - 'o';
		}
		else if (s[i] <= 'v') {
			now = 8; t = s[i] - 's';
		}
		else if (s[i] <= 'z') {
			now = 9; t = s[i] - 'v';
		}
		if (now == last) {
			printf("#");
		}
		REP(j, t) printf("%d", key[now]);
		last = now;
	}
	puts("");
	
	return 0;
}
