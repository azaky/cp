#include <cstdio>
#include <cstring>
#define MOD 11380

using namespace std;

int a,b,c,d,dp[12][12][12][33];

int aerolite(int l1,int l2,int l3,int d){
    //printf("%d %d %d %d\n",l1,l2,l3,d);
	if (dp[l1][l2][l3][d]>=0) return dp[l1][l2][l3][d];
	dp[l1][l2][l3][d] = 0;
	if (l1+l2+l3==d){
		dp[l1][l2][l3][d] = 1;
		return dp[l1][l2][l3][d];
	}
	if (l1+l2+l3<d || l1+l2+l3==0 || d==0)
		return dp[l1][l2][l3][d];
	int add, add1, add2, add3, add4;
	/*
	if (l3>0) add = aerolite(l1,l2,l3-1,d-1);
		else if (l2>0) add = aerolite(l1,l2-1,l3,d-1);
			else if (l1>0) add = aerolite(l1-1,l2,l3,d-1);
	dp[l1][l2][l3][d] = (dp[l1][l2][l3][d] + add)%MOD;
	*/
	for (int i1=0; i1<=l1; ++i1)
		for (int i2=0; i2<=l2; ++i2)
			for (int i3=0; i3<=l3; ++i3)
				for (int d0=0; d0<=d; ++d0){
					if (i1+i2+i3==0) continue;
					if (i3>0){
						add1 = aerolite(i1,i2,i3-1,d0-1);
						add2 = aerolite(i1,i2,i3-1,d-1);
					}
					else if (i2>0){
						add1 = aerolite(i1,i2-1,i3,d0-1);
						add2 = aerolite(i1,i2-1,i3,d-1);
					}
					else if (i1>0){
						add1 = aerolite(i1-1,i2,i3,d0-1);
						add2 = aerolite(i1-1,i2,i3,d-1);
					}
					add3 = aerolite(l1-i1,l2-i2,l3-i3,d0);
					add4 = aerolite(l1-i1,l2-i2,l3-i3,d);
					if (d0==d) dp[l1][l2][l3][d] = (dp[l1][l2][l3][d] + add1*add3)%MOD;
						else dp[l1][l2][l3][d] = (dp[l1][l2][l3][d] + add1*add4 + add2*add3)%MOD;
					}
	return dp[l1][l2][l3][d];
}

int main(){
	memset(dp,255,sizeof(dp));
	dp[0][0][0][0] = 1;
	for (int tc=0; tc<10; ++tc){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",aerolite(c,b,a,d));
	}
	return 0;
}
