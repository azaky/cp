#include <bits/stdc++.h>
using namespace std;

#define sqr(a) ((a)*(a))

int iline = 0;
vector<int> fgetline(ifstream& f) {
  iline++;
  char buffer[1024];
  f.getline(buffer, 1024);
  stringstream ss(buffer);
  vector<int> res;
  while (ss.good()) {
    int x;
    if (ss >> x) {
      res.push_back(x);
    }
  }
  return res;
}

#define MAXN 1000100

int p[MAXN];
vector<string> pi[MAXN];
bool used[MAXN];

int main(int argc, char** argv) {
  if (argc != 3) {
    fprintf(stderr, "Need exactly two args: ./scorer <input> <output>");
    exit(1);
  }

  ifstream fin(argv[1]);
  ifstream fout(argv[2]);

  int m, t[5];
  fin >> m >> t[2] >> t[3] >> t[4];
  for (int i = 0; i < m; ++i) {
    fin >> p[i];
    for (int j = 0; j < p[i]; ++j) {
      string buffer;
      fin >> buffer;
      pi[i].push_back(buffer);
    }
  }

  long long score = 0;
  int nans = fgetline(fout)[0];
  for (int i = 0; i < nans; ++i) {
    vector<int> line = fgetline(fout);
    if (!line.size()) {
      fprintf(stderr, "Error line %d: empty line\n", iline);
      exit(1);
    }
    int l = line[0];
    vector<int> q(line.begin()+1, line.end());
    
    t[l]--;
    if (t[l] < 0) {
      fprintf(stderr, "Error line %d: L = %d exceeded the number T_L = %d\n", iline, l, t[l]);
      exit(1);
    }
    if (q.size() != l) {
      fprintf(stderr, "Error line %d: Number of pizza = %d doesn't match number of people = %d\n", q.size(), l);
      exit(1);
    }

    set<string> ingredients;
    for (int qi : q) {
      if (qi < 0 || qi >= m) {
        fprintf(stderr, "Error line %d: Pizza %d index out of bounds\n", iline, qi);
        exit(1);
      }
      if (used[qi]) {
        fprintf(stderr, "Error line %d: Pizza %d already used\n", iline, qi);
        exit(1);
      }
      used[qi] = 1;
      for (string ing : pi[qi]) {
        ingredients.insert(ing);
      }
    }
    score += sqr((long long)ingredients.size());
  }

  printf("%lld\n", score);
}