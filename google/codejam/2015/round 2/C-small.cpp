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

#define MAXN 222
#define MAXL 10100

int ntc, n, lang[MAXL], bothnew[MAXL];
vector<int> a[MAXN];
char buffer[MAXL];

int main() {
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%d\n", &n);
		int c = 0;
		map<string, int> words;
		REP(i, n) {
			a[i].clear();

			gets(buffer);
			char *temp = strtok(buffer, " ");
			while (temp != NULL) {
				string word = temp;
				temp = strtok(NULL, " ");

				if (!EXIST(word, words)) {
					words[word] = c++;
				}
				a[i].PB(words[word]);
			}
		}

		REP(i, c) {
			lang[i] = 0;
			bothnew[i] = 0;
		}
		REP(i, 2) {
			FORIT(it, a[i]) {
				lang[*it] |= (1 << i);
			}
		}
		int both = 0;
		REP(i, c) {
			if (lang[i] == 3) both++;
		}

		// REP(i, n) {
		// 	printf("sentence #%d:", i);
		// 	FORIT(it, a[i]) printf(" %d", *it);
		// 	printf("\n");
		// }
		// fprintf(stderr, "%d\n", both);

		int ans = c;
		REP(s, 1 << n) {
			if ((s & 1) == 0 || (s & 2) != 0) continue;

			int cbothnew = 0;
			REP(i, n) {
				if (i < 2) continue;
				FORIT(it, a[i]) {
					if ((lang[*it] & 3) == 3) continue;

					if (s & (1 << i)) {
						lang[*it] |= 4;
						if (lang[*it] & (2|8)) {
							if (!bothnew[*it]) cbothnew++;
							bothnew[*it] = 1;
						}
					} else {
						lang[*it] |= 8;
						if (lang[*it] & (1|4)) {
							if (!bothnew[*it]) cbothnew++;
							bothnew[*it] = 1;
						}
					}
				}
				// fprintf(stderr, "%d", (s >> i) & 1);
			}
			// fprintf(stderr, ": %d\n", cbothnew);
			REP(i, n) {
				if (i < 2) continue;
				FORIT(it, a[i]){
					lang[*it] &= 3;
					bothnew[*it] = 0;
				}
			}
			MN(ans, both + cbothnew);
		}
		printf("Case #%d: %d\n", itc, ans);
		fprintf(stderr, "Case #%d: %d\n", itc, ans);
	}

	return 0;
}