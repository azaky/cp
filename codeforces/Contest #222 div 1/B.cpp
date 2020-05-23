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
#include <limits>
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
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

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

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

#define MAXN 111111

int n, m, s, b[MAXN], c[MAXN], l, r, days, ans[MAXN];
pii a[MAXN];
pair<pii,int> st[MAXN];

bool check(int days){
	priority_queue <pii> pq;
	int idx = 0;
	int cost = s;
	for (int i = 0; i < m; i += days){
		while (idx < n && st[idx].A.A >= a[i].A){
			pq.push(MP(-st[idx].A.B,st[idx].B));
			idx++;
		}
		if (pq.empty()) return false;
		pii humbala = pq.top(); pq.pop();
		cost += humbala.A;
		if (cost < 0) return false;
		for (int j = i; j < i+days && j < m; ++j) ans[a[j].B] = humbala.B;
	}
	return true;
}

int main(){
	scanf("%d%d%d",&n,&m,&s);
	REP(i,m) scanf("%d",&a[i].A);
	REP(i,n) scanf("%d",&b[i]);
	REP(i,n) scanf("%d",&c[i]);
	
	REP(i,m) a[i].B = i;
	sort(a,a+m);
	reverse(a,a+m);
	
	//check for NO
	bool no = true;
	REP(i,n) if (c[i] <= s && b[i] >= a[0].A) no = false;
	if (no){
		puts("NO");
		return 0;
	}
	
	//humbala
	REP(i,n) st[i] = MP(MP(b[i],c[i]),i);
	sort(st,st+n);
	reverse(st,st+n);
	
	l = 1; r = m;
	days = m;
	while (l < r){
		days = (l + r) / 2;
		if (check(days)){
			r = days;
		}
		else {
			l = days + 1;
		}
	}
	
	assert(l == r);
	
	check(l);
	
	puts("YES");
	REP(i,m-1) printf("%d ",ans[i]+1);
	printf("%d\n",ans[m-1]+1);
	
	return 0;
}
