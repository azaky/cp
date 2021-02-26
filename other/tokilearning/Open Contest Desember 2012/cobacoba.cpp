#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

int getint(){
	int ret = 0, mul = 1;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-'){
		mul = -1;
		ch = getchar();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getint(int &x){
	x = getint();
}
long long getLL(){
	long long ret = 0, mul = 1LL;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-'){
		mul = -1LL;
		ch = getchar();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getLL(long long &x){
	x = getLL();
}

#define mp make_pair
#define pb push_back
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define REPD(i,a,b) for (int i = a; i >= a; --i)

/* -------------- end of azaky's template -------------- */

const int MAX = 100;
const int INF = 1000000;
int r,c,sr,sc,xr,xc,a[MAX][MAX],selai[MAX][MAX],fix[MAX][MAX],dummy[MAX][MAX];
vector<pair<int,int> > ans;
vector<int> valans;
bool used[MAX][MAX];

int choose(int l, int r){return rand()%(r-l+1) + l;}

int calc(vector<pair<int,int> > ans){
	bool aktif[MAX][MAX];
	memset(aktif,false,sizeof(aktif));
	for (int i=0; i < (int)ans.size(); ++i){
		for (int xr = ans[i].first; xr < ans[i].first+sr; ++xr) for (int xc = ans[i].second; xc < ans[i].second+sc; ++xc){
			if (xr < 1 || xr > r || xc < 1 || xc > c) continue;
			if (selai[xr-ans[i].first][xc-ans[i].second]) aktif[xr][xc] = !aktif[xr][xc];
		}
	}
	int ret = 0;
	for (int i=1; i <= r; ++i) for (int j=1; j <= c; ++j){
		if (aktif[i][j]) ret += a[i][j];
	}
	return ret;
}

bool sama(vector<pair<int,int> > a, vector<pair<int,int> > b){
	for (int i = 0; i < (int)a.size(); ++i){
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main(){
	scanf("%d%d",&r,&c);
	for (int i=1; i <= r; ++i) for (int j=1; j <= c; ++j) scanf("%d",&a[i][j]);
	scanf("%d%d",&sr,&sc);
	for (int i=0; i < sr; ++i) for (int j=0; j < sc; ++j) scanf("%d",&selai[i][j]);
		
	int totalused = 0, VAL = 0;
	while (totalused < r+c){
		//printf("%d\n",totalused);
		pair<int,int>best = mp(INF,INF);
		int val = -INF;
		for (xr = 2-sr; xr <= r; ++xr) for (xc = 2-sc; xc <= c; ++xc){
			//printf("(%d,%d)\n",xr,xc);
			if (used[xr+sr][xc+sc]) continue;
			int add = 0;
			for (int i = xr; i < xr+sr; ++i) for (int j = xc; j < xc+sc; ++j){
				if (i < 1 || i > r || j < 1 || j > c) continue;
				if (!selai[i-xr][j-xc]) continue;
				if (fix[i][j] == a[i][j]) /* selai diambil lagi */ add -= a[i][j];
				else /* selai ditaroh */ add += a[i][j];
			}
			if (add > val){
				val = add; best = mp(xr,xc);
			}
		}
		//printf("boo\n");
		if (best.first == INF) break;
		xr = best.first; xc = best.second;
		ans.pb(mp(xr,xc));
		valans.pb(VAL+val);
		totalused++; VAL+=val;
		used[xr+sr][xc+sc] = true;
		for (int i = xr; i < xr+sr; ++i) for (int j = xc; j < xc+sc; ++j){
			if (i < 1 || i > r || j < 1 || j > c) continue;
			if (!selai[i-xr][j-xc]) continue;
			if (fix[i][j] == a[i][j]) /* selai diambil lagi */ fix[i][j] = 0;
			else /* selai ditaroh */ fix[i][j] = a[i][j];
		}
		//printf("[%d] : (%d,%d)\n",totalused,xr,xc);
	}
	
	vector <pair<int,int> > realans = ans;
	//int OLDVAL = VAL;
	bool found = true;
	
	while (found){
		found = false;
		REP(ii,0,totalused-1){
			int nowr = ans[ii].first, nowc = ans[ii].second;
			int bestadd = 0;
			pair<int,int> best = mp(nowr,nowc);
			REP(xr,2-sr,r)REP(xc,2-sc,c){
				int add = 0;
				//cabut dari (ans[ii].first,ans[ii].second)
				REP(i,nowr,nowr+sr-1) REP(j,nowc,nowc+sc-1){
					if (i < 1 || j < 1 || i > r || j > c) continue;
					if (!selai[i-nowr][j-nowc]) continue;
					if (fix[i][j] == a[i][j]) fix[i][j] = 0, add -= a[i][j];
					else fix[i][j] = a[i][j], add += a[i][j];
				}
				//taroh di (xr,xc)
				REP(i,xr,xr+sr-1) REP(j,xc,xc+sc-1){
					if (i < 1 || j < 1 || i > r || j > c) continue;
					if (!selai[i-xr][j-xc]) continue;
					if (fix[i][j] == a[i][j]) fix[i][j] = 0, add -= a[i][j];
					else fix[i][j] = a[i][j], add += a[i][j];
				}
				if (add > bestadd){
					best = mp(xr,xc);
					bestadd = add;
				}
				//cabut dari (ans[ii].first,ans[ii].second)
				REP(i,nowr,nowr+sr-1) REP(j,nowc,nowc+sc-1){
					if (i < 1 || j < 1 || i > r || j > c) continue;
					if (!selai[i-nowr][j-nowc]) continue;
					if (fix[i][j] == a[i][j]) fix[i][j] = 0, add -= a[i][j];
					else fix[i][j] = a[i][j], add += a[i][j];
				}
				//taroh di (xr,xc)
				REP(i,xr,xr+sr-1) REP(j,xc,xc+sc-1){
					if (i < 1 || j < 1 || i > r || j > c) continue;
					if (!selai[i-xr][j-xc]) continue;
					if (fix[i][j] == a[i][j]) fix[i][j] = 0, add -= a[i][j];
					else fix[i][j] = a[i][j], add += a[i][j];
				}
			}
			if (bestadd > 0){
				found = true;
				ans[ii] = best;
				int xr = best.first, xc = best.second;
				//cabut dari (ans[ii].first,ans[ii].second)
				REP(i,nowr,nowr+sr-1) REP(j,nowc,nowc+sc-1){
					if (i < 1 || j < 1 || i > r || j > c) continue;
					if (!selai[i-nowr][j-nowc]) continue;
					if (fix[i][j] == a[i][j]) fix[i][j] = 0;
					else fix[i][j] = a[i][j];
				}
				//taroh di (xr,xc)
				REP(i,xr,xr+sr-1) REP(j,xc,xc+sc-1){
					if (i < 1 || j < 1 || i > r || j > c) continue;
					if (!selai[i-xr][j-xc]) continue;
					if (fix[i][j] == a[i][j]) fix[i][j] = 0;
					else fix[i][j] = a[i][j];
				}
			}
		}
	}
	
	for (int i = 0; i < totalused; ++i) printf("%d %d\n",ans[i].first,ans[i].second);
	
	return 0;
}