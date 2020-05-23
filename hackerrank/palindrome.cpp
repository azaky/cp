#include <bits/stdc++.h>
using namespace std;

#define MAXN 1100
#define MOD 1000000007

int ntc, n;
char s[MAXN], a[MAXN];
int idx[MAXN];
long long dp[MAXN][MAXN][2][2];

int main() {
    // dp[l][r][udahl][udahr]
    scanf("%d", &ntc);
    for (int itc = 0; itc < ntc; ++itc) {
        scanf("%d", &n);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            int len = strlen(s);
            for (int j = 0; j < len; ++j) {
                m++;
                a[m] = s[j];
                idx[m] = i;
            }
        }
        
        memset(dp, 0, sizeof(dp));
        // len = 1 and 0
        for (int i = 0; i <= m; ++i) {
            dp[i][i][1][1] = 1; // the char itself
            dp[i][i][0][0] = 1; // empty string
            dp[i][i][0][1] = 0;
            dp[i][i][1][0] = 0;
            dp[i + 1][i][1][1] = 0;
            dp[i + 1][i][0][0] = 1; // empty string
            dp[i + 1][i][0][1] = 0;
            dp[i + 1][i][1][0] = 0;
        }
        for (int len = 1; len < m; ++len) {
            for (int l = 1; l + len <= m; ++l) {
                int r = l + len;

                // if within same region
                if (idx[l] == idx[r]) {
                    dp[l][r][0][1] = dp[l][r][1][0] = 0;
                    // not using any of the chars
                    dp[l][r][1][1] = dp[l + 1][r][1][1] + dp[l][r - 1][1][1] - dp[l + 1][r - 1][1][1];
                    dp[l][r][0][0] = 1; // always the empty chars
                    // using both
                    if (a[l] == a[r]) {
                        dp[l][r][1][1] += dp[l + 1][r - 1][1][1] + dp[l + 1][r - 1][0][0];
                    }
                } else {
                    // not using left char
                    if (idx[l] != idx[l + 1]) {
                        if (idx[l + 1] != idx[r]) {
                            dp[l][r][0][0] += dp[l + 1][r][1][0];
                            dp[l][r][0][1] += dp[l + 1][r][1][1];
                        } else {
                            dp[l][r][0][0] += dp[l + 1][r][0][0];
                            dp[l][r][0][1] += dp[l + 1][r][1][1];
                        }
                    } else {
                        dp[l][r][0][0] += dp[l + 1][r][0][0];
                        dp[l][r][0][1] += dp[l + 1][r][0][1];
                        dp[l][r][1][0] += dp[l + 1][r][1][0];
                        dp[l][r][1][1] += dp[l + 1][r][1][1];
                    }
                    // not using right char
                    if (idx[r] != idx[r - 1]) {
                        if (idx[l] != idx[r - 1]) {
                            dp[l][r][0][0] += dp[l][r - 1][0][1];
                            dp[l][r][1][0] += dp[l][r - 1][1][1];
                        } else {
                            dp[l][r][0][0] += dp[l][r - 1][0][0];
                            dp[l][r][1][0] += dp[l][r - 1][1][1];
                        }
                    } else {
                        dp[l][r][0][0] += dp[l][r - 1][0][0];
                        dp[l][r][0][1] += dp[l][r - 1][0][1];
                        dp[l][r][1][0] += dp[l][r - 1][1][0];
                        dp[l][r][1][1] += dp[l][r - 1][1][1];
                    }
                    // using both
                    if (a[l] == a[r]) {
                        dp[l][r][1][1] += dp[l + 1][r - 1][1][1];
                        if (idx[l] == idx[l + 1]) {
                            dp[l][r][1][1] += dp[l + 1][r - 1][0][1];
                            if (idx[l + 1] == idx[r - 1]) {
                                dp[l][r][1][1] += dp[l + 1][r - 1][0][0];
                            }
                        }
                        if (idx[r] == idx[r - 1]) {
                            dp[l][r][1][1] += dp[l + 1][r - 1][1][0];
                            if (idx[l + 1] == idx[r - 1]) {
                                dp[l][r][1][1] += dp[l + 1][r - 1][0][0];
                            }
                        }
                        if (idx[l] == idx[l + 1] && idx[r] == idx[r - 1]) {
                            dp[l][r][1][1] += dp[l + 1][r - 1][0][0];
                        }
                    }
                    // now the double-counting!

                    if (idx[l] == idx[l + 1] && idx[r] == idx[r - 1]) {
                        dp[l][r][0][0] -= dp[l + 1][r - 1][0][0];
                        dp[l][r][0][1] -= dp[l + 1][r - 1][0][1];
                        dp[l][r][1][0] -= dp[l + 1][r - 1][1][0];
                        dp[l][r][1][1] -= dp[l + 1][r - 1][1][1];
                    }
                    if (idx[l] == idx[l + 1] && idx[r] != idx[r - 1]) {
                        if (idx[l] == idx[r - 1]) {
                            dp[l][r][0][0] -= dp[l + 1][r - 1][0][0];
                            // dp[l][r][0][1] -= dp[l + 1][r - 1][0][1];
                            dp[l][r][1][0] -= dp[l + 1][r - 1][1][1];
                        } else {
                            dp[l][r][0][0] -= dp[l + 1][r - 1][0][1];
                            // dp[l][r][0][1] -= dp[l + 1][r - 1][0][1];
                            dp[l][r][1][0] -= dp[l + 1][r - 1][1][1];
                        }
                    }
                    if (idx[l] != idx[l + 1] && idx[r] == idx[r - 1]) {
                        if (idx[l + 1] == idx[r]) {
                            dp[l][r][0][0] -= dp[l + 1][r - 1][0][0];
                            dp[l][r][0][1] -= dp[l + 1][r - 1][1][1];
                            // dp[l][r][1][0] -= dp[l + 1][r - 1][1][0];
                        } else {
                            dp[l][r][0][0] -= dp[l + 1][r - 1][1][0];
                            dp[l][r][0][1] -= dp[l + 1][r - 1][1][1];
                            // dp[l][r][1][0] -= dp[l + 1][r - 1][1][0];
                        }
                    }
                    if (idx[l] != idx[l + 1] && idx[r] != idx[r - 1]) {
                        if (idx[l + 1] == idx[r]) {
                            dp[l][r][0][0] -= 1;
                        } else {
                            dp[l][r][0][0] -= dp[l + 1][r - 1][1][1];
                        }
                    }

                }
                for (int il = 0; il < 2; ++il) {
                    for (int ir = 0; ir < 2; ++ir) {
                        dp[l][r][il][ir] %= MOD;
                        dp[l][r][il][ir] += MOD;
                        dp[l][r][il][ir] %= MOD;
                        // printf("dp[");
                        // for (int i = l; i <= r; ++i) putchar(a[i]);
                        // printf("][%d][%d] = %lld\n", il, ir, dp[l][r][il][ir]);
                    }
                }
            }
        }
        printf("%lld\n", dp[1][m][1][1]);
    }
    return 0;
}
