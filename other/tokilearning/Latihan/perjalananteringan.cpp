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

const int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
const int INF = 1000000000;
const int MAXN = 1000;
const int MAXN = 1000;
int r,c,d,ra,rb,rr,ca,cb,cc,xxx,_x,a[MAXN][MAXN],x[MAXN][MAXN];
priority_queue <pair<int,pair<int,int> > > pq;

int main(){
	scanf("%d%d",&r,&c);
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j) scanf("%d",&a[i][j]);
	scanf("%d%d%d%d",&ra,&ca,&rb,&cb);
	--ra; --rb; --ca; --cb;
	pq.push(make_pair(0,make_pair(ra,ca)));
	for (int i=0; i<r; ++i)
		for (int j=0; j<c; ++j) x[i][j] = INF;
	pair<int,pair<int,int> > now;
	while (!pq.empty()){
		now = pq.top(); pq.pop();
		xxx = -now.first;
		ra = now.second.first; ca = now.second.second;
		if (ra==rb && ca==cb){
			printf("%d\n",xxx);
			return 0;
		}
		for (d = 0; d<4; ++d){
			rr = ra + next[d][0]; cc = ca + next[d][1];
			if (rr < 0 || cc < 0 || rr==r || cc==c) continue;
			if (a[rr][cc] < 0) continue;
			_x = max(xxx,a[rr][cc]);
			if (_x < x[rr][cc]){
				x[rr][cc] = _x;
				pq.push(make_pair(-_x,make_pair(rr,cc)));
			}
		}
	}
	return 0;
}
	
	
	
	
	
	
