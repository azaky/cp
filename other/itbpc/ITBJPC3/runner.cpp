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

#define MAXN 100100
int prime[MAXN],idp[MAXN],p[MAXN],RMQ[4*MAXN],nprime;

int diff(int x){
	return p[x+1]-p[x];
}

void build(int v, int l, int r){
	if (l == r){
		RMQ[v] = l;
		return;
	}
	build(2*v,l,(l+r)/2); build(2*v+1,(l+r+2)/2,r);
	RMQ[v] = diff(RMQ[2*v]) > diff(RMQ[2*v+1]) ? RMQ[2*v] : RMQ[2*v+1];
}
int query(int v, int l, int r, int x, int y){
	if (x <= l && r <= y) return RMQ[v];
	int ret = nprime, mid = (l+r)>>1;
	if (mid >= x){
		int retl = query(2*v,l,mid,x,y);
		if (diff(retl) > diff(ret)) ret = retl;
	}
	if (mid < y){
		int retr = query(2*v+1,mid+1,r,x,y);
		if (diff(retr) > diff(ret)) ret = retr;
	}
	return ret;
}

int main(){
	//SIEVE ERATOSTHENES
	RESET(prime,1);
	prime[1] = 0;
	for (int i=2; i*i < MAXN; ++i) if (prime[i]) for (int j=2; i*j < MAXN; ++j) prime[i*j] = 0;
	idp[1] = 0;
	FOR(i,2,MAXN-1){
		idp[i] = idp[i-1];
		if (prime[i]){
			idp[i]++;
			p[idp[i]] = i;
		}
	}
	nprime = idp[MAXN-1];
	//BUILD SEGMENT TREE
	build(1,1,nprime-1);
	//MAIN PROGRAM
	int n, a, b;
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%d%d",&a,&b);
		a = idp[a-1]+1;
		b = idp[b];
		//printf("[%d %d]\n",a,b);
		if (a >= b){
			puts("-1");
			continue;
		}
		int best = query(1,1,nprime-1,a,b-1);
		//printf("BEST = %d\n",best);
		if (1000*diff(best) > i) printf("%d %d\n",p[best],p[best+1]);
		else puts("-1");
	}
	
	return 0;
}
