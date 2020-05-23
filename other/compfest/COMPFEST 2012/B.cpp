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

const int MAXM = 100000;
const int MAXN = 111;
int tc, n,m,dd[MAXM],x[MAXM],y[MAXM],deg[MAXN],cantik,pp[MAXN];
vector <int> adj[MAXN];

int main(){
	scanf("%d",&tc);
	while (tc--){
		scanf("%d%d",&n,&m);
		for (int i=0; i<n; ++i) adj[i].clear();
		for (int i=0; i<=m; ++i) dd[i]=0;
		for (int i=0; i<n; ++i) deg[i] = 0;
		for (int i=0; i<m; ++i){
			scanf("%d%d",&x[i],&y[i]);
			--x[i]; --y[i];
			adj[x[i]].push_back(y[i]);
			adj[y[i]].push_back(x[i]);
			deg[x[i]]++; deg[y[i]]++;
		}
		for (int i=0; i<n; ++i) dd[deg[i]]++;
		if (dd[3] == 2 && dd[1] == 4 && dd[2] == n-6) {
			if (n==6){
				printf("cantik\n");
				continue;
			}
			
			cantik = 1;
			for (int i=0; i<n; ++i)
				if (deg[i] == 3){
					pp[1] = 0; pp[2] = 0;
					for (int j=0; j<3; ++j) pp[deg[adj[i][j]]]++;
					if (!(pp[1]==2 && pp[2]==1)) cantik = 0;
				}
			if (cantik) printf("cantik\n"); else printf("tidak cantik\n");
		}
		else printf("tidak cantik\n");
	}
	return 0;
}
