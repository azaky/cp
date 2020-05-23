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

const int MAXQ = 200002;
const int MAXN = 30000;
const int MAXA = 1000100;
struct Query{
	int tipe, x, y, i;
};
bool comp(const Query &a, const Query &b){
	if (a.y == b.y) return a.tipe < b.tipe; else return a.y < b.y;
}

int n, nq, nt, ans[MAXQ], bit[MAXN+1], pos[MAXA];
Query q[MAXN+MAXQ+1];

void update(int k, int val){for (int x=k; x <= MAXN; x += (x & -x)) bit[x] += val;}
int query(int k){int sum = 0; for (int x=k; x > 0; x -= (x & -x)) sum += bit[x]; return sum;}

int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		q[nt].tipe = 1;
		scanf("%d",&q[nt].x);
		q[nt].y = i;
		nt++;
	}
	scanf("%d",&nq);
	FOR(i,1,nq){
		q[nt].tipe = 2;
		scanf("%d%d",&q[nt].x,&q[nt].y);
		q[nt].i = i;
		nt++;
	}
	sort(q,q+nt,comp);
	REP(i,nt){
		if (q[i].tipe == 1){
			if (pos[q[i].x]) /* remove */ update(pos[q[i].x],-1);
			pos[q[i].x] = q[i].y;
			update(q[i].y,1);
		}
		else ans[q[i].i] = query(q[i].y) - query(q[i].x-1);
	}
	FOR(i,1,nq) printf("%d\n",ans[i]);
	return 0;
}
