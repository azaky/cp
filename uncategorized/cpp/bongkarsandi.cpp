#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
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
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}

/* -------------- end of azaky's template -------------- */

int sandi,x[6],step,totalstep,maxstep;
int dummy,a[6],ans[6],k,lastk,correct,lasti;
vector <int> digit,multi;

int ask(void){
	int k=0;
	//printf("? %d%d%d%d%d%d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
	//fflush(stdout);
	for (int i=0; i<6; ++i) k += a[i]==x[i] ? 1 : 0;
	++step;
	//printf("%d\n",k);
	//scanf("%d",&k);
	return k;
}

int main(){
for (int _sandi=0; _sandi<1000000; ++_sandi){
//scanf("%d",&sandi);
sandi = _sandi;
for (int i=5; i>=0; --i){
	x[i]=sandi%10;
	sandi/=10;
}

	//scanf("%d",&dummy);
	dummy = 6;
	
	if (dummy == 2)
		for (int i=0; i<100; ++i){
			printf("? %d%d\n",i/10,i%10);
			fflush(stdout);
			scanf("%d",&dummy);
			if (dummy==2){
				printf("! %d%d\n",i/10,i%10);
				fflush(stdout);
				return 0;
			}
		}
	dummy = 6; step = 0; correct = 0;
	digit.clear(); multi.clear();
	for (int i=0; i<9; ++i){
		a[0] = a[1] = a[2] = a[3] = a[4] = a[5] = i;
		k = ask();
		if (k){
			digit.push_back(i);
			multi.push_back(k);
		}
		dummy -= k;
		if (dummy==0) break;
	}
	if (dummy>0){
		digit.push_back(9);
		multi.push_back(dummy);
	}
	ans[0] = ans[1] = ans[2] = ans[3] = ans[4] = ans[5] = -1;
	for (int i=0; i<digit.size(); i+=2){
		if (i+1==digit.size()){
			for (int j=0; j<6; ++j)
				ans[j] = ans[j]<0 ? digit[i] : ans[j];
			break;
		}
		lastk = multi[i];
		lasti = -1;
		for (int j=0; j<6; ++j)
			if (ans[j]<0) lasti = j;
		if (lasti<0) break;
		a[0] = a[1] = a[2] = a[3] = a[4] = a[5] = digit[i];
		for (int j=0; j<6; ++j){
			if (j==lasti){
				ans[lasti] = multi[i] ? digit[i] : digit[i+1];
				break;
			}
			a[j] = digit[i+1];
			if (ans[j]>=0) continue;
			k = ask();
			if (k==6){
				for (int _j=0; _j<6; ++_j) ans[_j] = a[_j];
				break;
			}
			if (k!=lastk){
				++correct;
				if (k<lastk){
					ans[j] = digit[i];
					--multi[i];
				}
				else {
					ans[j] = digit[i+1];
					--multi[i+1];
				}
			}
			if (multi[i]+multi[i+1] == 0) break;
			lastk = k;
		}
	}
	//printf("! %d%d%d%d%d%d\n",ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]);
	//fflush(stdout);
	if (ans[0]==x[0]&&ans[1]==x[1]&&ans[2]==x[2]&&ans[3]==x[3]&&ans[4]==x[4]&&ans[5]==x[5]);
		else printf("INCORRECT %d%d%d%d%d%d\n",ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]);
	if (step > maxstep) maxstep = step;
	totalstep += step;
	//printf("%d steps taken.\n",step);
}
printf("Total steps required for all 1000000 cases is %d.\n",totalstep);
printf("The worst case takes %d steps.\n",maxstep);
GetTime
	return 0;
}
