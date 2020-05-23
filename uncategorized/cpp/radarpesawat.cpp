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

#define MAXN 100100
int n,idx,pesawat[MAXN],t[MAXN],v[MAXN],ans,seen[MAXN],x,last,meet[MAXN];
map <vector<int>,int> M;
vector <int> mm;
stack <int> S;

int main(){
	scanf("%d",&n);
	idx = 0; mm.push_back(-1); mm.push_back(-1);
	for (int i=0; i<n; ++i){
		scanf("%d%d",&t[i],&v[i]);
		mm[0] = t[i]; mm[1] = v[i];
		if (M[mm]==0) M[mm]=++idx;
		pesawat[i] = M[mm];
	}
	last = -1;
	memset(meet,1,sizeof(meet));
	for (int i=0; i<n; ++i){
		if (!meet[pesawat[i]]){
			meet[pesawat[i]] = 1;
			seen[pesawat[i]] = pesawat[i]==last ? 1 : 0;
		}
		else ++seen[pesawat[i]];
		
		if (seen[pesawat[i]]==2){
			if (ans==0) memset(meet,0,sizeof(meet));
			while (!S.empty()){
				x = S.top(); S.pop();
				meet[x] = 0; seen[x] = 0;
			}
			last = pesawat[i];
			++ans;
		}
		else S.push(pesawat[i]);
	}
	last = 0;
	for (int i=0; i<n; ++i)
		if (seen[pesawat[i]]>=1) last = 1;
	if (last) ++ans;
	
	printf("%d\n",ans);
	return 0;
}
