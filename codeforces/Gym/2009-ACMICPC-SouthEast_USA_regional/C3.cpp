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

int n, k, m[111], shift[111][111], nguard[111], humbala[1500];
int MAX_V, res[111][111], mf, f, s, t, vis[111];
vector<int> p;

int findPath(int u, int t, int f){
	if (u == t) return f;
	vis[u] = 1;
	REP(v,MAX_V){
		if (!vis[v] && res[u][v] > 0){
			int df = findPath(v,t,min(f,res[u][v]));
			if (df){
				res[u][v] -= df;
				res[v][u] += df;
				return df;
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d",&n);
	if (n == 0) return 0;
	FOR(i,1,n){
		scanf("%d%d",&k,&m[i]);
		m[i] /= 30;
		REP(j,48) shift[i][j] = 0;
		REP(j,1440) humbala[j] = 0;
		REP(j,k){
			int h1, m1, h2, m2;
			scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
			int st = h1 * 60 + m1;
			int fi = h2 * 60 + m2;
			if (fi <= st) fi += 1440;
			FOR(_i,st,fi-1) humbala[_i%1440] = 1;
		}
		REP(j,48){
			shift[i][j] = 1;
			for (int _j = 0; _j < 30; ++_j){
				if (!humbala[_j+30*j]) shift[i][j] = 0;
			}
		}
//		REP(j,48) if (shift[i][j]) printf("[%d]",j);
//		puts("\n");
	}
	MAX_V = 51+n;
	s = 49; t = 50;
	int ans, ansl, ansr;
	ansl = 0; ansr = n;
	while (ansl < ansr){
//		printf("[%d %d]\n",ansl,ansr);
		ans = (ansl + ansr + 1) / 2;
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
		for (mf = 0;;){
			REP(i,MAX_V) vis[i] = 0;
			int df = findPath(s,t,INF);
			if (df == 0) break;
			mf += df;
		}
		//END OF MAX FLOW
//		printf("ans = %d, mf = %d\n",ans,mf);
		if (mf != ans * 48){
			ansr = ans - 1;
		}
		else {
			ansl = ans;
		}
	}
//	assert(ansl == ansr);
//	ans = ansr;
	printf("%d\n",ansl);
	main();
		
	return 0;
}
