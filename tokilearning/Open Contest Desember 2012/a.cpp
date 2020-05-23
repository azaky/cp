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

/* -------------- end of azaky's template -------------- */

const int MAX = 100;
int r,c,sr,sc,xr,xc,a[MAX][MAX],selai[MAX][MAX],fix[MAX][MAX],dummy[MAX][MAX];
vector<pair<int,int> > ans, realans;
bool used[MAX][MAX];

int choose(int l, int r){return rand()%(r-l+1) + l;}

int calc(int xr, int xc){
	int ret = 0;
	for (int i = xr; i < xr+sr; ++i) for (int j = xc; j < xc+sc; ++j){
		if (i < 1 || i > r || j < 1 || j > c) continue;
		if (!selai[i-xr][j-xc]) continue;
		if (dummy[i][j] == a[i][j]) /* selai diambil lagi */ { ret -= a[i][j]; dummy[i][j] = 0; }
		else /* selai ditaroh */ { ret += a[i][j]; dummy[i][j] = a[i][j]; }
	}
	return ret;
}
void update(int xr, int xc){
	ans.pb(mp(xr,xc));
	for (int i = xr; i < xr+sr; ++i) for (int j = xc; j < xc+sc; ++j){
		if (i < 1 || i > r || j < 1 || j > c) continue;
		if (!selai[i-xr][j-xc]) continue;
		if (fix[i][j] == a[i][j]) /* selai diambil lagi */ fix[i][j] = 0;
		else /* selai ditaroh */ fix[i][j] = a[i][j];
	}
}

int main(){
	scanf("%d%d",&r,&c);
	for (int i=1; i <= r; ++i) for (int j=1; j <= c; ++j) scanf("%d",&a[i][j]);
	scanf("%d%d",&sr,&sc);
	for (int i=0; i < sr; ++i) for (int j=0; j < sc; ++j) scanf("%d",&selai[i][j]);
	srand(time(NULL));
	int totalnow = 0;
	const int LIMIT = (r+2*sr-2)*(c+2*sc-2);
	
	const int TL = 20000000/(LIMIT*sr*sc);
	
	//fprintf(stderr,"%d\n",TL);
	for (int coba = 0; coba < TL; ++coba)
{	
	memset(dummy,0,sizeof(dummy)); memset(fix,0,sizeof(fix)); memset(used,false,sizeof(used)); ans.clear();
	int current = 0, totalused = 0;
	while (totalused < LIMIT){
		do{
			//xr \in [1-sr+1..r+sr-1]
			xr = choose(2-sr,r+sr-1); xc = choose(2-sc,c+sc-1);
		} while (used[xr+sr][xc+sc]);
		used[xr+sr][xc+sc] = true;
		totalused += 1;
		int temp = calc(xr,xc);
		//	printf("%d\n",temp);
		if (temp > 0){
			current += temp;
			update(xr,xc);
			/*
			debug("===DUMMY===\n");
			for (int i = 1; i <= r; ++i){
				for (int j = 1; j <= c; ++j) debug("%d ",dummy[i][j]);
				debug("\n");
			}
			debug("===========\n");
			*/
		}
		else calc(xr,xc);
	}
	
	if (current > totalnow) {totalnow = current; realans = ans;}
	//fprintf(stderr,"TRY %d : %d\n",coba,current);
}
	for (int i=0; i<min((int)realans.size(),r+c); ++i) printf("%d %d\n",realans[i].first,realans[i].second);
	//fprintf(stderr,"%d\n",current);
	
	return 0;
}
