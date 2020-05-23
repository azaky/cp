#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MAX(a,b) a = max(a,b)

using namespace std;

bool sudah[201][5001],urus[201];
int dp[201][5001];
int efek[201],banyak,teman[201],nilai[201],berat[201],kasus,batas,pasang;

int proses(int nomor,int sisa) {
    if (nomor > banyak) return 0;
    if (sudah[nomor][sisa]) return dp[nomor][sisa];
    
    sudah[nomor][sisa] = true;
    MAX(dp[nomor][sisa],proses(nomor+1,sisa));
    if (urus[nomor]) {
        if (sisa >= berat[nomor]) MAX(dp[nomor][sisa],proses(nomor+1,sisa-berat[nomor])+nilai[nomor]);
        if (teman[nomor]) {
            if (sisa >= berat[teman[nomor]]) 
                MAX(dp[nomor][sisa],proses(nomor+1,sisa-berat[teman[nomor]])+nilai[teman[nomor]]);
            if (sisa >= berat[teman[nomor]]+berat[nomor]) 
                MAX(dp[nomor][sisa],proses(nomor+1,sisa-berat[teman[nomor]]-berat[nomor]) + nilai[nomor]+nilai[teman[nomor]]+efek[nomor]);
        }
    }
    return dp[nomor][sisa];
}

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d %d %d",&banyak,&batas,&pasang);
        for (int i=1;i<=banyak;++i) scanf("%d %d",&nilai[i],&berat[i]);
        
        memset(urus,1,sizeof(urus));
        memset(teman,0,sizeof(teman));
        for (int i=1,j,k,sem;i<=pasang;++i) {
            scanf("%d %d %d",&j,&k,&sem);
            if (j > k) swap(k,j);
            urus[k] = false;
            teman[j] = k;
            efek[j] = sem;
        }
        
        memset(sudah,0,sizeof(sudah));
        memset(dp,0,sizeof(dp));
        int jawab = proses(1,batas);
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
