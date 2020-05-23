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

typedef unsigned long long uLL;
const uLL MOD = 4294967296LL;

uLL calc(int L, int x, int y, int z, int w){
	if (L == 1){
		if (x < 0 || y < 0 || z < 0 || w < 0 || x > 3 || y > 2 || z > 1 || w > 1) return 0;
		int V = 1;
		REP(i,x) V *= 2; REP(i,y) V *= 3; REP(i,z) V *= 5; REP(i,w) V *= 7;
		return V < 10 ? 1 : 0;
	}
	uLL ret = 0;
	if (L % 2 == 0){
		ret = (ret + calc(L-1,x,y,z,w)) % MOD; // 1
		ret = (ret + calc(L-1,x-1,y,z,w)) % MOD; // 2
		ret = (ret + calc(L-1,x,y-1,z,w)) % MOD; // 3
		ret = (ret + calc(L-1,x-2,y,z,w)) % MOD; // 4
		ret = (ret + calc(L-1,x,y,z-1,w)) % MOD; // 5
		ret = (ret + calc(L-1,x-1,y-1,z,w)) % MOD; // 6
		ret = (ret + calc(L-1,x,y,z,w-1)) % MOD; // 7
		ret = (ret + calc(L-1,x-3,y,z,w)) % MOD; // 8
		ret = (ret + calc(L-1,x,y-2,z,w)) % MOD; // 9
	}
	else {
		ret = (ret + calc(L-1,x,y,z,w)) % MOD; // 1
		ret = (ret + calc(L-1,x-1,y,z,w)) % MOD; // 2
		ret = (ret + calc(L-1,x,y-1,z,w)) % MOD; // 3
		ret = (ret + calc(L-1,x-2,y,z,w)) % MOD; // 4
		ret = (ret + calc(L-1,x,y,z-1,w)) % MOD; // 5
		ret = (ret + calc(L-1,x-1,y-1,z,w)) % MOD; // 6
		ret = (ret + calc(L-1,x,y,z,w-1)) % MOD; // 7
		ret = (ret + calc(L-1,x-3,y,z,w)) % MOD; // 8
		ret = (ret + calc(L-1,x,y-2,z,w)) % MOD; // 9
	}
		

int main(){
	int ntc; scanf("%d",&ntc);
	while (ntc--){
		cin >> L >> V;
		if (V == 0){
			
			continue;
		}
		x = y = z = w = 0;
		for (; V % 2 == 0; ++x, V /= 2);
		for (; V % 3 == 0; ++y, V /= 3);
		for (; V % 5 == 0; ++z, V /= 5);
		for (; V % 7 == 0; ++w, V /= 7);
		if (V != 1){
			puts("0");
			continue;
		}
		cout << calc(L,x,y,z,w) << endl;
	}
	
	return 0;
}
