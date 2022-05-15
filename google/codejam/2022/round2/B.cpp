#include <bits/stdc++.h>
using namespace std;

long long solve(int R) {
    vector<long long> h(R+1);

    h[0] = R;

    for (int x = 1; x <= R; ++x) {
        h[x] = h[x-1];
        while ((int)(round(sqrt(x * x + h[x] * h[x]))) > R) {
            h[x]--;
        }
        printf("h[%d] = %lld\n", x, h[x]);
    }

    long long correctArea = 1 + 4 * R;
    for (int x = 1; x <= R; ++x) {
        correctArea += h[x] * 4;
    }

    long long wrongArea = 1;
    long long tri = 0;
    for (int i = 1; i <= R; ++i) {
        tri += i;
        wrongArea += 4 * tri;
    }

    printf("correct = %lld, wrong = %lld\n", correctArea, wrongArea);

    return correctArea - wrongArea;
}

int main() {
    int ntc;
    scanf("%d", &ntc);
    for (int itc = 1; itc <= ntc; ++itc) {
        int R;
        scanf("%d", &R);
        long long ans = solve(R);

        printf("Case #%d: %lld\n", itc, ans);
    }

    return 0;
}