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

const int NALPHABET = 26;

int nodecount = 0;

struct Node {
  Node** children;
  bool leaf;
  Node* parent;
  char charToParent;
  Node* suffLink;
  Node* dictSuffLink;
  Node** go;
  int count;
  int value;

  Node() {
    children = new Node*[NALPHABET];
    go = new Node*[NALPHABET];
    for (int i = 0; i < NALPHABET; ++i) {
      children[i] = go[i] = NULL;
    }
    parent = suffLink = dictSuffLink = NULL;
    leaf = false;
    count = 0;
    value = nodecount++;
  }
};

Node* createRoot() {
  Node* node = new Node();
  node->suffLink = node;
  return node;
}

void addString(Node* node, const string& s) {
  for (int i = 0; i < s.length(); ++i) {
    int c = s[i] - 'a';
    if (node->children[c] == NULL) {
      Node* n = new Node();
      n->parent = node;
      n->charToParent = s[i];
      node->children[c] = n;
    }
    node = node->children[c];
  }
  node->leaf = true;
  node->count++;
}

Node* suffLink(Node* node);
Node* dictSuffLink(Node* node);
Node* go(Node* node, char ch);
int calc(Node* node);

Node* suffLink(Node* node) {
  if (node->suffLink == NULL) {
    if (node->parent->parent == NULL) {
      node->suffLink = node->parent;
    } else {
      node->suffLink = go(suffLink(node->parent), node->charToParent);
    }
  }
  return node->suffLink;
}

Node* dictSuffLink(Node* node) {
  if (node->dictSuffLink == NULL) {
    Node* n = suffLink(node);
    if (node == n) {
      node->dictSuffLink = node;
    } else {
      while (!n->leaf && n->parent != NULL) {
        n = dictSuffLink(n);
      }
      node->dictSuffLink = n;
    }
  }
  return node->dictSuffLink;
}

Node* go(Node* node, char ch) {
  int c = ch - 'a';
  if (node->go[c] == NULL) {
    if (node->children[c] != NULL) {
      node->go[c] = node->children[c];
    } else {
      node->go[c] = node->parent == NULL ? node : go(suffLink(node), ch);
    }
  }
  return node->go[c];
}

int calc(Node* node) {
  if (node->parent == NULL) {
    return 0;
  } else {
    return node->count + calc(dictSuffLink(node));
  }
}

int nq, n, t;
string s[300300];
char buffer[300300];

#define LOGN 20
struct Blocks {
  Node* root[LOGN];
  vector<int> block[LOGN];

  Blocks() {
    REP(i, LOGN) {
      root[i] = NULL;
    }
  }

  void insert(int x) {
    vector<int> cur(1, x);
    REP(i, LOGN) {
      if (SZ(block[i]) == SZ(cur)) {
        cur.insert(cur.end(), ALL(block[i]));
        block[i].clear();
        root[i] = createRoot();
      } else {
        block[i] = cur;
        root[i] = createRoot();
        FORIT(it, block[i]) {
          addString(root[i], s[*it]);
        }
        break;
      }
    }
  }

  ll calcc(const string& T) {
    ll ans = 0;
    REP(i, LOGN) {
      Node* node = root[i];
      if (node == NULL) continue;
      int localans = 0;
      REP(j, SZ(T)) {
        node = go(node, T[j]);
        localans += calc(node);
      }
      ans += localans;
    }
    return ans;
  } 
};

int main(){
  Blocks block1, block2;
  scanf("%d", &nq);
  REP(iq, nq) {
    scanf("%d%s", &t, buffer);
    s[iq] = buffer;
    if (t == 1) {
      block1.insert(iq);
    } else if (t == 2) {
      block2.insert(iq);
    } else {
      ll ans = block1.calcc(s[iq]) - block2.calcc(s[iq]);
      printf("%lld\n", ans);
      fflush(stdout);
    }
  }
  
  return 0;
}
