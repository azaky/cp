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

int getint(){
	int ret = 0, mul = 1;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-'){
		mul = -1;
		ch = getchar();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getint(int &x){
	x = getint();
}
long long getLL(){
	long long ret = 0, mul = 1LL;
	char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-'){
		mul = -1LL;
		ch = getchar();
	}
	do ret = (ret<<1)+(ret<<3)+ch-'0';
	while ((ch = getchar()) && ('0' <= ch && ch <= '9'));
	return ret*mul;
}
void getLL(long long &x){
	x = getLL();
}

/* -------------- end of azaky's template -------------- */

typedef long long LL;
struct node{
	LL l,r;
	LL way[4][4];
};
const LL MOD = 777777777LL;
const LL MAX = 6LL*77777LL;

node nod[MAX];
LL good[4][4],n,m,x,t;

void build(LL v, LL l, LL r){
	nod[v].l = l; nod[v].r = r;
	memset(nod[v].way,0,sizeof(nod[v].way));
	if (l == r){
		for (LL i = 1; i <= 3; ++i) nod[v].way[i][i] = 1;
		return;
	}
	build(2*v,l,(l+r)/2); build(2*v+1,(l+r+2)/2,r);
	for (LL i = 1; i <= 3; ++i)
		for (LL j = 1; j <= 3; ++j)
			for (LL x = 1; x <= 3; ++x)
				for (LL y = 1; y <= 3; ++y)
					if (good[x][y]) nod[v].way[i][j] = (nod[v].way[i][j] + nod[2*v].way[i][x]*nod[2*v+1].way[y][j])%MOD;
}
void update(LL v, LL x, LL t){
	if (nod[v].l == x && nod[v].r == x){
		nod[v].way[1][1] = nod[v].way[2][2] = nod[v].way[3][3] = (t == 0 ? 1 : 0);
		nod[v].way[t][t] = 1;
		return;
	}
	if (nod[v].r < x || nod[v].l > x) return;
	update(2*v,x,t); update(2*v+1,x,t);
	for (LL i = 1; i <= 3; ++i)
		for (LL j = 1; j <= 3; ++j){
			nod[v].way[i][j] = 0;
			for (LL x = 1; x <= 3; ++x)
				for (LL y = 1; y <= 3; ++y)
					if (good[x][y]) nod[v].way[i][j] = (nod[v].way[i][j] + nod[2*v].way[i][x]*nod[2*v+1].way[y][j])%MOD;
		}
}
LL total(){
	LL ret = 0;
	for (LL i = 1; i <= 3; ++i)
		for (LL j = 1; j <= 3; ++j)
			ret = (ret + nod[1].way[i][j])%MOD;
	return ret;
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	for (LL i = 1; i <= 3; ++i) for (LL j = 1; j <= 3; ++j) scanf("%I64d",&good[i][j]);
	build(1,1,n);
	for (LL task = 0; task < m; ++task){
		scanf("%I64d%I64d",&x,&t);
		update(1,x,t);
		printf("%I64d\n",total());
	}
	return 0;
}
