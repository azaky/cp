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

#define MAXN 105

int ntc, n;
char s[MAXN];
map<char, int> isVowel;

int main() {
	isVowel['a'] = isVowel['i'] = isVowel['u'] = isVowel['e'] = isVowel['o'] = 1;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%s", s);
		n = strlen(s);
		vector<char> vowel, cons;
		for (int i = 0; i < n; ++i) {
			if (isVowel[s[i]]) {
				vowel.PB(s[i]);
			} else {
				cons.PB(s[i]);
			}
		}
		int nVowel = SZ(vowel);
		int nCons = SZ(cons);
		if (nVowel <= nCons && nCons <= 2 * nVowel) {
			// bisa coy
			int l = nCons - nVowel;
			int k = nVowel - l;
			string ans = "";
			for (int i = 0; i < k; ++i) {
				ans.PB(cons.back());
				cons.pop_back();
				ans.PB(vowel.back());
				vowel.pop_back();
			}
			for (int i = 0; i < l; ++i) {
				ans.PB(cons.back());
				cons.pop_back();
				ans.PB(vowel.back());
				vowel.pop_back();
				ans.PB(cons.back());
				cons.pop_back();
			}
			printf("Case #%d: %s\n", itc, ans.c_str());
		} else {
			printf("Case #%d: IMPOSSIBLE\n", itc);
		}
	}

	return 0;
}
