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

const int MAXN = 1005;
int n,m,k,q,row[MAXN],col[MAXN],a[MAXN][MAXN],x,y;
char task;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j) scanf("%d",&a[i][j]);
	for (int i=1; i<=n; ++i) row[i] = i;
	for (int j=1; j<=m; ++j) col[j] = j;
	for (int q=0; q<k; ++q){
		do
			scanf("%c",&task);
		while (task != 'c' && task != 'r' && task != 'g');
		scanf("%d%d",&x,&y);
		if (task=='c') swap(col[x],col[y]);
		else if (task=='r') swap(row[x],row[y]);
		else if (task=='g') printf("%d\n",a[row[x]][col[y]]);
	}
	return 0;
}
