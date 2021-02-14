#define DEBUG

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include <ctime>
#include <cassert>
using namespace std;
// template

// abbreviations
#define vi vector <int>
#define vl vector <long long>
#define vb vector <bool>
#define vs vector <string>
#define ii pair <int, int>
#define a first
#define b second
#define vii vector <ii>
#define mii map <int, int>
#define que queue
#define pque priority_queue
#define stk stack
#define lsone(value) (value)&(-value)
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define pu push
#define po pop
#define mp make_pair
#define loop(i, n) for(int i = 0; i < n; ++i)
#define loop1(i, n) for(int i = 1; i <= n; ++i)
#define reverse_iterate(a, b) for(__typeof(b.rend()) a = b.rbegin(); a != b.rend(); ++a)
#define iterate(a, b) for(__typeof(b.begin()) a = b.begin(); a != b.end(); ++a)
#define all(i) i.begin(), i.end()

typedef unsigned long long ull;
typedef long long ll;

const double PI = acos(-1);

#ifdef DEBUG
  #define debug(...) printf(__VA_ARGS__)
  #define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
  #define debug(...) 
  #define GetTime() 
#endif

// end of template

bool sf(ii a, ii b) {
  if (a.b != b.b)
    return a.b < b.b;
  return a.a > b.a;
}

int main() {
    // freopen("SUBSEG2.in", "r", stdin);
    
    int n, q;
    scanf("%d %d", &n, &q);
    vii courses;
    loop(it, n) {
      int start, time;
      scanf("%d %d", &start, &time);
      courses.pub(mp(start, time));
    }
    sort(all(courses), sf);

    vector<vector<int> > par(n, vi(25, -1));
    vi dp(n, 1);
    map<int, int> start_course_next;
    for (int idx = courses.size()-1; idx >= 0; --idx) {
      ii &course = courses[idx];
      mii::iterator next_course = start_course_next.upper_bound(course.b);
      if (next_course != start_course_next.end()) {
        dp[idx] = dp[next_course->b]+1;
            par[idx][0] = next_course->b;
      } else {
            par[idx][0] = idx;
        }
        for (int level = 1; level < 25; ++level) {
            par[idx][level] = par[par[idx][level-1]][level-1];
        }
      if ((start_course_next.upper_bound(course.a) != start_course_next.end()) and (courses[start_course_next.upper_bound(course.a)->b].b < course.b)) {
        // there are others that finish earlier
      } else {
        start_course_next[course.a] = idx;
      }
    }
    while (q--) {
      int start, end;
      scanf("%d %d", &start, &end);
      int ans = 0;
      mii::iterator first_course = start_course_next.lower_bound(start);
      if (first_course != start_course_next.end()) {
            ans = dp[first_course->b];
            // do the binary lifting here
            int node_idx = first_course->b;
            if (courses[node_idx].b <= end) {
                for (int level = 24; level >= 0; --level) {
                    if (courses[par[node_idx][level]].b  <= end) {
                        node_idx = par[node_idx][level];
                    }
                }
                node_idx = par[node_idx][0];
            }
            if (courses[node_idx].b > end) {
                ans -= dp[node_idx];
            }
      }
      printf("%d\n", ans);
    }

    return 0;
}