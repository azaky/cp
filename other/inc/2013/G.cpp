/* DELAPAN.3gp */
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of DELAPAN.3gp's template -------------- */

int ntc, n, nd, k;
char s[200200];

int main(){
	scanf("%d",&ntc);
    FOR(itc,1,ntc){
        scanf("%d%s",&k,s);
        n = strlen(s);
        nd = 0;
        map <char,int> seen;
        REP(i,n){
            if (!seen[s[i]]) nd++;
            seen[s[i]] = 1;
        }
        k = nd-k;
        if (k == 0){
            printf("Case #%d: 0\n",itc);
            continue;
        }
        REP(i,n) s[i+n] = s[i];
        int a = 0, b = 0, ans = 0;
        set<char> member;
        map<char,int> salvian;
        member.insert(s[0]);
        salvian[s[0]] = 1;
        while (a < n){
//            printf("mulai: a = %d, b = %d\n",a,b);
//            FORIT(it,member) printf("[%c]",*it); puts("");
            //ngejambrengin
            while (SZ(member) < k){
                b++;
                member.insert(s[b]);
                salvian[s[b]]++;
            }
            while (EXIST(s[b+1],member)){
                b++;
                member.insert(s[b]);
                salvian[s[b]]++;
            }
//            FORIT(it,member) printf("[%c]",*it); puts("");
            MX(ans,b-a+1);
//            printf("[%d..%d]\n",a,b);
            char toDel = s[a];
            while (s[a] == toDel && a < n){
                salvian[s[a]]--;
                a++;
            }
            if (salvian[toDel] == 0){
                member.erase(toDel);
            }
        }
        printf("Case #%d: %d\n",itc,min(n,ans));
    }
	
	return 0;
}
