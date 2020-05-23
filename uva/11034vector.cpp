#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
        int c, tc; scanf("%d",&c);
        for (tc = 1; tc <= c; tc++){
                int l, m;
                scanf("%d%d",&l,&m);
                
                vector<int> left, right;
                
                int i;
                for (i = 1; i <= m; ++i){
                        int l_mobil;
                        char posisi[10];
                        scanf("%d%s",&l_mobil,posisi);
                        if (!strcmp(posisi,"left")) left.push_back(l_mobil);
                        if (!strcmp(posisi,"right")) right.push_back(l_mobil);
                }
                
                int Moveleft = 0, Moveright = 0;
                
                reverse(left.begin(),left.end());
                for(; !left.empty(); ++Moveleft){
                        int space = 100*l;
                        while (!left.empty()){
                                if (space >= left.back()){
                                        space -= left.back();
									    left.pop_back();
                                }
                                else break;
                        }
                }
                reverse(right.begin(),right.end());
                for(; !right.empty(); ++Moveright){
                        int space = 100*l;
                        while (!right.empty()){
                                if (space >= right.back()){
                                        space -= right.back();
                                        right.pop_back();
                                }
                                else break;
                        }
                }
                printf("%d\n",2*Moveleft-1 > 2*Moveright ? 2*Moveleft-1 : 2*Moveright);
        }
        return 0;
}
