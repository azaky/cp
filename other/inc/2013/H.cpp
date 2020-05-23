/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

#define INF 1000000000
#define MAXN 20200
#define LOGMAXN 100

int ntc, n, np, q, par[MAXN], path[MAXN], p[MAXN], level[MAXN];
vector<int> adj[MAXN];

/* RMQ nonpath */
int rmqnonpath[4*MAXN];
void _updatenonpath(int v, int l, int r, int x, int val){
    if (x < l || r < x) return;
    if (l == r){
        rmqnonpath[v] += val;
        return;
    }
    int mid = (l+r)/2;
    _updatenonpath(2*v,l,mid,x,val); _updatenonpath(2*v+1,mid+1,r,x,val);
    rmqnonpath[v] = max(rmqnonpath[2*v],rmqnonpath[2*v+1]);
}
void updatenonpath(int x, int v){
    _updatenonpath(1,1,n,x,v);
}
int _querynonpath(int v, int l, int r, int x, int y){
    if (y < l || r < x) return -INF;
    if (x <= l && r <= y) return rmqnonpath[v];
    int mid = (l+r)/2;
    return max(_querynonpath(2*v,l,mid,x,y),_querynonpath(2*v+1,mid+1,r,x,y));
}
int querynonpath(int x, int y){
    return _querynonpath(1,1,n,x,y);
}
/* RMQ path */
int rmqpath[8*MAXN];
int lazy[8*MAXN];
void _updatepath(int id, int l, int r, int x, int y, int val){
    //do lazy
    rmqpath[id] += lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;

    // out of bounds
    if (l > y || r < x) 
        return;

    // inside bound, do lazy
    if (l >= x && r <= y)
    {
        rmqpath[id] += val;
        lazy[id*2] += val;
        lazy[id*2+1] += val;
    }
    else
    {   
        // spread
        int m = (l+r)>>1;
        _updatepath(id<<1, l, m, x, y, val);
        _updatepath((id<<1) + 1, m+1, r, x, y, val);
        rmqpath[id] = max(rmqpath[id<<1], rmqpath[(id<<1)+1]);
    }
//    printf("updatepath [%d..%d], rmqpath[] = %d\n",l,r,rmqpath[id]);
}
void updatepath(int x, int y, int val){
    _updatepath(1,1,np,x,y,val);
}
int _querypath(int id, int l, int r, int x, int y){
    //do lazy
    rmqpath[id] += lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;

    // out of bounds
    if (l > y || r < x) 
        return -INF;

    // inside bound, do lazy
    if (l >= x && r <= y)
    {
        return rmqpath[id];
    }
          
    // spread
    int m = (l+r)>>1;
    return max(_querypath(id<<1, l, m, x, y), _querypath((id<<1) + 1, m+1, r, x, y));
}
int querypath(int x, int y){
    return _querypath(1,1,np,x,y);
}
/* LCA */
int P[MAXN][LOGMAXN];
void LCApre() {
      int i, j;
    
  //we initialize every element in P with -1
      for (i = 1; i <= n; i++)
          for (j = 0; 1 << j <= n; j++)
              P[i][j] = -1;
    
  //the first ancestor of every node i is T[i]
      for (i = 1; i <= n; i++)
          P[i][0] = p[i];
    
  //bottom up dynamic programing
      for (j = 1; 1 << j <= n; j++)
         for (i = 1; i <= n; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
  }
int LCA(int _p, int q) {
      int tmp, log, i;
    
  //if p is situated on a higher level than q then we swap them
      if (level[_p] < level[q])
          tmp = _p, _p = q, q = tmp;
   
  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= level[_p]; log++);
      log--;
    
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (level[_p] - (1 << i) >= level[q])
              _p = P[_p][i];
    
      if (_p == q)
          return _p;
    
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[_p][i] != -1 && P[_p][i] != P[q][i])
              _p = P[_p][i], q = P[q][i];
    
      return p[_p];
  }

void dfs(int par, int v){
    level[v] = level[par]+1;
    p[v] = par;
    REP(i,SZ(adj[v])){
        if (adj[v][i] != par) dfs(v,adj[v][i]);
    }
}

int main(){
	scanf("%d",&ntc);
    FOR(itc,1,ntc){
        scanf("%d%d",&n,&q);
        FOR(i,1,n) adj[i].clear();
        REP(i,n-1){
            int x, y;
            scanf("%d%d",&x,&y);
            adj[x].PB(y); adj[y].PB(x);
        }
        /* JANGAN LUPA RESET DI SINI */
        RESET(path,0);
        RESET(rmqnonpath,0);
        RESET(rmqpath,0);
        RESET(lazy,0);
        /* finding longest path */
        dfs(0,1);
        int root = 0;
        FOR(i,1,n) if (level[i] > level[root]) root = i;
        dfs(0,root);
        int genta = 0;
        FOR(i,1,n) if (level[i] > level[genta]) genta = i;
        int now = genta;
        np = 0;
        for (int i = 1; now != 0; ++i, np++){
            path[now] = i;
            now = p[now];
        }
        for (int i = 1; i <= n; ++i){
            if (path[i]) updatenonpath(i,-INF);
        }
//        printf("ROOT = %d, GENTA = %d, np = %d\n",root,genta,np);
        /* RMQ */
        //todo
        /* LCA */
        LCApre();
        /* QUERY */
        printf("Case #%d:\n",itc);
        REP(_i,q){
            char task;
            do {
                task = getchar();
            } while (task != 'q' && task != 'u');
            if (task == 'q'){
                printf("%d\n",max(querypath(1,np),querynonpath(1,n)));
            }
            else {
                int x, y, v;
                scanf("%d%d%d",&x,&y,&v);
                int _lca = LCA(x,y);
                while (!path[x] && x != _lca){
                    updatenonpath(x,v);
                    x = p[x];
                }
                while (!path[y] && y != _lca){
                    updatenonpath(y,v);
                    y = p[y];
                }
//                printf("x = %d, y = %d\n",x,y);
                if (path[x] && path[y]){
                    int px = path[x], py = path[y];
                    if (px > py) swap(px,py);
//                    printf("[%d..%d]\n",px,py);
                    updatepath(px,py,v);
                }
                else {
                    /* x == y == _lca */
                    assert(x == y);
                    updatenonpath(x,v);
                }
            }
        }
    }
	
	return 0;
}
