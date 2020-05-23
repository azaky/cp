#include<bits/stdc++.h>
using namespace std;
 
#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
 
int N,M;
map<pint,int>table;
int cur;
vpint G[1000000];
 
int make(int a,int c){
    if(table.count({a,c}))return table[{a,c}];
    table[{a,c}]=cur;
    G[a].pb({cur,1});
    G[cur].pb({a,0});
    return cur++;
}
int dist[1000000];
 
signed main(){
    cin>>N>>M;
    cur=N;
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        a=make(a,c);
        b=make(b,c);
        G[a].pb({b,0});
        G[b].pb({a,0});
    }
 
    fill_n(dist,cur,1001001001);
    dist[0]=0;
    priority_queue<pint>que;
    que.push({0,0});
    while(que.size()){
        int v,c;
        tie(c,v)=que.top();que.pop();
        c=-c;
        if(dist[v]<c)continue;
        for(auto e:G[v]){
            if(dist[e.fi]<=c+e.se)continue;
            dist[e.fi]=c+e.se;
            que.push({-dist[e.fi],e.fi});
        }
    }
 
    if(dist[N-1]==1001001001)cout<<-1<<endl;
    else cout<<dist[N-1]<<endl;
    return 0;
}