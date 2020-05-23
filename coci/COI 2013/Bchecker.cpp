#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
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
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

const int MAXN = 30;
const int MAXE = 1000;
int r, c, a[MAXN][MAXN];
PII pos[MAXE];
vector<PII> ans;

void turn(int r0, int c0){
	//assert(r0 < r && c0 < c);
	if (r0 == r || c0 == c) {printf("ERROR: %d %d\n",r0,c0); return;}
	ans.pb(mp(r0,c0));
	int temp = a[r0][c0];
	a[r0][c0] = a[r0+1][c0]; pos[a[r0][c0]] = mp(r0,c0);
	a[r0+1][c0] = a[r0+1][c0+1]; pos[a[r0+1][c0]] = mp(r0+1,c0);
	a[r0+1][c0+1] = a[r0][c0+1]; pos[a[r0+1][c0+1]] = mp(r0+1,c0+1);
	a[r0][c0+1] = temp; pos[a[r0][c0+1]] = mp(r0,c0+1);
	//printf("=== MOVE: [%d][%d] ===\n",r0,c0);FOR(i,1,r){FOR(j,1,c) printf("%d ",a[i][j]); printf("\n");}
}

int random(int l, int r){
	return rand()%(r-l+1)+l;
}

int main(int argc, char **argv){
	
	FILE *fin = fopen(argv[1],"r");
	FILE *fout = fopen(argv[2],"r");
	
	fscanf(fin,"%d%d",&r,&c);
	FOR(i,1,r) FOR(j,1,c) fscanf(fin,"%d",&a[i][j]);
	
	int r0, c0;
	while (fscanf(fout,"%d %d",&r0,&c0) != EOF){
		turn(r0,c0);
	}
	
	FOR(i,1,r){FOR(j,1,c) printf("%d ",a[i][j]); printf("\n");}

	bool correct = true;
	FOR(i,1,r) FOR(j,1,c) if (a[i][j] != (i-1)*c+j) correct = false;
	
	if (correct) puts("ACCEPTED"); else puts("WRONG ANSWER");
	
	return 0;
}
