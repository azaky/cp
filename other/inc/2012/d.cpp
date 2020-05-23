#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

typedef struct {
    int tunjuk[26];
    int masuk[4],lewat;
} data;

data kosong;
vector<data> trie;
pair<int,string> kata[10001];

bool cf(const pair<int,string> &a, const pair<int,string> &b) {
    if (a.first != b.first) return (a.first > b.first);
    return a.second < b.second;
}

int main() {
    memset(kosong.tunjuk,0,sizeof(kosong.tunjuk));
    kosong.lewat = 0;

    int kasus;
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        int masukan,minta;
        scanf("%d %d",&masukan,&minta);
        trie.clear();
        trie.push_back(kosong);
        int temu = 0;
        
        for (int i=1;i<=masukan;++i) {
            cin>>kata[i].second>>kata[i].first;
            int panjang = kata[i].second.length();
            
            int indeks = 0;
            for (int j=0;j<panjang;++j) {
                if (trie[indeks].tunjuk[kata[i].second[j]-'a'] == 0) {
                    trie[indeks].tunjuk[kata[i].second[j]-'a'] = ++temu;
                    trie.push_back(kosong);
                }
                indeks = trie[indeks].tunjuk[kata[i].second[j]-'a'];
                
                int k = trie[indeks].lewat-1;
                while ((k > -1) && (cf(kata[i],kata[trie[indeks].masuk[k]]))) {
                    if (k+1 < 4) trie[indeks].masuk[k+1] = trie[indeks].masuk[k];
                    --k;
                }
                
                if (k+1 < 4) trie[indeks].masuk[k+1] = i;
                if (trie[indeks].lewat < 4) ++trie[indeks].lewat;
            }
        }
        
        printf("Case #%d:\n",l);
        for (int i=0;i<minta;++i) {
            string mau;
            cin>>mau;
            int indeks = 0;
            
            bool flag = true;
            for (int j=0;j<mau.length() && flag;++j) {
                if (!trie[indeks].tunjuk[mau[j]-'a']) flag = false;
                indeks = trie[indeks].tunjuk[mau[j]-'a'];
            }
            
            cout<<"FIND "<<mau<<endl;
            if (flag) {
                string jawab[4];
                for (int j=0;j<trie[indeks].lewat;++j) jawab[j] = kata[trie[indeks].masuk[j]].second;
                sort(jawab,jawab+trie[indeks].lewat);
                
                for (int j=0;j<trie[indeks].lewat;++j) cout<<"> "<<jawab[j]<<endl;
            }
        }
        
        /*for (int i=1;i<=masukan;++i) cin>>kata[i].second>>kata[i].first;
        sort(kata+1,kata+masukan+1,cf);
        
        for (int i=1;i<=minta;++i) {
        
        }*/
    }
    return 0;
}
