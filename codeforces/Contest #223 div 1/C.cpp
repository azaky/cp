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

#define MAXN 1000100

char s[MAXN];
int n, m, f, sum[MAXN], a[MAXN], ans[MAXN], level, p[MAXN], temen[MAXN];
int bit[MAXN], bitzero[MAXN];
pair <pii,int> q[MAXN];

void update(int x, int v) {
	for (; x <= n; x += (x & -x)) bit[x] += v;
}
int get(int x) {
	int ret = 0;
	for (; x > 0; x -= (x & -x)) ret += bit[x];
	return ret;
}
int get(int x, int y) {
	return get(y) - get(x-1);
}

void updatezero(int x, int v) {
	for (; x <= n; x += (x & -x)) bitzero[x] += v;
}
int getzero(int x) {
	int ret = 0;
	for (; x > 0; x -= (x & -x)) ret += bitzero[x];
	return ret;
}
int getzero(int x, int y) {
	return getzero(y) - getzero(x-1);
}


int main(){
	scanf("%s",s);
	n = strlen(s);
	
	sum[0] = 0;
	level = 0;
	
	REP(i,n) {
		int x = s[i] == '(' ? 1 : -1;
		
		sum[i+1] = sum[i] + x;
		
		if (sum[i+1] < 0) {
			x = 0;
			sum[i+1] = sum[i];
		}
		
		if (x == 0) {
			
		}
		else if (x == 1) {
			level++;
			p[level] = i+1;
		}
		else if (x == -1) {
			temen[i+1] = p[level];
			temen[p[level]] = i+1;
			level--;
		}
		
		if (x != 0) update(i+1,x);
		if (x == 0) updatezero(i+1,1);
		
		a[i+1] = x;
	}
	
	scanf("%d",&m);
	REP(i,m) {
		scanf("%d%d",&q[i].A.A,&q[i].A.B);
		q[i].B = i;
	}
	
	sort(q,q+m);
	
	f = 1;
	REP(i,m) {
		for (; f < q[i].A.A; ++f) {
			if (a[f] == 1 && temen[f] != 0){
				update(temen[f],1);
				updatezero(temen[f],1);
			}
		}
		
		int len = q[i].A.B - q[i].A.A + 1;
		int zeros = getzero(q[i].A.A,q[i].A.B);
		int total = get(q[i].A.A,q[i].A.B);
		
		//printf("query [%d..%d], zeros = %d, total = %d\n",q[i].A.A,q[i].A.B,zeros,total);
		
		ans[q[i].B] = (len-zeros) - total;
	}
	
	REP(i,m) printf("%d\n",ans[i]);
	
	return 0;
}
