#include "roads.h"

#include <bits/stdc++.h>
using namespace std;

vector<long long> subtask1(int N, vector<int> U, vector<int> V, vector<int> W) {
  sort(W.rbegin(), W.rend());
  vector<long long> ans(N, 0);
  long long sum = 0;
  ans[N-1] = 0;
  for (int i = N-1; i >= 0; --i) {
    sum += W[i];
    ans[i] = sum;
  }
  return ans;
}

vector<long long> subtask2(int N, vector<int> U, vector<int> V, vector<int> W) {
  // k = 0, all roads
  // k = 1, dp
  // k >= 2, no roads
  long long sum = 0;
  for (int i = 0; i < N-1; ++i) {
    sum += W[i];
  }
  vector<long long> ans(N, 0);
  ans[0] = sum;

  vector<long long> dp(N, 0);
  dp[0] = 0;
  dp[1] = W[0];
  ans[1] = sum - W[0];
  for (int i = 2; i < N; ++i) {
    dp[i] = max(dp[i-1], dp[i-2] + W[i-1]);
    ans[1] = min(ans[1], sum - dp[i]);
    // printf("dp[%d] = %lld\n", i, dp[i]);
  }

  return ans;
}

vector<long long> minimum_closure_costs(int N, vector<int> U, vector<int> V, vector<int> W) {
  bool is_subtask1 = true;
  for (int i = 0; i < N; ++i) {
    if (U[i] != 0) is_subtask1 = false;
  }
  if (is_subtask1) {
    return subtask1(N, U, V, W);
  }
  bool is_subtask2 = true;
  for (int i = 0; i < N-1; ++i) {
    if (U[i] != i || V[i] != i+1) is_subtask2 = false;
  }
  if (is_subtask2) {
    return subtask2(N, U, V, W);
  }

  return vector<long long>(N, 0);
}
