#include <stdio.h>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;

int n,last,len;
char s[111111],ans[111111];
//string s,ans;
priority_queue <pair<int,int> > pq;
pair<int,int> temp;

int main(){
    //cin >> s;
    //n = s.length();
    scanf("%s",s);
    n = strlen(s);
    //printf("%d\n",n);
    for (int i=0; i<n; i++) pq.push(make_pair((int)s[i],-i));
    len = 0; last = -1;
    for (int i=0; i<n; i++){
        temp = pq.top(); pq.pop();
        temp.second = -temp.second;
        if (temp.second < last) continue;
        //ans = ans + (char)temp.first;
        ans[len++] = (char)temp.first;
        last = temp.second;
        }
    printf("%s\n",ans);
    return 0;
}
