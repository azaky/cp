#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int kasus,vertex;
vector<int> edge[1001];
set<string> kode;

string dfs(int x,int parent) {
    string hasil = "";
    vector<string> mau;
    for (int i=0;i<edge[x].size();++i) {
        if (edge[x][i] == parent) continue;
        mau.push_back("0"+dfs(edge[x][i],x)+"1");
    }
    
    sort(mau.begin(),mau.end());
    for (int i=0;i<mau.size();++i) hasil += mau[i];
    
    return hasil;
}

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d",&vertex);
        for (int i=1;i<=vertex;++i) edge[i].clear();
        
        kode.clear();
        for (int i=1,j,k;i<vertex;++i) scanf("%d %d",&j,&k),edge[j].push_back(k),edge[k].push_back(j);
        
        for (int i=1;i<=vertex;++i) {
            string hasil = dfs(i,0);
            kode.insert(hasil);
        }
        
        printf("Case #%d: %d\n",l,(int)kode.size());
    }
    return 0;
}
