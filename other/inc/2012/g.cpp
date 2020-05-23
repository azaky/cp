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

struct state{
	int r,c,p,step;
};

queue <state> q;
int tc,n,m,visit[111][111][5],ans,r,c,p,step,fr,fc;
string a[111],dummy;
state init;

void add(int r,int c,int p, int step){
	if (r < 0 || c < 0 || r >= n || c >= m) return;
	if (a[r][c] == '#') return;
	if (p == 1)
		if (a[r][c+1] == '#' || c+1 >= m) return;
	if (p == 2)
		if (a[r+1][c] == '#' || r+1 >= n) return;
	if (visit[r][c][p] != -1 && visit[r][c][p] <= step) return;
	visit[r][c][p] = step;
	init.r = r;
	init.c = c;
	init.p = p;
	init.step = step;
	q.push(init);
}


int main(){
	scanf("%d\n",&tc);
	for (int _tc = 1; _tc <= tc; ++_tc){
		scanf("%d%d\n",&n,&m);
		for (int i=0; i<n; ++i) getline(cin,a[i]);
		
		while (!q.empty()) q.pop();
		memset(visit,-1,sizeof(visit));
		
		for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j){
			if (a[i][j] == 'S'){
				init.r = i;
				init.c = j;
				init.p = 0;
				init.step = 0;
				visit[r][c][p] = 0;
				q.push(init);
			}
			if (a[i][j] == 'F'){
				fr = i; fc = j;
			}
		}
		ans = -1;
		while (!q.empty()){
			init = q.front();
			r = init.r;
			c = init.c;
			p = init.p;
			step = init.step;
			q.pop();
			if (r == fr && c == fc && p == 0){
				ans = step;
				break;
			}
			if (p == 0){
				add(r,c+1,1,step+1);
				add(r,c-2,1,step+1);
				add(r+1,c,2,step+1);
				add(r-2,c,2,step+1);
			}
			if (p == 1){
				add(r,c+2,0,step+1);
				add(r-1,c,1,step+1);
				add(r+1,c,1,step+1);
				add(r,c-1,0,step+1);
			}
			if (p == 2){
				add(r,c+1,2,step+1);
				add(r,c-1,2,step+1);
				add(r+2,c,0,step+1);
				add(r-1,c,0,step+1);
			}
		}
		printf("Case #%d: %d\n",_tc,ans);
	}
	
	return 0;
}
