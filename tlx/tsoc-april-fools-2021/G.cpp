#include <bits/stdc++.h>
using namespace std;

int main() {
  // puts("0");
  // puts("7331");
  // puts("83317331");
  // puts("043183317331");
  // puts("3431043183317331");
  // puts("74313431043183317331");
  // puts("253174313431043183317331");
  // puts("9531");

  // puts("0");
  // return 0;

  // pair<int,int> now = {15, 16};
  time_t t = time(0);
  tm* n = gmtime(&t);
  pair<int,int> now = {n->tm_hour, n->tm_min};

  stringstream ans;

  vector<pair<int,int>> times;
  // times.push_back(now);
  for (int i = 20; i > 0; --i) {
    now.second -= i;
    if (now.second < 0) {
      now.second += 60;
      now.first--;
    }
    times.push_back(now);
  }
  reverse(times.begin(), times.end());
  for (auto p : times) {
    ans << std::setfill('0') << std::setw(2) << p.first;
    ans << std::setfill('0') << std::setw(2) << p.second;
  }
  string s = ans.str();
  reverse(s.begin(), s.end());
  cout << s << endl;
}