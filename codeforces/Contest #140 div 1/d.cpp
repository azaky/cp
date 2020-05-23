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

const int MAXN = 111;
int n,m,a[MAXN][MAXN],row[MAXN],col[MAXN],ac,ar,sum,positive;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j) scanf("%d",&a[i][j]);
	for (int i=0; i<n; ++i) row[i] = 1;
	for (int i=0; i<m; ++i) col[i] = 1;
	while (1){
		for (int i=0; i<n; ++i){
			sum = 0;
			for (int j=0; j<m; ++j) sum += a[i][j]*row[i]*col[j];
			if (sum < 0) row[i] *= -1;
		}
		for (int j=0; j<m; ++j){
			sum = 0;
			for (int i=0; i<n; ++i) sum += a[i][j]*row[i]*col[j];
			if (sum < 0) col[j] *= -1;
		}
		positive = 1;
		for (int i=0; i<n; ++i){
			sum = 0;
			for (int j=0; j<m; ++j) sum += a[i][j]*row[i]*col[j];
			if (sum < 0) positive = 0;
		}
		if (positive) break;
	}
	ac = ar = 0;
	for (int i=0; i<n; ++i) ac += row[i]==-1 ? 1 : 0;
	for (int i=0; i<m; ++i) ar += col[i]==-1 ? 1 : 0;
	printf("%d",ac);
	for (int i=0; i<n; ++i) if (row[i]<0) printf(" %d",i+1);
	printf("\n");
	printf("%d",ar);
	for (int i=0; i<m; ++i) if (col[i]<0) printf(" %d",i+1);
		
	return 0;
}
