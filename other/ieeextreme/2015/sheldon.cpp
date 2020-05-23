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

#define MAXN 111

int ntc;
ll n;
char alice[100], bob[100];
int visited[MAXN], game[MAXN];

int win[5][5] = {
	{0, -1, 1, 1, -1},
	{1, 0, -1, -1, 1},
	{-1, 1, 0, 1, -1},
	{-1, 1, -1, 0, 1},
	{1, -1, 1, -1, 0}
};

int main() {
	map<string, int> idx;
	idx["Rock"] = 0;
	idx["Paper"] = 1;
	idx["Scissors"] = 2;
	idx["Lizard"] = 3;
	idx["Spock"] = 4;

	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%s%s%lld", alice, bob, &n);

		int a = idx[alice];
		int b = idx[bob];
		RESET(visited, -1);
		int k = 0;
		int now = 5 * a + b;
		while (visited[now] == -1) {
			// printf("game[%d] = [%d..%d]\n", k, a, b);
			game[k] = now;
			visited[now] = k++;
			int aa, bb;
			if (win[a][b] > 0) {
				aa = a;
			} else if (win[a][b] == 0) {
				aa = -1;
				for (int i = 0; i < 5; ++i) {
					if (win[i][a] > 0) {
						if (aa == -1 || win[i][aa] > 0) {
							aa = i;
						}
					}
				}
			} else {
				aa = -1;
				for (int i = 0; i < 5; ++i) {
					if (win[i][b] > 0) {
						if (aa == -1 || win[i][aa] > 0) {
							aa = i;
						}
					}
				}
			}
			if (b == 4) {
				if (win[b][a] > 0) {
					bb = 0;
				} else if (win[b][a] == 0) {
					bb = 3;
				} else {
					bb = 1;
				}
			} else {
				bb = 4;
			}
			now = aa * 5 + bb;
			a = aa;
			b = bb;
		}
		map<int, ll> outcome;
		if (n < visited[now]) {
			for (int i = 0; i < (int)n; ++i) {
				int aa = game[i] / 5;
				int bb = game[i] % 5;
				outcome[win[aa][bb]]++;
			}
		} else {
			ll cycle = k - visited[now];
			ll total = n - (ll)visited[now];
			ll rest = total % cycle;
			ll ncycle = total / cycle;

			// printf("begincycle = %d, cycle = %lld, total = %lld, rest = %lld, ncycle = %lld\n", visited[now], cycle, total, rest, ncycle);

			map<int, ll> mprev, mcycle, mrest;
			for (int i = 0; i < visited[now]; ++i) {
				int aa = game[i] / 5;
				int bb = game[i] % 5;
				mprev[win[aa][bb]]++;
			}
			for (int i = 0; i < (int)cycle; ++i) {
				int aa = game[i + visited[now]] / 5;
				int bb = game[i + visited[now]] % 5;
				mcycle[win[aa][bb]]++;
			}
			for (int i = 0; i < (int)rest; ++i) {
				int aa = game[i + visited[now]] / 5;
				int bb = game[i + visited[now]] % 5;
				mrest[win[aa][bb]]++;
			}
			for (int i = -1; i <= 1; ++i) {
				outcome[i] += mprev[i] + mcycle[i] * ncycle + mrest[i];
			}
		}
		if (outcome[-1] == outcome[1]) {
			printf("Alice and Bob tie, each winning %lld game(s) and tying %lld game(s)\n", outcome[1], outcome[0]);
		} else if (outcome[1] > outcome[-1]) {
			printf("Alice wins, by winning %lld game(s) and tying %lld game(s)\n", outcome[1], outcome[0]);
		} else {
			printf("Bob wins, by winning %lld game(s) and tying %lld game(s)\n", outcome[-1], outcome[0]);
		}
	}

	return 0;
}