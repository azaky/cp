#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

#define MAXN 111111

int n,k,next[MAXN][11],path[MAXN],v,d,vv,dd;
priority_queue <pair<int, int> > q;

int main(){
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; ++i)
        for (int j=0; j<k; ++j){
            scanf("%d",&next[i][j]);
            --next[i][j];
            }
    for (int i=0; i<n; ++i) path[i] = 1000000000;
    path[0] = 0;
    q.push(make_pair(0,0));
    while (!q.empty()){
          v = q.top().second;
          d = -q.top().first;
          q.pop();
          
          if (v == n-1) break;
          if (d > path[v]) continue;
          
          for (int i=0; i<k; ++i){
              vv = next[v][(d+i)%k];
              dd = d + i + 1;
              if (dd < path[vv]){
                     path[vv] = dd;
                     q.push(make_pair(-dd,vv));
                     }
              }
          }
    printf("%d\n",path[n-1]);
    return 0;
}
