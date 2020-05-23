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
#define REPD(i,n) for (int i = n-i; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) (s.find(a) != s.end())

/* -------------- end of azaky's template -------------- */

#define MAX 1030
int ntc,n,x,y,num,xl,xr,yl,yr;
int a[MAX][MAX], tree[MAX][MAX];
char task[10];

int query(int x, int y){
	int sum = 0;
	for (; x > 0; x -= (x & -x)) for (int _y = y; _y > 0; _y -= (_y & -_y)) sum += tree[x][_y];
	return sum;
}
void update(int x, int y, int val){
	for (; x <= MAX; x+= (x & -x)) for (int _y = y; _y <= MAX; _y += (_y & -_y)) tree[x][_y] += val;
}

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		//reset everything here
		REP(i,MAX) REP(j,MAX) a[i][j] = tree[i][j] = 0;
		scanf("%d",&n);
		while (true){
			scanf("%s",task);
			if (strcmp(task,"END")==0) break;
			if (strcmp(task,"SET")==0){
				scanf("%d%d%d",&x,&y,&num);
				++x; ++y;
				update(x,y,num-a[x][y]);
				a[x][y] = num;
			}
			if (strcmp(task,"SUM")==0){
				scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
				++xr; ++yr;
				printf("%d\n",query(xl,yl)+query(xr,yr)-query(xl,yr)-query(xr,yl));
			}
		}
		if (itc != ntc-1) puts("");
	}
	
	return 0;
}
