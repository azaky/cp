#include <queue>
#include <iostream>
#include <string>

using namespace std;

int n,last,len;
string s,ans;
priority_queue <pair<int,int> > pq;
pair<int,int> temp;

int main(){
    cin >> s; n = s.length();
    for (int i=0; i<n; i++) pq.push(make_pair((int)s[i],-i));
    len = 0; last = n;
    for (int i=0; i<n; i++){
        temp = pq.top(); pq.pop();
        if (temp.second > last) continue;
        ans.append(1,(char)temp.first);
        last = temp.second;
        }
    cout << ans << endl;
    return 0;
}
