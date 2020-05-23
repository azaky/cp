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

int c(int p, int r){
	//creating linked list
	pair<int,int> knight[1111];
	FOR(i,1,p){
		knight[i].A = i-1;
		knight[i].B = i+1;
	}
	knight[1].A = p; knight[p].B = 1;
	int now = p;
	REP(step,p-1){
		REP(i,r) now = knight[now].B;
		//dismiss now
		knight[knight[now].A].B = knight[now].B;
		knight[knight[now].B].A = knight[now].A;
	}
	assert(knight[now].A == knight[now].B);
	return knight[now].B;
}

int main(){
	
	int n, k;
	while (scanf("%d%d",&n,&k)) printf("%d\n",c(n,k));
	
	int t = c(999,11) + c(121,12) + c(2,1) + c(15,16) + c(99,3);
	printf("%d\n",t);
	
	return 0;
}
