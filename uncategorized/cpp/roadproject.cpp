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

#define MAXN 222222

int n,m,x,a[MAXN],b[MAXN],c[MAXN],visit[MAXN],used[MAXN];
int ii,vv,uu,cc;
long long ans;
vector <pair<int,int> > h[MAXN];
priority_queue <pair<int,pair<int,int> > > pq;

int main(){
	scanf("%d%d%d",&n,&m,&x);
	for (int i=0; i<m; ++i){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		c[i] = x - c[i];
		h[a[i]-1].push_back(make_pair(b[i]-1,i));
		h[b[i]-1].push_back(make_pair(a[i]-1,i));
	}
	//pq: <c,<v,i>>
	pq.push(make_pair(0,make_pair(0,MAXN-1)));
	while (!pq.empty()){
		cc = pq.top().first;
		vv = pq.top().second.first;
		ii = pq.top().second.second;
		pq.pop();
		
		if (used[ii]) continue;
		used[ii] = 1;
		
		debug("%d %d %d\n",vv,cc,ii);
		
		if (visit[vv]){
			if (cc > 0) ans += (long long)cc;
			continue;
		}
		visit[vv] = 1;
		ans += (long long)cc;
		
		for (int i=0; i<h[vv].size(); ++i){
			uu = h[vv][i].first;
			ii = h[vv][i].second;
			pq.push(make_pair(c[ii],make_pair(uu,ii)));
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
