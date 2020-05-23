#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>

using namespace std;

long long total[101];
long long angka[101];

int main() {
    int kasus,banyak,pilih;
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d %d",&banyak,&pilih);
        for (int i=1;i<=banyak;++i) {
            cin>>angka[i];
        }
        sort(angka+1,angka+1+banyak);
        
        for (int i=1;i<=banyak;++i) total[i] = total[i-1] + angka[i];
        
        bool flag = false;
        for (int i=pilih;i<=banyak&&!flag;++i) {
            if (total[i-1]-total[i-pilih] > angka[i]) flag = true;
        }
        
        printf("Case #%d: ",l);
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
