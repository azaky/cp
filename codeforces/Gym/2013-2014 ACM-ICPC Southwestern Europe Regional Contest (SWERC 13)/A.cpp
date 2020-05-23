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

#define MAXN 505

map<string, int> idxcolor;
string color[MAXN];
int ncolor = 0, prod[MAXN][MAXN], r, n;
int getidx(string &c) {
	if (!EXIST(c, idxcolor)) {
		color[ncolor] = c;
		idxcolor[c] = ncolor;
		ncolor++;
	}
	return idxcolor[c];
}

float dp[MAXN][MAXN][303];
int col[MAXN][MAXN][303], ncol[MAXN][MAXN];

int main(){
	// read color productions
	RESET(prod, -1);
	scanf("%d", &r);
	REP(i, r) {
		string a, b, c;
		cin >> a >> b >> c;
		int ia = getidx(a);
		int ib = getidx(b);
		int ic = getidx(c);
		prod[ia][ib] = prod[ib][ia] = ic;
	}
	
	int ntc;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		//RESET here
		REP(i, n) REP(j, n) REP(k, ncolor) dp[i][j][k] = 0.;
		REP(i, n) REP(j, n) ncol[i][j] = 0;
		//read certainty
		scanf("%d", &n);
		REP(i, n) {
			while (true) {
				string c;
				cin >> c;
				if (c == "END") break;
				cin >> dp[i][i][getidx(c)];
				col[i][i][ncol[i][i]++] = getidx(c);
			}
		}
		FOR(len, 2, n) {
			REP(l, n-len+1) {
				int r = l + len - 1;
				FOR(m, l, r-1) {
					REP(il, ncol[l][m]) REP(ir, ncol[m+1][r]) {
						int c = prod[col[l][m][il]][col[m+1][r][ir]];
						if (c != -1) {
							if (dp[l][r][c] == 0.) {
								col[l][r][ncol[l][r]++] = c;
							}
							dp[l][r][c] += dp[l][m][col[l][m][il]] * dp[m+1][r][col[m+1][r][ir]];
						}
					}
				}
			}
		}
		if (ncol[0][n-1] == 0) {
			puts("GAMEOVER");
		}
		else {
			int best = 0;
			REP(i, ncolor) {
				if (dp[0][n-1][i] > dp[0][n-1][best]) {
					best = i;
				}
			}
			printf("%s\n", color[best].c_str());
		}
	}
	
	return 0;
}
