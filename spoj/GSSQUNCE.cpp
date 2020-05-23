#include <algorithm>
#include <cstdio>
using namespace std;

inline void inp( int &n ) 
 {
    n=0;
    int ch=getchar_unlocked();
    while( ch < '0' || ch > '9' ) ch=getchar_unlocked();

    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
  }

int tc,n,x,s,t,v[111111];

int main(){
	scanf("%d",&tc);
	while (tc--){
		inp(n);
		for (int i=0; i<n; ++i) inp(v[i]);
		sort(v,v+n);
		s = 0;
		for (int i=1; i<n-1; ++i)
			if (v[i]==v[i-1] && v[i]==v[i+1]) ++s;
		printf("%s\n",s || n==1 ? "NO" : "YES");
	}
	return 0;
}
