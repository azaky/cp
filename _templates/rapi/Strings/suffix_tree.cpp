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

  Node(int begin, int end, int depth, Node* parent) {
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

int traverseLCS(Node* node, int i1, int i2) {
  if (node->begin <= i1 && i1 < node->end) {
    return 1;
  }
  if (node->begin <= i2 && i2 < node->end) {
    return 2;
  }

  int mask = 0;
  for (int f = 0; f < ALPHABET.length(); ++f) {
    if (node->children[f] != NULL) {
      mask |= traverseLCS(node->children[f], i1, i2);
    }
  }
  if (mask == 3) {
    int curLength = node->depth + node->end - node->begin;
    if (lcsLength < curLength) {
      lcsLength = curLength;
      lcsNode = node;
    }
  }

  return mask;
}

string longestCommonSubstring(const string &s1, const string& s2) {
  string s = s1 + '\1' + s2 + '\2';
  Node* tree = buildSuffixTree(s);
  tree->print();
  lcsLength = 0;
  lcsNode = NULL;
  traverseLCS(tree, s1.length(), s1.length() + s2.length() + 1);
  if (lcsNode == NULL) {
    return "";
  } else {
    string lcs;
    lcs.resize(lcsLength);
    int pos = lcsLength;
    while (lcsNode != NULL) {
      int offset = pos - lcsNode->end;
      for (int i = lcsNode->begin; i < lcsNode->end; ++i) {
        lcs[offset + i] = s[i];
      }
      pos -= (lcsNode->end - lcsNode->begin);
      lcsNode = lcsNode->parent;
    }
    return lcs;
  }
}

int main() {
  // string s;
  // cin >> s;
  // buildSuffixTree(s)->print();
  string s1 = "banana";
  string s2 = "ananab";
  cout << longestCommonSubstring(s1, s2) << endl;
}
