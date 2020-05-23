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
#define INF 1000000

int n,q,a[MAXN],l,r,ni,ans[MAXN],idx;
vector <pair<pair<int,int>,int> > qq;
vector <int> lst[MAXN];

int main(){
	scanf("%d%d",&n,&q);
	for (int i=0; i<n; ++i) scanf("%d",&a[i]);
	for (int i=0; i<q; ++i){
		scanf("%d%d",&l,&r);
		qq.push_back(make_pair(make_pair(l,r),i));
	}
	sort(qq.begin(),qq.end());
	for (int i=1; i<=n; ++i) lst[i].push_back(0);
	for (int i=0; i<n; ++i) {
		if (a[i]>n) { a[i] = -1; continue;};
		lst[a[i]].push_back(i+1);
	}
	for (int i=1; i<=n; ++i) lst[i].push_back(n+1);
	for (int i=1; i<=n; ++i) {
		ni = lst[i].size()-2;
		if (ni < i) continue;
		idx = 1;
		for (int j=0; j<q; ++j){
			while (qq[j].first.first > lst[i][idx]) ++idx;
			if (idx + i - 1 > ni) break;
			if (qq[j].first.second >= lst[i][idx+i-1] && qq[j].first.second < lst[i][idx+i]) ++ans[qq[j].second];
		}
	}
	for (int i=0; i<q; ++i) printf("%d\n",ans[i]);
	return 0;
}
