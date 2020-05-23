#include <stdio.h>
#include <string.h>

#define MAXS 1000000
int w, n, _n, t[5005], l[MAXS];
char p[505][5005], _s[101][50005];
char* s[MAXS];
int i, j;

int main(){
	scanf("%d",&w);
	for(i=0; i < w; ++i) scanf("%s",p[i]);
	scanf("%d",&_n);
	n = 0;
	for(i=0; i < _n; ++i){
		scanf("%s",_s[i]);
		char * temp = strtok(_s[i],"-");
		while (temp != NULL){
			l[n] = strlen(temp);
			s[n++] = temp;
			temp = strtok(NULL,"-");
		}
	}
	for(i=0; i < w; ++i){
		//compute T
		int len = strlen(p[i]);
		int pos = 2, cnd = 0;
		t[0] = -1; t[1] = 0;
		while (pos < len){
			if (p[i][pos-1] == p[i][cnd]) t[pos++] = ++cnd;
			else if (cnd) cnd = t[cnd];
			else t[pos++] = 0;
		}
		int ans = 0;
		for(j=0; j < n; ++j){
			//KMP
			int hoho = -1;
			int m = 0, ii = 0;
			while (m+ii < l[j]){
				if (p[i][ii] == s[j][m+ii]){
					if (ii == len-1){
						hoho = m;
						break;
					}
					++ii;
				}
				else {
					m += ii - t[ii];
					if (t[ii] > -1) ii = t[ii]; else ii = 0;
				}
			}
			if (hoho != -1) ans++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
