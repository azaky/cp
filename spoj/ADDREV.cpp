#include <cstdio>

using namespace std;

int a,b,kasus;

int rev(int a){
	int ret = 0;
	while (a>0){
		ret = 10*ret + (a%10);
		a/=10;
	}
	return ret;
}

int main(){
	scanf("%d",&kasus);
	while (kasus--){
		scanf("%d%d",&a,&b);
		printf("%d\n",rev(rev(a)+rev(b)));
	}
	return 0;
}
