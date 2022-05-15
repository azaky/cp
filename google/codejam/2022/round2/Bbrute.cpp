#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>, bool> canvas;

void draw_circle_perimeter(int R, map<pair<int,int>, bool> &canvas) {
    for (int x = -R; x <= R; ++x) {
        int y = (int)(round(sqrt(R * R - x * x)));
        canvas[make_pair(x, y)] = true;
        canvas[make_pair(x, -y)] = true;
        canvas[make_pair(y, x)] = true;
        canvas[make_pair(-y, x)] = true;
    }
}

void draw_circle_filled(int R, map<pair<int,int>, bool> &canvas) {
    for (int x = -R; x <= R; ++x) {
        for (int y = -R; y <= R; ++y) {
            if ((int)(round(sqrt(x * x + y * y))) <= R) {
                canvas[make_pair(x, y)] = true;
            }
        }
    }
}

void draw_circle_filled_wrong(int R, map<pair<int,int>, bool> &canvas) {
    for (int r = 0; r <= R; ++r) {
        draw_circle_perimeter(r, canvas);
    }
}

long long solve(int R) {
    map<pair<int,int>, bool> canvasCorrect, canvasWrong;

    draw_circle_filled(R, canvasCorrect);
    draw_circle_filled_wrong(R, canvasWrong);

    for (int x = -R; x <= R; ++x) {
        for (int y = -R; y <= R; ++y) {
            printf("%d", canvasCorrect[make_pair(x, y)]);
        }
        printf("\n");
    }
    printf("\n");
    for (int x = -R; x <= R; ++x) {
        for (int y = -R; y <= R; ++y) {
            printf("%d", canvasWrong[make_pair(x, y)]);
        }
        printf("\n");
    }
    printf("\n");

    int ans = 0;

    for (int x = -R; x <= R; ++x) {
        for (int y = -R; y <= R; ++y) {
            if (canvasCorrect[make_pair(x, y)] != canvasWrong[make_pair(x, y)]) {
                ans++;
                // printf("(%d, %d)\n", x, y);
            }
        }
    }

    return ans;
}

long long solve2(int R) {
    map<pair<int,int>, bool> canvasCorrect;

    draw_circle_filled(R, canvasCorrect);

    int area = 0;
    for (int x = -R; x <= R; ++x) {
        for (int y = -R; y <= R; ++y) {
            if (canvasCorrect[make_pair(x, y)]) {
                area++;
            }
        }
    }

    int wrongArea = 5;
    for (int i = 2; i <= R; ++i) {
        wrongArea += 4 * (i + 1);
    }

    printf("correct = %d, wrong = %d\n", area, wrongArea);

    return area - wrongArea;
}

int main() {
    int ntc;
    scanf("%d", &ntc);
    // ntc = 100;
    for (int itc = 1; itc <= ntc; ++itc) {
        int R;
        // R = itc;
        scanf("%d", &R);
        long long ans = solve(R);
        long long ans2 = solve2(R);
        
        printf("R = %d, ans = %lld ... %lld\n", R, ans, ans2);
        fflush(stdout);

        assert(ans == ans2);

        printf("Case #%d: %lld\n", itc, ans);
    }

    return 0;
}