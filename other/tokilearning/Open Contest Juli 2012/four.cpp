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
#define MOD 1000000007

int getobs(int lx,int rx,int lc,int rc){
    if (rx<lx) swap(lx,rx);
    if (rc<lc) swap(lc,rc);
    if (lx==0) lx = 1;
    if (lc==0) lc = 1;
    return sum[rx][rc]+sum[lx-1][lc-1]-sum[rx][lc-1]-sum[lx-1][rc];
}

int getfree(int lx, int rx, int lc, int rc){
    return (abs(rx-lx+1)*abs(rc-lc+1)-getobs(lx,rx,lc,rc));
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0; i<k; ++i){
        scanf("%d%d",&x,&y);
        obs[x][y] = 1;
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            sum[i][j] = obs[i][j] + sum[i-1][j-1] - sum[i][j-1] - sum[i-1][j];
    for (r0=1; r0<n; ++r0)
        for (c0=1; c0<m; ++c0)
            for (r2=1; r2<n; ++r2)
                for (c2=1; c2<m; ++c2){
                    if ((r2<r0 && c2<c0) || (r2>=r0 && c2>=c0)) continue;
                    if (obs[r0][c0] || obs[r2][c2]) continue;
                    
                    now = 0;
                    if (r2>=r0){
                                if (c2<=c0)
                                   now = getfree(n,r0,0,c2)*getfree(r2,0,c0,m);
                                else {
                                     now += 
                                            
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
