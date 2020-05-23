#include <cstdio>

using namespace std;

int n,a[111111],pos[111111];
bool ambigu;

int main(){
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		
		ambigu = true;		
		for (int i=0; i<n; ++i){
			scanf("%d",&a[i]);
			--a[i];
			pos[a[i]] = i;
		}
		for (int i=0; i<n; ++i)
			if (a[i]!=pos[i]) ambigu = false;
		
		if (ambigu) printf("ambiguous\n");
		else printf("not ambiguous\n");
	}
	return 0;
}
