#include "spoj.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(void) {
	spoj_init();
	long long x,y;
	int n;
	fscanf(spoj_t_out,"%lld %lld",&x,&y);
	fscanf(spoj_p_out,"%d",&n);
	long long ans = 1, res = 7*x*x+y*y;
	for (int i=0; i<n; i++) ans*=2;
	
	if (ans!=res || x%2==0 || y%2==0) return SPOJ_RV_NEGATIVE;
		else return SPOJ_RV_POSITIVE;
}
