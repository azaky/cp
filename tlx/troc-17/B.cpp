#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  puts((n/2 % 2) || (m/2 % 2) ? "No" : "Yes");
}