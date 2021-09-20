#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> point;
#define x first
#define y second
const double e = 1e-12;

bool online(point p, point a, point b) {
  return fabs((p.x - a.x) * (p.y - b.y) - (p.x - b.x) * (p.y - a.y)) < e;
}

double distance(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

bool onsegment(point p, point a, point b) {
  return fabs(distance(a, p) + distance(b, p) - distance(a, b)) < e;
}

double cross(point a, point b, point c) {
  point ab = make_pair(a.x - b.x, a.y - b.y);
  point bc = make_pair(b.x - c.x, b.y - c.y);
  return ab.x * bc.y - ab.y * bc.x;
}

bool onsameside(point p, point q, point a, point b) {
  return cross(a, b, p) * cross(a, b, q) > e;
}

void solve(int itc) {
  int n;
  scanf("%d", &n);
  point s;
  vector<point> p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
  }
  scanf("%lf%lf", &s.x, &s.y);
  double ans = -1;
  for (int a = 0; a < n; ++a) {
    for (int b = a+1; b < n; ++b) {
      if (online(s, p[a], p[b])) continue;
      for (int c = b+1; c < n; ++c) {
        if (online(s, p[a], p[c]) || online(s, p[b], p[c])) continue;
        if (online(p[a], p[b], p[c])) continue;
        point g = make_pair((p[a].x + p[b].x + p[c].x) / 3., (p[a].y + p[b].y + p[c].y) / 3.);
        if (onsameside(s, g, p[a], p[b]) && onsameside(s, g, p[a], p[c]) && onsameside(s, g, p[b], p[c])) {
          double perim = distance(p[a], p[b]) + distance(p[b], p[c]) + distance(p[c], p[a]);
          // printf("(%d, %d, %d)\n", a, b, c);
          if (perim < ans || ans < 0) {
            ans = perim;
          }
        }
      }
    }
  }
  for (int a = 0; a < n; ++a) {
    for (int b = a+1; b < n; ++b) {
      if (onsegment(s, p[a], p[b])) {
        double minp = -1, minn = -1;
        int pi,  ni;
        for (int c = 0; c < n; ++c) {
          if (c == a || c == b) continue;
          double cr = cross(p[a], p[b], p[c]);
          if (fabs(cr) < e) continue;
          double perim = distance(p[a], p[c]) + distance(p[c], p[b]);
          if (cr > e) {
            if (perim < minp || minp < 0) {
              minp = perim;
              pi = c;
            }
          } else {
            if (perim < minn || minn < 0) {
              minn = perim;
              ni = c;
            }
          }
        }
        if (minp > 0 && minn > 0) {
          // printf("(%d, %d) - (%d, %d)\n", a, b, pi, ni);
          double perim = minp + minn;
          if (perim < ans || ans < 0) {
            ans = perim;
          }
        }
      }
    }
  }

  if (ans < 0) {
    puts("IMPOSSIBLE");
  } else {
    printf("%.17lf\n", ans);
  }
}

int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int itc = 1; itc <= ntc; ++itc) {
    printf("Case #%d: ", itc);
    solve(itc);
  }
}