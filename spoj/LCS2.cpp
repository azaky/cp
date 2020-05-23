#include <bits/stdc++.h>
using namespace std;

/** Suffix Tree Ukkonen's algorithm **/
/* Complexity: O(N) (Warning: large multiplier) */

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz0123456789\1\2";
const int NALPHABET = 38;

struct Node {
  int begin, end, depth;
  Node* parent;
  Node** children;
  Node* suffixLink;
  static int nnode;

  Node(int begin, int end, int depth, Node* parent) {
    nnode++;
    this->begin = begin;
    this->end = end;
    this->depth = depth;
    this->parent = parent;
    this->children = new Node*[NALPHABET];
    for (int i = 0; i < NALPHABET; ++i) {
      this->children[i] = NULL;
    }
  }

  ~Node() {
    delete[] children;
  }

  void printTab(int times) {
    for (int i = 0; i < times; ++i) {
      putchar('\t');
    }
  }

  void print(int level = 0) {
    printTab(level);
    printf("(%d..%d, %d)\n", begin, end, depth);
    for (int i = 0; i < NALPHABET; ++i) {
      if (this->children[i] != NULL) {
        printTab(level);
        printf("%c:\n", ALPHABET[i]);
        this->children[i]->print(level + 1);
      }
    }
  }
};

Node* buildSuffixTree(string s) {
  int n = s.length();
  char* a = new char[n];
  for (int i = 0; i < n; ++i) {
    a[i] = (char) ALPHABET.find(s[i]);
  }

  Node* root = new Node(0, 0, 0, NULL);
  Node* node = root;
  for (int i = 0, tail = 0; i < n; ++i, ++tail) {
    Node* last = NULL;
    while (tail >= 0) {
      Node* ch = node->children[a[i - tail]];
      while (ch != NULL && tail >= ch->end - ch->begin) {
        tail -= (ch->end - ch->begin);
        node = ch;
        ch = ch->children[a[i - tail]];
      }

      if (ch == NULL) {
        node->children[a[i]] = new Node(i, n, node->depth + node->end - node->begin, node);
        if (last != NULL) {
          last->suffixLink = node;
        }
        last = NULL;
      } else {
        char t = a[ch->begin + tail];
        if (t == a[i]) {
          if (last != NULL) {
            last->suffixLink = node;
          }
          break;
        } else {
          Node* splitNode = new Node(ch->begin, ch->begin + tail, node->depth + node->end - node->begin, node);
          splitNode->children[a[i]] = new Node(i, n, ch->depth + tail, splitNode);
          splitNode->children[t] = ch;
          ch->begin += tail;
          ch->depth += tail;
          ch->parent = splitNode;
          node->children[a[i - tail]] = splitNode;
          if (last != NULL) {
            last->suffixLink = splitNode;
          }
          last = splitNode;
        }
      }
      if (node == root) {
        --tail;
      } else {
        node = node->suffixLink;
      }
    }
  }
  delete[] a;

  return root;
}



/* Example: longest common substring */
int lcsLength;
Node* lcsNode;

int traverseLCS(Node* node, const vector<int>& stops, const int target) {
  for (int i = 0; i < stops.size(); ++i) {
    if (node->begin <= stops[i] && stops[i] < node->end) {
      return 1 << i;
    }
  }

  int mask = 0;
  for (int f = 0; f < ALPHABET.length(); ++f) {
    if (node->children[f] != NULL) {
      mask |= traverseLCS(node->children[f], stops, target);
    }
  }
  if (mask == target) {
    int curLength = node->depth + node->end - node->begin;
    if (lcsLength < curLength) {
      lcsLength = curLength;
      lcsNode = node;
    }
  }

  return mask;
}

int longestCommonSubstring(const vector<string> &ss) {
  int totalN = 0;
  int n = ss.size();
  for (int i = 0; i < n; ++i) {
    totalN += ss[i].length() + 1;
  }

  string s;
  s.resize(totalN);
  int offset = 0;
  vector<int> stops;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < ss[i].length(); ++j) {
      s[offset + j] = ss[i][j];
    }
    offset += ss[i].length() + 1;
    s[offset - 1] = '0' + i;
    stops.push_back(offset - 1);
  }

  Node* tree = buildSuffixTree(s);
  lcsLength = 0;
  lcsNode = NULL;
  traverseLCS(tree, stops, (1 << n) - 1);
  delete tree;
  return lcsLength;
}

int Node::nnode = 0;
char buffer[100100];

int main() {
  vector<string> ss;
  while (scanf("%s", buffer) == 1) {
    ss.push_back(buffer);
  }

  printf("%d\n", longestCommonSubstring(ss));

  return 0;
}
