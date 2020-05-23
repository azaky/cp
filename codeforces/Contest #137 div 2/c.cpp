#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
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
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}

/* -------------- end of azaky's template -------------- */

const int MAXN = 10000005;
const int MAXM = 100005;
const int MAXP = 700000;
const long long LIM = 10000000LL;

int prime[MAXN],nextprime[MAXN],p[MAXP],ip[MAXN],np;
int n,m,x,xnum[MAXM],xden[MAXM];
int num[MAXP],den[MAXP],nnum,anum[MAXM],nden,aden[MAXM];

int main(){
	for (int i=2; i<MAXN; ++i) prime[i] = 1;
	for (int i=2; i*i<MAXN; ++i)
		if (prime[i])
			for (int j=i; i*j<MAXN; ++j){
				nextprime[i*j] = i;
				prime[i*j] = 0;
			}
	for (int i=2; i<MAXN; ++i)
		if (prime[i]){
			nextprime[i] = i;
			ip[i] = np;
			p[np++] = i;
		}
	debug("%d\n",np);
	debug("%d\n",p[np-1]);
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; ++i){
		scanf("%d",&x);
		xnum[i] = x;
		while (x > 1){
			++num[ip[nextprime[x]]];
			x /= nextprime[x];
		}
	}
	for (int i=0; i<m; ++i){
		scanf("%d",&x);
		xden[i] = x;
		while (x > 1){
			++den[ip[nextprime[x]]];
			x /= nextprime[x];
		}
	}
	for (int i=0; i<np; ++i){
		if (num[i] >= den[i]){
			num[i] -= den[i];
			den[i] = 0;
		}
		else {
			den[i] -= num[i];
			num[i] = 0;
		}
	}
	for (int i=0; i<n; ++i){
		anum[i] = 1;
		x = xnum[i];
		while (x > 1){
			if (num[ip[nextprime[x]]]>0){
				anum[i] *= nextprime[x];
				--num[ip[nextprime[x]]];
			}
			x /= nextprime[x];
		}
	}
	for (int i=0; i<m; ++i){
		aden[i] = 1;
		x = xden[i];
		while (x > 1){
			if (den[ip[nextprime[x]]]>0){
				aden[i] *= nextprime[x];
				--den[ip[nextprime[x]]];
			}
			x /= nextprime[x];
		}
	}
	
	/*
	nnum = 1; anum[nnum-1] = 1;
	for (int i=0; i<np; ++i)
		while (num[i]>0){
			--num[i];
			if ((long long)p[i]*(long long)anum[nnum-1] <= LIM) anum[nnum-1] *= p[i];
				else anum[nnum++] = p[i];
		}
	nden = 1; aden[nden-1] = 1;
	for (int i=0; i<np; ++i)
		while (den[i]>0){
			--den[i];
			if ((long long)p[i]*(long long)aden[nden-1] <= LIM) aden[nden-1] *= p[i];
				else aden[nden++] = p[i];
		}
	*/
	printf("%d %d\n",n,m);
	for (int i=0; i<n; ++i) printf("%d ",anum[i]); printf("\n");
	for (int i=0; i<m; ++i) printf("%d ",aden[i]); printf("\n");
	return 0;
}
