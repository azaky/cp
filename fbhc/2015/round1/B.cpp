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
	freopen((s + ".txt").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 1100100

struct node {
	node() {
		REP(i, 26) child[i] = -1;
	}
	int child[26];
} root;
vector<node> trie;
int ntc, n;
char s[MAXN];

int main() {
	OPEN("autocomplete");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d", &n);
		trie.clear();
		trie.PB(root);
		int totalans = 0;
		REP(ii, n) {
			scanf("%s", s);
			int len = strlen(s);
			int v = 0;
			int ans = 0;
			REP(i, len) {
				char c = s[i] - 'a';
				// printf("char = %c, child = %d\n", c, trie[v].child[c]);
				if (trie[v].child[c] == -1) {
					if (ans == 0) ans = i+1;
					node newNode;
					trie.PB(newNode);
					trie[v].child[c] = SZ(trie) - 1;
				}
				v = trie[v].child[c];
			}
			if (ans == 0) ans = len;
			totalans += ans;
			// printf("s = %s, ans = %d\n", s, ans);
		}
		printf("Case #%d: %d\n", itc, totalans);
	}

	return 0;
}