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

string s;
int m,k,n,c,ss,ans,a[111],dp[111][1111],idx[111],limit;

int main(){
    cin >> m >> k >> s;
    n = s.length();
    if (m>n) m=n;
    for (int i=0; i<n; ++i)
        if (s[i]=='?') a[i] = -1;
           else a[i] = (int)s[i] - 48;
    limit = 1 << m;
    for (int p=0; p+m<=n; ++p)
        for (int s=0; s<limit; ++s){
            c = 0;
            for (int i=0; i<m; ++i){
                idx[i] = ((1 << i)&s)>0 ? 1 : 0;
                if (idx[i]==1) ++c;
                }
            if (c!=k) continue;
            c = 1;
            for (int i=0; i<m; ++i)
                if (a[i+p]!=-1 && a[i+p]!=idx[i]) c=0;
            if (c=0) continue;
            if (p==0){
                      dp[p][s] = 1;
                      continue;
                      }
            ss = (s - idx[m-1]*(1 << (m-1))) << 1;
            dp[p][s] = dp[p-1][ss+1] + dp[p-1][ss];
            //printf("%d %d %d --- %d %d\n",p,s,dp[p][s],ss,idx[m-1]);
            }
    ans = 0;
    for (int s=0; s<limit; ++s){
        //printf("%d\n",dp[n-m][s]);
        ans += dp[n-m][s];
        }
    printf("%d\n",ans);
    return 0;
}
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
