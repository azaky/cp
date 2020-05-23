#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>

using namespace std;

int kasus,vertex;
string dapat[1001],pohon[1001];
vector<int> edge[1001];
vector<pair<string,int> > anak[1001],buat[1001];
set<string> kode;

string dfs(int x,int parent) {
    //if (sudah[x][parent]) return dp[x][parent];
    
    //sudah[x][parent] = true;
    //dp[x][parent] = "";
  
    pohon[x] = "";
    for (int i=0;i<edge[x].size();++i) {
        if (edge[x][i] == parent) continue;
        anak[x].push_back(make_pair("0"+dfs(edge[x][i],x)+"1",edge[x][i]));
    }
    
    sort(anak[x].begin(),anak[x].end());
    //for (int i=0;i<mau.size();++i) dp[x][parent] += mau[i];
    for (int i=0;i<anak[x].size();++i) pohon[x] += anak[x][i].first;
    
    return pohon[x];
    //return dp[x][parent];
}

void create_code(int x,int parent,string atas) {
    buat[x].clear();
    dapat[x] = "";
    bool flag = false;
    
    for (int i=0;i<anak[x].size();++i) {
        if (!flag && atas < anak[x][i].first) {
            flag = true;
            buat[x].push_back(make_pair(atas,parent));
            dapat[x] += atas;
        } 
        buat[x].push_back(anak[x][i]);
        dapat[x] += anak[x][i].first;            
    }
    
    if (!flag) {
        flag = true;
        buat[x].push_back(make_pair(atas,parent));
        dapat[x] += atas;    
    }
    
    //cout<<x<<" : "<<dapat[x]<<endl;
    
    if (kode.find(dapat[x]) == kode.end()) {
        kode.insert(dapat[x]);
        string depan = "0";
        string belakang = "";
        for (int i=1;i<buat[x].size();++i) belakang += buat[x][i].first; 
        belakang += "1";
        
        for (int i=0;i<buat[x].size();++i) {
            if (buat[x][i].second != parent) create_code(buat[x][i].second,x,depan+belakang);
            if (i+1<buat[x].size()) belakang = belakang.substr(buat[x][i+1].first.length());
            depan += buat[x][i].first;
        }
    }
}

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d",&vertex);
        for (int i=1;i<=vertex;++i) edge[i].clear(),anak[i].clear();
        
        kode.clear();
        for (int i=1,j,k;i<vertex;++i) scanf("%d %d",&j,&k),edge[j].push_back(k),edge[k].push_back(j);
        
        /*memset(sudah,0,sizeof(sudah));
        for (int i=1;i<=vertex;++i) {
            string hasil = dfs(1,0);
            kode.insert(hasil);
        }*/
        
        //cout<<dfs(1,0)<<endl;
        dfs(1,0);
        create_code(1,0,"");
        
        printf("Case #%d: %d\n",l,(int)kode.size());
    }
    return 0;
}
