//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG 
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of jonathanirvings' template v3.0.3 (BETA)

int t;
LL data[3][1005];
LL MOD = 1e9 + 9;
int c,s;

bool cek(int c,int s)
{
  REP(i,3) REP(j,c) if(data[i][j] < 0) return false;
  REP(i,c) REP(j,c) REP(k,c)
  {
    if (j * 2 == i + k) 
    {
      if (data[0][i] + data[1][j] + data[2][k] == s);
      else return false;
    }
  }
  return true;
}

void print()
{
  REP(i,3)
  {
    REP(j,c) printf("%lld",data[i][j]);
    puts("");
  }
  DEBUG;
}

LL bf(int c,int s)
{
  LL risan = 0;
  if (c == 1)
  {
    FORN(i,0,s) FORN(j,0,s) FORN(k,0,s)
    {
      if (i + j + k == s) ++risan;
    }
  } else 
  {
    FORN(i,0,s) FORN(j,0,s) FORN(k,0,s) FORN(l,0,s)
    {
      data[0][0] = i;
      data[0][1] = j;
      data[1][0] = k;
      data[1][1] = l;
      data[2][0] = s - data[0][0] - data[1][0];
      data[2][1] = s - data[0][1] - data[1][1];
      FOR(m,2,c)
      {
        data[0][m] = s - data[1][m-1] - data[2][m-2];
        data[2][m] = s - data[1][m-1] - data[0][m-2];
        data[1][m] = s - data[0][m] - data[2][m];
      }
      if (cek(c,s)) 
      {
        ++risan;
      }
    }
  }
  return risan;
}

LL coba(LL c,LL s)
{
  if (c == 1)
  {
    return ((s+1)*(s+2)/2)%MOD;
  }
  LL risan = 0;
  LL TWO = 500000005;
  LL SIX = 833333341;
  FORN(b,1,s/(c-1))
  {
    LL ret1 = (s+1 - (c-1)*b) % MOD;
    LL ret2 = ((s+1 - (c-2)*b)%MOD) * (( s+1 - ( c-1)*b)%MOD) % MOD;
    LL ret3 = ((s   - (c-1)*b)%MOD) * ((2*s+2 - (2*c-3)*b)%MOD) % MOD * TWO % MOD;
    LL ret4 = ((s   - (c-1)*b)%MOD) * ((2*s+1 - (2*c-2)*b)%MOD) % MOD * SIX % MOD;
    LL ret = ret1 * (ret2 - ret3 + ret4);
    risan = (risan + ret) % MOD;
  }
  risan = (risan * 2 + (((s+1)*(s+2)) % MOD) * (((2*s+3)*SIX) % MOD) ) % MOD;
  return (risan + MOD) % MOD;
}

int main()
{
  scanf("%d",&t);
  VALUE(bf(2,1));
  FORN(i,1,10) FORN(j,1,10)
  {
    //printf("%d %d %lld %lld\n",i,j,bf(i,j),coba(i,j));
    assert(bf(i,j) == coba(i,j));
  }
  //return 0;
  // vector<pair<int, int> > tcs;

  // for (int i = 0; i < t; ++i) {
  //   scanf("%d%d", &c, &s);
  //   tcs.push_back(make_pair(c, s));
  // }
  // for (int i = t - 1; i >= 0; --i) {
  //   printf("%d: %lld\n", i + 1, coba(tcs[i].first, tcs[i].second));
  // }
  TC(t)
  {
    fprintf(stderr,"%d\n",t);
    LL risan = 0;
    scanf("%d %d",&c,&s);
    printf("%lld\n",coba(c,s));
  }
  return 0;
}









