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

int n,k[1111],x,il,ir,ii,ans=0,l[111111],r[111111];
vector <int> v[1111];

int main(){
	scanf("%d",&n);
	for (int i=0; i<n; ++i){
		scanf("%d",&k[i]);
		for (int j=0; j<k[i]; ++j){
			scanf("%d",&x);
			v[i].push_back(x);
		}
		sort(v[i].begin(),v[i].end());
	}
	for (int i=0; i<k[0]; ++i) v[n].push_back(v[0][i]);
	for (int i=0; i<k[1]; ++i) v[n+1].push_back(v[1][i]);
	k[n] = k[0]; k[n+1] = k[1];
	
	for (int i=1; i<=n; ++i){
		for (int j=0; j<k[i]; ++j) l[j] = 0;
		il = 0;
		for (int j=0; j<k[i]; ++j){
			while (v[i-1][il]<v[i][j] && il<k[i-1]){
				++l[j];
				++il;
			}
		}
		
		for (int j=0; j<k[i]; ++j) r[j] = 0;
		ir = 0;
		for (int j=0; j<k[i]; ++j){
			while (v[i+1][ir]<v[i][j] && ir<k[i+1]){
				++r[j];
				++ir;
			}
		}
		
		for (int j=1; j<k[i]; ++j)
			if (l[j]!=r[j]) ++ans;
		for (int j=1; j<k[i]; ++j) debug("%d ",l[j]); debug("\n");
		for (int j=1; j<k[i]; ++j) debug("%d ",r[j]); debug("\n");
		
		debug("%d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}

