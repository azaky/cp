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
#include <cassert>
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

int main(){
	
	LL r, c, m, s, nr, nc, minn = 0, maxx = 0;
	
	cin >> r >> c;
	cin >> m >> s;
	
	//assert(1 <= m && m <= c);
	
	/*
	if (!(1 <= m && m <= c)){
		while (1){ LL t = 10; }
	}
	*/
	
	//cek minimum
	nr = 0; nc = m;
	REP(i,r){
		nr ++;
		if (nc == 0) nc = 1;
		if (nc > 1) nc--;
		minn += (nr-1)*c + nc;
	}
	//cek maksimum
	nr = 0; nc = m;
	REP(i,r){
		nr ++;
		if (nc > c) nc = c;
		if (nc < c) nc++;
		maxx += (nr-1)*c + nc;
	}
	
	//cout << minn << " " << maxx << endl;
	
	if (maxx >= s) cout << "Ya " << max(s,minn) << endl;
	else cout << "Tidak " << maxx << endl;
	
	return 0;
}
