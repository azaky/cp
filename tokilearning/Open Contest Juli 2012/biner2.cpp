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
int m,k,n,c,ans,same,a[111],t[111],limit;

int main(){
    cin >> m >> k >> s;
    n = s.length();
    if (m>n) m=n;
    for (int i=0; i<n; ++i)
        if (s[i]=='?') a[i] = -1;
           else a[i] = (int)s[i] - 48;
    limit = 1 << m; ans = 0;
    for (int s=0; s<limit; ++s){
        c = 0;
        for (int i=0; i<m; ++i){
            t[i] = ((1 << i)&s)>0 ? 1 : 0;
            if (t[i]==1) ++c;
            }
        if (c!=k) continue;
        for (int i=m; i<n; ++i)
            t[i] = t[i-m];
        same = 1;
        for (int i=0; i<n; ++i)
            if (a[i]!=-1 && a[i]!=t[i]) same = 0;
        ans += same;
        }
    printf("%d\n",ans);
    return 0;
}
