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

/* -------------- end of azaky's template -------------- */

#define sejuta 1000000
#define MAXN 100100

int n, q;
pii courses[MAXN];
int nextCourse[sejuta + 5];
int parent[MAXN][30];

int main(){
  scanf("%d%d", &n, &q);
  REP(i, n) {
    scanf("%d%d", &courses[i].A, &courses[i].B);
  }

  RESET(nextCourse, -1);
  REP(i, n) {
    if (nextCourse[courses[i].A] == -1 || courses[nextCourse[courses[i].A]].B > courses[i].B) {
      nextCourse[courses[i].A] = i;
    }
  }
  FORD(t, sejuta, 1) {
    if (nextCourse[t] == -1 || (nextCourse[t + 1] != -1 && courses[nextCourse[t]].B > courses[nextCourse[t + 1]].B)) {
      nextCourse[t] = nextCourse[t + 1];
    }
  }

  REP(i, n) {
    parent[i][0] = nextCourse[courses[i].B + 1];
    // printf("parent[%d] = %d\n", i, parent[i]);
  }

  FOR(level, 1, 25) {
    REP(i, n) {
      int midParent = parent[i][level - 1];
      if (midParent != -1) {
        parent[i][level] = parent[midParent][level - 1];
      } else {
        parent[i][level] = -1;
      }
    }
  }

  REP(iq, q) {
    int start, end;
    scanf("%d%d", &start, &end);
    int node = nextCourse[start];
    if (node == -1 || courses[node].B > end) {
      puts("0");
    } else {
      int ans = 1;
      FORD(level, 25, 0) {
        if (parent[node][level] != -1 && courses[parent[node][level]].B <= end) {
          node = parent[node][level];
          // printf("now in %d\n", node);
          ans += 1 << level;
        }
      }
      printf("%d\n", ans);
    }
  }
  
  return 0;
}
