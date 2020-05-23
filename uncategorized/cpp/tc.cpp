#include <stdio.h>
using namespace std;

int main(){
	int n = 50;
	int k = 32;

		int aaa = 0, take[1000];
		for (int r = 0; r <= n; ++r){
			for (int g = 0; r + g <= n; ++g){
				int b = n - r - g;
				int hehe = 0;
				while (r + g + b > 0){
					if (r > 0){take[++hehe] = 1; r--;}
					if (g > 0){take[++hehe] = 2; g--;}
					if (b > 0){take[++hehe] = 3; b--;}
				}
				if (take[k] == 1) ++aaa;
			}
		}
		printf("JAWABAN = %d\n",aaa);	

	return 0;
}
