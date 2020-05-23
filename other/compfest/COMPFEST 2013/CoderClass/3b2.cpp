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

#define MAXN 100100
#define UNDEFINED 1e100
struct dikra{int s, d;}; //line y = s + dx
bool comp(const dikra &a, const dikra &b){
	if (a.d != b.d) return a.d > b.d;
	return a.s < b.s;
}
double intersect(dikra a, dikra b){
	//a.s + a.d*x = b.s + b.d*x
	if (a.d == b.d) return UNDEFINED;
	return (db)(a.s-b.s)/(db)(b.d-a.d);
}
vector<dikra> atur(vector<dikra> a){
	vector<dikra> ans;
	if (a.empty()) return ans;
	sort(ALL(a),comp);
	double last = 0;
	FORIT(it,a){
		if (ans.empty()){
			ans.PB(*it); continue;
		}
		if (it->d == ans.back().d) continue;
		double now = intersect(ans.back(),*it);
		while (last > now){
			ans.pop_back();
			if (ans.empty()) break;
			now = intersect(ans.back(),*it);
		}
		if (ans.empty()){
			ans.PB(*it); last = 0; continue;
		}
		ans.PB(*it);
		last = now;
	}
	return ans;
}

int ntc, n, m, mc[MAXN], mv[MAXN];
vector<dikra> v, c, _v, _c;

int main(){
	scanf("%d",&ntc);
	REP(itc,ntc){
		scanf("%d%d",&n,&m);
		_v.clear(); _c.clear();
		REP(i,n){
			int j;
			dikra h;
			scanf("%d%d%d",&j,&h.s,&h.d);
			if (j == 0) _c.PB(h); else _v.PB(h);
		}
		v = atur(_v); c = atur(_c);
		int pv = 0, pc = 0;
		if (!v.empty()) FOR(i,0,m){
			int now = v[pv].s + v[pv].d * i;
			while (pv+1 < SZ(v)){
				if (v[pv+1].s + v[pv+1].d * i < now){
					now = v[pv+1].s + v[pv+1].d * i;
					pv++;
				}
				else break;
			}
			mv[i] = now;
		}
		if (!c.empty()) FOR(i,0,m){
			int now = c[pc].s + c[pc].d * i;
			while (pc + 1 < SZ(c)){
				if (c[pc+1].s + c[pc+1].d * i < now){
					now = c[pc+1].s + c[pc+1].d * i;
					pc++;
				}
				else break;
			}
			mc[i] = now;
		}
		int ans = 0;
		if (v.empty()) ans = mc[m];
		else if (c.empty()) ans = mv[m];
		else FOR(i,0,m) MX(ans,min(mv[i],mc[m-i]));
		printf("%d\n",ans);
				
	}
	return 0;
}
