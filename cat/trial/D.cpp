#include <bits/stdc++.h>
using namespace std;

int X[10][10];
int XC = 0;

int q(int r, int c) {
    if (X[r][c] != -1) {
        return X[r][c];
    }

    if (r < 0 || r >= 10 || c < 0 || c >= 10 || XC >= 5) {
        return 0;
    }

    printf("%d %d\n", r+1, c+1);
    fflush(stdout);

    scanf("%d", &X[r][c]);
    XC += X[r][c];
    return X[r][c];
}

int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

int main() {
    memset(X, -1, sizeof(X));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j) % 5 == 0 && q(i, j)) {
                for (int d = 0; d < 4; d++) {
                    int ii = i, jj = j;
                    do {
                        ii += dir[d][0];
                        jj += dir[d][1];
                    } while (q(ii, jj));
                }

                return 0;
            }
        }
    }

    return 0;
}