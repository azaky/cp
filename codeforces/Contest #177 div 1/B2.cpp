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
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

int n, k, next[10], ans;

void perm(int pos){
	if (pos > k){
		FOR(i,2,k){
			int now = i;
			bool visit[10];
			FOR(i,1,k) visit[i] = false;
			while (now != 1 && !visit[now]) visit[now] = true, now = next[now];
			if (now != 1) return;
		}
		ans++;
	}
	else {
		FOR(i,1,k){
			if (i == pos) continue;
			next[pos] = i;
			perm(pos+1);
		}
	}
}

#define MOD 1000000007LL

LL power(LL a, LL b){
	if (b <= 0) return 1;
	LL temp = power(a,b>>1);
	temp = (temp*temp)%MOD;
	if (b&1) temp = (temp*a) % MOD;
	return temp;
}


int main(){
	scanf("%d%d",&n,&k);
	ans = 0;
	perm(2);
	ans *= k;
	printf("%d\n",ans);
	ans = int(((LL)ans * power(LL(n-k),LL(n-k))) % MOD);
	printf("%I64d\n",(LL)ans);
	printf("%I64d\n",(LL(ans)*power(n-k,n-k))%MOD);
	
	return 0;
}
