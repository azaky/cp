#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime	printf("Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

//abbreviations
typedef long long LL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LLD "%I64d"

//prefefined macros
#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPD(i,n) for (int i = n-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define ALL(a) (a).begin(),(a).end()
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())

/* -------------- end of azaky's template -------------- */

int n, m, k;
vector<pair<int,PII> > X, Y;
vector<PII> usedX, usedY;

int findX(int pos, int L){
	int last = 0, total = 0, xb, xe;
	REP(i,(int)X.size()){
		if (X[i].fi != pos) continue;
		xb = min(L,X[i].se.fi);
		xe = min(L,X[i].se.se);
		total += max(0,xb-last);
		last = max(last,xe);
	}
	total += L - last;
	return total;
}

int findY(int pos, int L){
	int last = 0, total = 0, yb, ye;
	REP(i,(int)Y.size()){
		if (Y[i].fi != pos) continue;
		yb = min(L,Y[i].se.fi);
		ye = min(L,Y[i].se.se);
		total += max(0,yb-last);
		last = max(last,ye);
	}
	total += L - last;
	return total;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	REP(i,k){
		int xb, yb, xe, ye;
		scanf("%d%d%d%d",&xb,&yb,&xe,&ye);
		if (xb == xe){
			if (yb > ye) swap(yb,ye);
			X.pb(mp(xb,mp(yb,ye)));
		}
		else {
			if (xb > xe) swap(xb,xe);
			Y.pb(mp(yb,mp(xb,xe)));
		}
	}
	sort(ALL(X)); sort(ALL(Y));
	if (X.size() != 0){
		int last = 0, now = X[0].fi, total = 0;
		REP(i,(int)X.size()){
			if (X[i].fi != now){
				total += m - last;
				usedX.pb(mp(now,total));
				last = total = 0;
				now = X[i].fi;
			}
			total += max(0,X[i].se.fi-last);
			last = max(last,X[i].se.se);
		}
		total += m - last;
		usedX.pb(mp(now,total));
	}
	if (Y.size() != 0){
		int last = 0, now = Y[0].fi, total = 0;
		REP(i,(int)Y.size()){
			if (Y[i].fi != now){
				total += n - last;
				usedY.pb(mp(now,total));
				last = total = 0;
				now = Y[i].fi;
			}
			total += max(0,Y[i].se.fi-last);
			last = max(last,Y[i].se.se);
		}
		total += n - last;
		usedY.pb(mp(now,total));
	}
	int Grundy = 0;
	if ((n-1-(int)usedX.size()) % 2 != 0) Grundy = Grundy ^ m;
	if ((m-1-(int)usedY.size()) % 2 != 0) Grundy = Grundy ^ n;
	REP(i,(int)usedX.size()) Grundy = Grundy ^ usedX[i].se;
	REP(i,(int)usedY.size()) Grundy = Grundy ^ usedY[i].se;
	
	/*
	REP(i,(int)usedX.size()){
		printf("X : %d %d\n",usedX[i].fi,usedX[i].se);
	}
	REP(i,(int)usedY.size()){
		printf("Y : %d %d\n",usedY[i].fi,usedY[i].se);
	}
	*/
	
	//printf("Grundy = %d\n",Grundy);
	
	
	if (Grundy == 0){
		puts("SECOND");
		return 0;
	}
	
	puts("FIRST");
	
	//puts("BOOM");
	if ((int)usedX.size() < n-1){
		if (usedX.empty()){
			usedX.pb(mp(1,m));
		}
		else FOR(i,1,n-1) if (usedX[i-1].fi != i){
			usedX.pb(mp(i,m));
			break;
		}
	}
	//puts("BOOM");
	REP(i,(int)usedX.size()) if ((Grundy ^ usedX[i].se) <= usedX[i].se){
		int target = usedX[i].se - (Grundy ^ usedX[i].se);
		//printf("%d\n",target);
		int l = 0, r = m;
		while (l < r){
			//printf("%d %d\n",l,r);
			int mid = (l+r) / 2;
			int d = findX(usedX[i].fi,mid);
			if (d == target){
				l = r = mid; break;
			}
			if (d < target){
				l = mid + 1;
			}
			if (d > target){
				r = mid - 1;
			}
		}
		printf("%d 0 %d %d\n",usedX[i].fi,usedX[i].fi,l);
		return 0;
	}
	
	//puts("BOOM");
	if ((int)usedY.size() < m-1){
		if (usedY.empty()){
			usedY.pb(mp(1,n));
		}
		else FOR(i,1,m-1) if (usedY[i-1].fi != i){
			usedY.pb(mp(i,n));
			break;
		}
	}
	REP(i,(int)usedY.size()) if ((Grundy ^ usedY[i].se) <= usedY[i].se){
		int target = usedY[i].se - (Grundy ^ usedY[i].se);
		int l = 0, r = n;
		while (l < r){
			int mid = (l+r) / 2;
			int d = findY(usedY[i].fi,mid);
			if (d == target){
				l = r = mid; break;
			}
			if (d < target){
				l = mid + 1;
			}
			if (d > target){
				r = mid - 1;
			}
		}
		printf("0 %d %d %d\n",usedY[i].fi,l,usedY[i].fi);
		return 0;
	}
			
	
	return 0;
}
