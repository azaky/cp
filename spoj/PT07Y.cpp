#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAXN 20010
using namespace std;

int tree(){
	int n,m,ep1,ep2,v,visit[MAXN];
	vector <int> adj[MAXN];
	scanf("%d%d",&n,&m);
	if (m!=n-1) return 0;
	for (int i=0; i<m; ++i){
		scanf("%d%d",&ep1,&ep2);
		--ep1; --ep2;
		if (ep1==ep2) return 0;
		adj[ep1].push_back(ep2);
		adj[ep2].push_back(ep1);
	}
	queue <int> q;
	q.push(0);
	memset(visit,0,sizeof(visit));
	while (!q.empty()){
		v = q.front(); q.pop();
		visit[v] = 1;
		for (int i=0; i<adj[v].size(); ++i)
			if (!visit[adj[v][i]]) q.push(adj[v][i]);
	}
	for (int i=0; i<n; ++i)
	    if (!visit[i]) return 0;
	return 1;
}

int main(){
	if (tree()) printf("YES\n");
		else printf("NO\n");
	return 0;
}
