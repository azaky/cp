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

struct _trie{
	int num;
	int occ;
	int mins;
	vector <pair<int,int> > child;
};

vector <_trie> trie;
_trie init;

int size, target;
int l,n,price[33],m,a[33],ans[33],arr[33],now,used[33],mincost;
int mind,dum[33],k,better;

void dfs(int v, int cost, int depth);

int main(){
	
	init.num =init.occ = 0;
	init.child.clear();
	
	int tc; scanf("%d",&tc);
	for (int _tc = 0; _tc < tc; ++_tc){
		
		trie.clear(); trie.push_back(init);
		size = 1;
		
		scanf("%d%d",&l,&n);
		for (int i=1; i<=l; ++i) scanf("%d",&price[i]);
		for (int ii=0; ii<n; ++ii){
			scanf("%d",&m);
			for (int i=0; i<m; ++i) scanf("%d",&a[i]);
			now = 0;
			for (int i=0; i<m; ++i){
				target = -1;
				for (int j=0; j<trie[now].child.size(); ++j)
					if (trie[now].child[j].first == a[i]) {target = j; break;}
				if (target < 0){
					target = trie[now].child.size();
					trie.push_back(init);
					trie[size].num = a[i];
					trie[now].child.push_back(make_pair(a[i],size++));
				}
				now = trie[now].child[target].second;
			}
			trie[now].occ++;
		}
		
		for (int i=1; i<=l; ++i) ans[i] = arr[i] = l+1;
		for (int i=1; i<=l; ++i) used[i] = 0;
		mincost = 1000000000;
		dfs(0,0,0);
		
		for (int i=1; i<l; ++i) printf("%d ",ans[i]);
		printf("%d\n",ans[l]);
		debug("---%d---\n",mincost);
	}
	return 0;
}

void dfs(int v, int cost, int depth){
	cost += trie[v].occ*price[depth];
	arr[depth] = trie[v].num;
	
	if (cost > mincost) return;
	
	if (depth == l){
		better = 1;
		if (cost == mincost)
			for (int i=1; i<=l; ++i)
				if (ans[i] < arr[i]){better = 0; break;}
				else if (ans[i] > arr[i]){break;}
		if (!better) return;
		for (int j=1; j<=l; ++j) ans[j] = arr[j];
		mincost = cost;
		return;
	}
	
	debug("V = %d; DEPTH = %d; COST = %d\n",trie[v].num,depth,cost);
	
	for (int i=0; i<trie[v].child.size(); ++i){
		//if (used[trie[v].child[i].first]) continue;
		used[trie[v].child[i].first] = 1;
		dfs(trie[v].child[i].second,cost,depth+1);
		used[trie[v].child[i].first] = 0;
	}
	
	if (cost > mincost) return;
	
	memset(dum,0,sizeof(dum));
	for (int i=0; i<trie[v].child.size(); ++i) dum[trie[v].child[i].first] = 1;
	mind = l+1;
	for (int i=1; i<=l; ++i)
		if (!used[i] && !dum[i] && i<mind) mind = i;
	if (mind > l) return;
	used[mind] = 1; arr[++depth] = mind;
	
	k = depth;
	for (int i=1; i<=l; ++i)
		if (!used[i]) arr[++k] = i;
	
	better = 1;
	if (cost == mincost)
		for (int i=1; i<=l; ++i)
			if (ans[i] < arr[i]){better = 0; break;}
			else if (ans[i] > arr[i]){break;};
	
	if (!better) return;
	
	for (int i=1; i<=l; ++i) ans[i] = arr[i];
	mincost = cost;
	
	for (int j=1; j<=l; ++j) debug("%d ",ans[j]); debug(":%d\n",cost);
			
	used[mind] = 0;
	return;
}
