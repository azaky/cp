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

struct Node {
  Node** children;
  bool leaf;
  Node* parent;
  char charToParent;
  Node* suffLink;
  Node* dictSuffLink;
  Node** go;
  int value;

  Node() {
    children = new Node*[NALPHABET];
    go = new Node*[NALPHABET];
    for (int i = 0; i < NALPHABET; ++i) {
      children[i] = go[i] = NULL;
    }
    parent = suffLink = dictSuffLink = NULL;
    leaf = false;
    value = -1;
  }
};

Node* createRoot() {
  Node* node = new Node();
  node->suffLink = node;
  return node;
}

void addString(Node* node, const string& s, int idx) {
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
  node->value = idx;
}

Node* suffLink(Node* node);
Node* dictSuffLink(Node* node);
Node* go(Node* node, char ch);

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
      while (!n->leaf) {
        Node* temp = suffLink(n);
        if (temp == n) {
          break;
        } else {
          n = temp;
        }
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

#define MAXN 1100100
#define MAXM 10100
#define MAXL 111

int n, a[MAXN], m, len[MAXM];
char s[MAXN], w[MAXM][MAXL];

int main(){
  int ntc;

  OPEN("cenzura");
  scanf("%d", &ntc);
  FOR(itc, 1, ntc) {
    scanf("%d", &n);
    scanf("%s", s);
    REP(i, n) {
      scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    REP(i, m) {
      scanf("%s", w[i]);
      len[i] = strlen(w[i]);
    }
    Node* root = createRoot();
    REP(i, m) {
      addString(root, w[i], i);
    }
    Node* node = root;
    for (int i = 0; i < n; ++i) {
      node = go(node, s[i]);
      Node* tr = node;
      while (tr != root) {
        if (tr->leaf) {
          printf("at position %d: value = %d\n", i, tr->value);
        }
        tr = dictSuffLink(tr);
      }
    }
  }
  
  return 0;
}
