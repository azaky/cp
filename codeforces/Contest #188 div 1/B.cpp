#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
	#define GetTime()	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define LLD "%I64d"

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

/* -------------- end of azaky's template -------------- */

const int G = 1000;
int peta[2000][2000], temp[2000][2000], top, n, t;

int main(){
	scanf("%d",&n);
	top = 0; peta[G][G] = n;
	while (1){
//		FOR(x,-top,top){FOR(y,-top,top) printf("%d ",peta[G+x][G+y]); puts("");}
		FOR(tot,0,top){
			FOR(x,-tot,tot){
				int y = tot - abs(x);
				if (peta[G+x][G+y] >= 4){
					int add = peta[G+x][G+y]/4;
					peta[G+x][G+y] -= 4*add;
					temp[G+x][G+y-1] += add;
					temp[G+x][G+y+1] += add;
					temp[G+x-1][G+y] += add;
					temp[G+x+1][G+y] += add;
				}
				if (abs(x) == tot) continue;
				y = abs(x)- tot;
				if (peta[G+x][G+y] >= 4){
					int add = peta[G+x][G+y]/4;
					peta[G+x][G+y] -= 4*add;
					temp[G+x][G+y-1] += add;
					temp[G+x][G+y+1] += add;
					temp[G+x-1][G+y] += add;
					temp[G+x+1][G+y] += add;
				}
			}
		}
		bool kosong = true;
		bool nomove = true;
		FOR(tot,0,top+1){
			FOR(x,-tot,tot){
				int y = tot - abs(x);
				if (temp[G+x][G+y] != 0){
					peta[G+x][G+y] += temp[G+x][G+y];
					if (tot == top+1) kosong = false;
					nomove = false;
					temp[G+x][G+y] = 0;
				}
				if (abs(x) == tot) continue;
				y = abs(x) - tot;
				if (temp[G+x][G+y] != 0){
					peta[G+x][G+y] += temp[G+x][G+y];
					if (tot == top+1) kosong = false;
					nomove = false;
					temp[G+x][G+y] = 0;
				}
			}
		}
		
		if (!kosong) top++;
//		FOR(x,-top,top){FOR(y,-top,top) printf("%d ",peta[G+x][G+y]); puts("");}
		if (nomove) break;
	}
//	puts("hoho");
	scanf("%d",&t);
	REP(itc,t){
		int x, y;
		scanf("%d%d",&x,&y);
		if (abs(x)+abs(y) > top) printf("0\n");
		else printf("%d\n",peta[G+x][G+y]);
	}
		
	
	return 0;
}
