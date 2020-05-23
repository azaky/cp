#include <cstdio>

using namespace std;

int a,b,c;

int main(){
	while (1){
		scanf("%d%d%d",&a,&b,&c);
		if (a==0 && b==0 && c==0) break;
		if (a+c==b+b) printf("AP %d\n",c+c-b);
		if (a*c==b*b) printf("GP %d\n",c*c/b);
	}
	return 0;
}
