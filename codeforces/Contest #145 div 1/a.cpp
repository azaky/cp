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

const int maxn = 111;
int m, k, x, fav[maxn], high[maxn], low[maxn], n, d, nfav, nkos, maxl, maxh;
char title[111];

int main(){
	#ifdef DEBUG
	#else
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
	scanf("%d%d",&m,&k);
	for (int i=0; i<k; ++i) scanf("%d",&x), fav[x] = 1;
	scanf("%d",&n);
	maxl = maxh = 0;
	for (int i=0; i<n; ++i){
		scanf("%s %d",title,&d);
		nfav = nkos = 0;
		for (int j=0; j<d; ++j){
			scanf("%d",&x);
			if (x == 0) ++nkos;
			if (fav[x]) ++nfav;
		}
		//(m-k) - (d - nkos - nfav)
		low[i] = max(0,-m+k+d-nfav)+nfav;
		//k - nfav
		high[i] = min(nkos,k-nfav)+nfav;
	}
	for (int i=0; i<n; ++i){
		maxh = maxl = 0;
		for (int j=0; j<n; ++j){
			if (i == j) continue;
			maxh = max(maxh,high[j]);
			maxl = max(maxl,low[j]);
		}
		debug("FILM #%d: %d .. %d\n",i,low[i],high[i]);
		if (low[i] >= maxh) puts("0");
		else if (high[i] < maxl) puts("1");
		else puts("2");
	}
	
	return 0;
}
