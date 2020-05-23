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
	int child[31];
};

vector <_trie> trie;
_trie init;

int size;
int l,n,price[33],m,a[33],ans[33],arr[33],now,used[33],mincost;

void dfs(int v, int cost, int depth);

int main(){
	
	init.num =init.occ = 0;
	memset(init.child,-1,sizeof(init.child));
	
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
				if (trie[now].child[a[i]] < 0){
					trie.push_back(init);
					trie[size].num = a[i];
					trie[now].child[a[i]] = size++;
				}
				now = trie[now].child[a[i]];
			}
			trie[now].occ++;
		}
		
		for (int i=1; i<=l; ++i) ans[i] = arr[i] = l+1;
		for (int i=1; i<=l; ++i) used[i] = 0;
		mincost = 1000000000;
		dfs(0,0,0);
		
		for (int i=1; i<l; ++i) printf("%d ",ans[i]);
		printf("%d\n",ans[l]);
	}
	return 0;
}

void dfs(int v, int cost, int depth){
	cost += trie[v].occ*price[depth];
	arr[depth] = trie[v].num;
	
	if (cost >= mincost) return;
	
	if (depth == l){
		for (int j=1; j<=l; ++j) ans[j] = arr[j];
		mincost = cost;
		return;
	}
	
	//debug("V = %d; DEPTH = %d; COST = %d\n",trie[v].num,depth,cost);
	
	for (int i=1; i<=l; ++i){
		if (used[i]) continue;
		if (trie[v].child[i] < 0){
			if (cost >= mincost) return;
			used[i] = 1; arr[++depth] = i;
			int k = depth;
			for (int j=1; j<=l; ++j)
				if (!used[j]) arr[++k] = j;
			
			for (int j=1; j<=l; ++j) ans[j] = arr[j];
			//for (int j=1; j<=l; ++j) debug("%d ",ans[j]); debug(":%d\n",cost);
			mincost = cost;
			used[i] = 0;
			return;
		}
		used[i] = 1; dfs(trie[v].child[i],cost,depth+1); used[i] = 0;
	}
	return;
}


