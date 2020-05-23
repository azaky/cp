/* DIKRA */
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

int ntc, row, col;
char s[105][105];
int wall[105][105];
int sr, sc, gr, gc;
vector<pair<pair<int,int>, int> > laser;

int rm[] = {0,1,0,-1};
int cm[] = {1,0,-1,0};

int vis[105][105][5];

int isDead(int r, int c, int dir){
	REP(i, SZ(laser)){
		int lr = laser[i].A.A;
		int lc = laser[i].A.B;
		int ld = (laser[i].B + dir)%4;

		int dr = r-lr;
		int dc = c-lc;

		if (dr == 0 && dc == 0) return 1;

		if (dr == 0){
			if (dc/abs(dc) == cm[ld]){
				lc += cm[ld];
				while (wall[r][lc] == 0 && lc != c) lc += cm[ld];

				if (lc == c) return 1;	
			}

			
		}

		if (dc == 0){
			if (dr/abs(dr) == rm[ld]){
				lr += rm[ld];
				while (wall[lr][c] == 0 && lr != r) lr += rm[ld];

				if (lr == r) return 1;
			}
		}

	}
	return 0;
}

int main(){
//	OPEN("maze");
	scanf("%d", &ntc);
	FOR(itc, 1, ntc){
		scanf("%d %d", &row, &col);
		REP(i, row){
			scanf("%s", s[i]);
		}

		RESET(wall, 0);
		laser.clear();
		REP(i, row){
			REP(j, col){
				if (s[i][j] == '#') wall[i][j] = 1;
				else if (s[i][j] == 'S'){
					sr = i; sc = j;
				}
				else if (s[i][j] == 'G'){
					gr = i; gc = j;
				}
				else if (s[i][j] == '>'){
					laser.PB(MP(MP(i,j), 0));
					wall[i][j] = 1;
				}
				else if (s[i][j] == 'v'){
					laser.PB(MP(MP(i,j), 1));
					wall[i][j] = 1;
				}
				else if (s[i][j] == '<'){
					laser.PB(MP(MP(i,j), 2));
					wall[i][j] = 1;
				}
				else if (s[i][j] == '^'){
					laser.PB(MP(MP(i,j), 3));
					wall[i][j] = 1;
				}
			}
		}
	
		RESET(vis, -1);
		queue<pair<pii, int> > q;
		vis[sr][sc][0] = 0;
		REP(i, 4){
			int rr = sr+rm[i];
			int cc = sc+cm[i];

			if (rr < 0 || rr >= row || cc < 0 || cc >= col) continue;

			if (wall[rr][cc]) continue;
			q.push(MP(MP(rr, cc), 1));			
		}

		while (!q.empty()){
			int r = q.front().A.A;
			int c = q.front().A.B;
			int d = q.front().B;
			q.pop();

			if (wall[r][c]) continue;

			if (vis[r][c][d%4] != -1){
				if (vis[r][c][d%4] >= d) continue;
			}

			if (isDead(r,c,(d%4))) continue;
			
			vis[r][c][d%4] = d;

			if (r == gr && c == gc) continue;

			REP(i, 4){
				int rr = r+rm[i];
				int cc = c+cm[i];

				if (rr < 0 || rr >= row || cc < 0 || cc >= col) continue;

				if (wall[rr][cc]) continue;
				if (vis[rr][cc][(d+1)%4] == -1 || vis[rr][cc][(d+1)%4] > d+1){
					q.push(MP(MP(rr, cc), d+1));	
				}
			}
		}

		int ans = 2000000000;
		REP(i, 4){
			if (vis[gr][gc][i] == -1) continue;
			MN(ans, vis[gr][gc][i]);
		}

		printf("Case #%d: ", itc);
		if (ans == 2000000000) printf("impossible\n");
		else printf("%d\n", ans);

	}

	return 0;
}