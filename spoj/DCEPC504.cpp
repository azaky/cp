#include <cstdio>

using namespace std;

long long a,b;

int calc(long long k){
    int ret = 0;
    while (k>0){
		ret = (ret+(k%2))%2;
		k /= 2;
	}
	return ret;
	}

int main(){
    int kasus;
	scanf("%d",&kasus);
	while (kasus--){
		scanf("%lld%lld",&a,&b);
		if (calc(b-1)==0) printf("Male\n");
			else printf("Female\n");
	}
	return 0;
}
