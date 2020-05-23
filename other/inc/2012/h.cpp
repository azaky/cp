#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MAX(a,b) a = max(a,b)

using namespace std;

int nilai[20][20];
bool sudah[1<<15];
int dp[1<<15];

int proses(int bitmask, int total) {
    if (sudah[bitmask]) return dp[bitmask];
    sudah[bitmask] = true;
    
    int angka[20];
    int temu = 0;
    for (int i=0;i<15;++i) if (bitmask & (1<<i)) {
        angka[temu++] = i;
    }
    
    //cout<<total<<" "<<temu<<endl;
    
    if (total == 3) {
        dp[bitmask] = nilai[angka[0]][angka[1]] + nilai[angka[0]][angka[2]] + nilai[angka[1]][angka[2]];
    } else {
        for (int i=0;i<total;++i) {
            for (int j=i+1;j<total;++j) {
                for (int k=j+1;k<total;++k) {
                    int best = min(nilai[angka[i]][angka[j]] + nilai[angka[i]][angka[k]] + nilai[angka[j]][angka[k]],
                                   proses(bitmask - ((1<<angka[i])+(1<<angka[j])+(1<<angka[k])),total-3));
                    MAX(dp[bitmask],best);
                }
            }
        }
    }
    
    return dp[bitmask];
}

int main() {
    int kasus,banyak;
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d",&banyak);
        //banyak *= 3;
        for (int i=0;i<3*banyak;++i) {
            for (int j=0;j<3*banyak;++j) {
                scanf("%d",&nilai[i][j]);
            }
        }
        
        memset(sudah,0,sizeof(sudah));
        memset(dp,0,sizeof(dp));
        
        int jawab = proses((1<<(3*banyak))-1,3*banyak);
        printf("Case #%d: %d\n",l,jawab);
    }
    return 0;
}
