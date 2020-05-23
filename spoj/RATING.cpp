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

#define MAXR 100000
#define MAXN 300000
struct Coder {int a,b,i;} coder[MAXN+5];
int n, ans[MAXN+5], bit[MAXR+5];
map <PII,int> cot;

bool comp(const Coder &a, const Coder &b) {if (a.a != b.a) return a.a < b.a; return a.b < b.b;}
void update(int k) {for (int x = k; x <= MAXR; x += (x & -x)) bit[x]++;}
int query(int k) {int sum = 0; for (int x = k; x; x -= (x & -x)) sum += bit[x]; return sum;}

int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%d%d",&coder[i].a,&coder[i].b);
		coder[i].i = i;
	}
	sort(coder,coder+n,comp);
	REP(i,n){
		ans[coder[i].i] = query(coder[i].b) - cot[mp(coder[i].a,coder[i].b)];
		update(coder[i].b);
		cot[mp(coder[i].a,coder[i].b)] ++;
	}
	REP(i,n) printf("%d\n",ans[i]);
	
	return 0;
}
