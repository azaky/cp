#include <cstdio>
#include <cstdlib>

using namespace std;

int n,m,k,mr,mc,ar,ac,br,bc;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0; i<k; ++i){
		scanf("%d%d%d%d%d%d",&mr,&mc,&ar,&ac,&br,&bc);
		if ((mr-ar)*(mr-br)<0 && (mc-ac)*(mc-bc)<0 && abs(mc-ac)==abs(mr-ar) && abs(mc-bc)==abs(mr-br)) printf("NO\n");
			else printf("YES\n");
		}
	return 0;
}
