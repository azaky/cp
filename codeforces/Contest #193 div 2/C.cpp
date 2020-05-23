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

typedef pair<int,pair<int,int> > pll;

int n, p, k, id[111111];
pll a[111111];
vector<int> ans;

bool comp(const pll &a, const pll &b){
	if (a.B.B != b.B.B) return a.B.B < b.B.B;
	if (a.B.A == b.B.A) return a.A < b.A;
	return a.B.A > b.B.A;
}
bool comp2(const pll &a, const pll &b){
	if (a.B.A == b.B.A) return id[a.A] > id[b.A];
	return a.B.A > b.B.A;
}

int main(){
	cin >> n >> p >> k;
	REP(i,n){
		int _a, _b;
		cin >> _a >> _b;
		a[i] = MP(i,MP(_a,_b));
	}
	
	sort(a,a+n,comp);
//	REP(i,n) printf("%d:(%d)[%d][%d]\n",i+1,a[i].A+1,a[i].B.A,a[i].B.B);
	REP(i,n) id[a[i].A] = i;
	
	sort(a,a+n,comp2);
	
	int lastid = n;
	//ambil yang gede2
	REP(i,n){
		if (SZ(ans) < k) if (id[a[i].A] >= p-k){
			ans.PB(a[i].A);
			MN(lastid,id[a[i].A]);
		}
	}
	
//	REP(i,k) printf("%d ",ans[i]+1); puts("");
//	printf("ID = %d\n",lastid);
	
	sort(a,a+n,comp);
	
	FOR(i,lastid-(p-k),lastid-1) ans.PB(a[i].A);
	
	REP(i,p) printf("%d ",ans[i]+1);
	
	return 0;
}
