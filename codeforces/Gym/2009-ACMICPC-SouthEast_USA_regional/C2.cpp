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

#define INF 1000000
#define MAXV 111

int n, k, m[111], shift[111][111], nguard[111], res[111][111];
int MAX_V, v1, v2, maxflow, maxloc, v, pathcap, curnode, nextnode, prevnode[MAXV], flow[MAXV], visit[MAXV];

int main(){
	scanf("%d",&n);
	if (n == 0) return 0;
	REP(i,48) nguard[i] = 0;
	FOR(i,1,n){
		scanf("%d%d",&k,&m[i]);
		m[i] /= 30;
		REP(j,48) shift[i][j] = 0;
		REP(j,k){
			int h1, m1, h2, m2;
			scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
			int st = h1 * 60 + m1;
			st = (st + 29) / 30;
			int fi = h2 * 60 + m2;
			fi = fi / 30;
			if (fi <= st) fi += 48;
			FOR(_i,st,fi-1) shift[i][_i % 48] = 1;
		}
//		REP(j,48) if (shift[i][j]) printf("[%d]",j);
//		puts("\n");
		REP(j,48) if (shift[i][j]) nguard[j]++;
	}
	int _max = *min_element(nguard,nguard+48);
	MAX_V = 51+n;
	v1 = 49; v2 = 50;
	FOR(ans,1,_max){
		//reset values
		FOR(i,0,MAX_V) FOR(j,0,MAX_V) res[i][j] = 0;
		FOR(i,1,n){
			res[49][50+i] = m[i];
			REP(j,48) if (shift[i][j]) res[50+i][j] = 1;
		}
		REP(i,48){
			res[i][50] = ans;
		}
		//MAX FLOW
		int totalflow = 0;
		while (1){
			RESET(prevnode,0);
			RESET(flow,0);
			RESET(visit,0);
			flow[v1] = INF;
			while (1){
				maxflow = 0;
				maxloc = 0;
				FOR(i,1,n){
					if (flow[i] > maxflow && !visit[i]){
						maxflow = flow[i];
						maxloc = i;
					}
				}
				if (maxloc == 0 || maxloc == v2) break;
				visit[maxloc] = true;
				REP(v,MAX_V){
					if (flow[v] < min(maxflow,res[maxloc][v])){
						prevnode[v] = maxloc;
						flow[v] = min(maxflow,res[maxloc][v]);
					}
				}
			}
			if (maxloc == 0) break;
			pathcap = flow[v2];
			totalflow += pathcap;
			curnode = v2;
			while (curnode != v1){
				nextnode = prevnode[curnode];
				res[nextnode][curnode] -= pathcap;
				res[curnode][nextnode] += pathcap;
				curnode = nextnode;
			}
		}
		int mf = totalflow;
		//END OF MAX FLOW
//		printf("ans = %d, mf = %d\n",ans,mf);
		if (mf != ans * 48){
			printf("%d\n",ans-1);
			break;
		}
		else if (ans == _max){
			printf("%d\n",ans);
			break;
		}
	}
	main();
		
	return 0;
}
