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

int n, level;
vector <int> ans[111111];

void practice(int l, int r, int depth){
	if (l == r) return;
	if (depth + 1 > level) level = depth + 1;
	int mid = (l+r)/2;
	for (int i=l; i<=mid; ++i) ans[depth].push_back(i);
	practice(l,mid,depth+1); practice(mid+1,r,depth+1);
}

int main(){
	#ifdef DEBUG
	#else
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
	scanf("%d",&n);
	level = 0;
	practice(1,n,0);
	
	printf("%d\n",level);
	for (int i=0; i<level; ++i){
		printf("%d",(int)ans[i].size());
		for (int j=0; j<(int)ans[i].size(); ++j) printf(" %d",ans[i][j]);
		printf("\n");
	}
	return 0;
}
