#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pair<pair<int,int>,int> getCoordinate(int num, int n) {
    // Determine M's coordinate.
    // Run backwards.
    int inv = n*n + 1 - num;
    int s = (int)(sqrt(inv));
    while (s * s > inv) s--;
    while (s * s < inv) s++;
    if (s % 2 == 0) s++;
    // Determine direction.
    // Special case = n*n?
    pair<int,int> center = {(n + 1) / 2, (n + 1) / 2};
    if (s == 1) {
        return {center, 0};
    }
    // down
    int rem = inv - (s-2)*(s-2);
    assert(rem > 0);
    int d = (rem - 1) / (s-1);
    assert(0 <= d && d <= 3);
    int x = (rem - 1) % (s-1);
    if (d == 0) {
        pair<int,int> ans = {center.first - (s-3)/2, center.first - (s-3)/2};
        ans.first--;
        ans.second += x;
        return {ans, 3};
    }
    if (d == 1) {
        pair<int,int> ans = {center.first - (s-3)/2, center.first + (s-3)/2};
        ans.second++;
        ans.first += x;
        return {ans, 2};
    }
    if (d == 2) {
        pair<int,int> ans = {center.first + (s-3)/2, center.first + (s-3)/2};
        ans.first++;
        ans.second -= x;
        return {ans, 1};
    }
    if (d == 3) {
        pair<int,int> ans = {center.first + (s-3)/2, center.first - (s-3)/2};
        ans.second--;
        ans.first -= x;
        return {ans, 0};
    }
    assert(false);
}

int __getNum(pair<int,int> c, int n) {
    int x = c.first;
    int y = c.second;

    int center = (n+1)/2;
    int d = max(abs(x - center), abs(y - center));
    int s = d*2 - 1;

    if (d == 0) {
        return n*n;
    }

    // printf("d = %d\n", d);

    // Left
    if (x == center - d) {
        if (y == center - d) {
            return (n*n + 1) - ((s+2)*(s+2));
        }
        int p = y - (center - (d-1));
        assert(0 <= p && p <= s);
        return (n*n + 1) - (s*s + p + 1);
    }
    if (y == center + d) {
        int p = x - (center - (d-1));
        assert(0 <= p && p <= s);
        return (n*n + 1) - (s*s + (s+1) + p + 1);
    }
    if (x == center + d) {
        int p = (center + (d-1)) - y;
        assert(0 <= p && p <= s);
        return (n*n + 1) - (s*s + 2*(s+1) + p + 1);
    }
    if (y == center - d) {
        int p = (center + (d-1)) - x;
        assert(0 <= p && p <= s);
        return (n*n + 1) - (s*s + 3*(s+1) + p+1);
    }
    assert(false);
}

int getNum(pair<int,int> c, int n) {
    // printf("getNum((%d, %d), %d) = ...\n", c.first, c.second, n);
    int num = __getNum(c, n);
    // printf("getNum((%d, %d), %d) = %d\n", c.first, c.second, n, num);
    return num;
}

void solve(int itc) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (k < n-1 || k % 2 == 1) {
        printf("Case #%d: IMPOSSIBLE\n", itc);
        return;
    }

    // Binary search?
    int L = 1, R = n*n;
    while (L < R) {
        int M = (L + R) / 2;
        auto c = getCoordinate(M, n);
        auto p = c.first;
        int dis = abs((n+1)/2 - p.first) + abs((n+1)/2 - p.second);
        int total = dis + M-1;

        // printf("(%d, %d): %d: %d\n", L, R, M, total);

        if (total < k) {
            L = M+1;
        } else {
            R = M;
        }
    }
    // fprintf(stderr, "at %d\n", L);

    vector<pair<int,int>> ans;

    auto c = getCoordinate(L, n);
    // exhaustive walk.
    auto p = c.first;
    int num = L;
    int dis = abs((n+1)/2 - p.first) + abs((n+1)/2 - p.second);
    while (dis > 0) {
        // printf("pos = (%d, %d) (%d)\n", p.first, p.second, num);
        bool found = false;
        for (int d = 0; d < 4; ++d) {
            pair<int,int> np = {p.first + dx[d], p.second + dy[d]};
            int nnum = getNum(np, n);
            if (nnum < num) continue;
            int ndis = abs((n+1)/2 - np.first) + abs((n+1)/2 - np.second);
            if (ndis != dis-1) continue;
            found = true;
            if (nnum != num+1) {
                ans.emplace_back(num, nnum);
            }
            num = nnum;
            p = np;
            dis = ndis;
            break;
        }
        assert(found);
    }
    printf("Case #%d: %lu\n", itc, ans.size());
    for (auto a : ans) {
        printf("%d %d\n", a.first, a.second);
    }
}

int main() {
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {
        solve(itc);
    }

    return 0;
}