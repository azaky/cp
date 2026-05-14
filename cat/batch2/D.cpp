#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007LL
#define P 998244353LL
#define MAXN 200200

int pmap[24][4];

void init_pmap() {
    int t = 0;
    int a[4] = {0, 1, 2, 3};
    do {
        for (int i = 0; i < 4; i++) {
            pmap[t][i] = a[i];
        }
        t++;
    } while (next_permutation(a, a+4));
}

int n;
long long p[MAXN];

void init_p() {
    p[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        p[i] = p[i-1] * P;
        p[i] %= MOD;
    }
}

char s[MAXN];
int a[MAXN];

#define BSIZE 350

struct bucket {
    int l, r; // [l, r)
    long long s[BSIZE];
};

vector<bucket> buckets;

// index to the bucket
int hsh[24][BSIZE];

int main() {
    init_pmap();
    init_p();

    int q;
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - 'a';
    }

    for (int t = 0; t < 24; t++) {
        for (int b = 0; b * BSIZE < n; b++) {
            int is = b * BSIZE;
            bucket bt;
            bt.l = is;
            bt.r = min(is + BSIZE, n);
            for (int i = 0; is + i < n && i < BSIZE; i++) {
                bt.s[i+1] = (bt.s[i] + p[i] * pmap[t][a[is + i]]) % MOD;
            }
            hsh[t][b] = buckets.size();
            buckets.push_back(bt);
        }
    }

    while (q--) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int u;
            char cs[10];
            scanf("%d%s", &u, cs);
            u--;
            int c = cs[0] - 'a';
            int b = u / BSIZE;
            int i = u - b * BSIZE;
            for (int t = 0; t < 24; t++) {
                // a[u] -> c
            }
        } else if (qt == 2) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--, r--;
            // a -> b, b -> c, c -> d, d -> a
            
        }
    }

    return 0;
}