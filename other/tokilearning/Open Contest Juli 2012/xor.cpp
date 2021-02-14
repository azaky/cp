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

int n,m,a[111111],ans[111111],rules[111],cur[111][111];

int main(){
    scanf("%d%d",&n,&m);
    //determining the rules
    for (int i=0; i<=m; ++i)
        for (int j=0; j<=m; ++j)
            cur[i][j] = (i==j) ? 1 : 0;
    for (int step=1; step<=m; ++step)
        for (int i=0; i<=m-step; ++i)
            //cur[i]^=cur[i+1]
            for (int j=0; j<=m; ++j)
                cur[i][j]^=cur[i+1][j];
    for (int i=0; i<=m; ++i)
        rules[i] = cur[0][i];
    /*
    for (int i=0; i<=m; ++i)
        cout << rules[i] << " ";
    cout << endl;
    */
    for (int i=0; i<n; ++i)
        scanf("%d",&a[i]);
    for (int i=0; i<m; ++i)
        ans[i] = 0;
    for (int i=m; i<n+m; ++i){
        ans[i] = a[i-m];
        for (int j=0; j<m; ++j)
            if (rules[j]) ans[i] ^= ans[i-m+j];
        }
    for (int i=0; i<n+m; ++i)
        printf("%d\n",ans[i]);
    return 0;
}
