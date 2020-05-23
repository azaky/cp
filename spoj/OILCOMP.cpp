#include <stdio.h>
using namespace std;

int main(){
	scanf("%d",&ntc);
	for (int itc = 1; itc <= ntc; ++itc){
		scanf("%d%d",&w,&h);
		for (int i=0; i<h; ++i) for (int j=0; j<w; ++j) scanf("%d",&a[i][j]);
		
