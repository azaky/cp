#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

char buffer[100];

bool isPalindrome(const string &s) {
	int len = SZ(s);
	for (int i = 0, j = len - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

int calc(int dd, int MM, int yy, int hh, int mm, int ss) {
	REP(ty, 2) REP(iM, 2) REP(id, 2) REP(iy, 2) REP(th, 2) REP(ih, 2) {
		string date = "";
		if (ty) {
			// Month
			sprintf(buffer, iM ? "%02d" : "%d", MM);
			date += buffer;
			// day
			sprintf(buffer, id ? "%02d" : "%d", dd);
			date += buffer;
			// year
			if (iy) {
				sprintf(buffer, "%d", yy);
			} else {
				sprintf(buffer, "%02d", yy % 100);
			}
			date += buffer;
		} else {
			// day
			sprintf(buffer, id ? "%02d" : "%d", dd);
			date += buffer;
			// Month
			sprintf(buffer, iM ? "%02d" : "%d", MM);
			date += buffer;
			// year
			if (iy) {
				sprintf(buffer, "%d", yy);
			} else {
				sprintf(buffer, "%02d", yy % 100);
			}
			date += buffer;
		}
		// AM/PM
		if (th) {
			// hour
			sprintf(buffer, ih ? "%02d" : "%d", (hh + 11) % 12 + 1);
			date += buffer;
			// minute:second
			sprintf(buffer, "%02d%02d", mm, ss);
			date += buffer;
		} else {
			// hour
			sprintf(buffer, ih ? "%02d" : "%d", hh);
			date += buffer;
			// minute:second
			sprintf(buffer, "%02d%02d", mm, ss);
			date += buffer;
		}
		if (isPalindrome(date)) {
			// printf("%s\n", date.c_str());
			return 1;
		}
	}
	return 0;
}

int calcBrute(int dd, int MM, int yy) {
	int ans = 0;
	for (int hh = 0; hh < 24; ++hh) {
		for (int mm = 0; mm < 60; ++mm) {
			for (int ss = 0; ss < 60; ++ss) {
				ans += calc(dd, MM, yy, hh, mm, ss);
			}
		}
	}
	return ans;
}

int hours0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
int nhours0 = 22;

int hours1[10][5] = {
	{0, 10, 20, 22, -1},
	{1, 11, 13, 21, 23},
	{0, 2, 12, 14, 22},
	{3, 13, 15, 23, -1},
	{4, 14, 16, -1, -1},
	{5, 15, 17, -1, -1},
	{6, 16, 18, -1, -1},
	{7, 17, 19, -1, -1},
	{8, 18, 20, -1, -1},
	{9, 19, 21, -1, -1}
};



int calc(int dd, int MM, int yy, int hh) {
	set<int> s;
	REP(ty, 2) REP(iM, 2) REP(id, 2) REP(iy, 2) REP(th, 2) REP(ih, 2) {
		string date = "";
		if (ty) {
			// Month
			sprintf(buffer, iM ? "%02d" : "%d", MM);
			date += buffer;
			// day
			sprintf(buffer, id ? "%02d" : "%d", dd);
			date += buffer;
			// year
			if (iy) {
				sprintf(buffer, "%d", yy);
			} else {
				sprintf(buffer, "%02d", yy % 100);
			}
			date += buffer;
		} else {
			// day
			sprintf(buffer, id ? "%02d" : "%d", dd);
			date += buffer;
			// Month
			sprintf(buffer, iM ? "%02d" : "%d", MM);
			date += buffer;
			// year
			if (iy) {
				sprintf(buffer, "%d", yy);
			} else {
				sprintf(buffer, "%02d", yy % 100);
			}
			date += buffer;
		}
		int ss = (date[1] - '0') * 10 + (date[0] - '0');
		int mm = (date[3] - '0') * 10 + (date[2] - '0');
		if (ss > 59 || mm > 59) continue;
		int mmss = mm * 60 + ss;
		// AM/PM
		if (th) {
			// hour
			sprintf(buffer, ih ? "%02d" : "%d", (hh + 11) % 12 + 1);
			date += buffer;
			// minute:second
			sprintf(buffer, "%02d%02d", mm, ss);
			date += buffer;
		} else {
			// hour
			sprintf(buffer, ih ? "%02d" : "%d", hh);
			date += buffer;
			// minute:second
			sprintf(buffer, "%02d%02d", mm, ss);
			date += buffer;
		}
		if (isPalindrome(date)) {
			// printf("%s\n", date.c_str());
			s.insert(mmss);
		}
	}
	if (dd == 1 && MM == 1) {
		FORIT(it, s) {
			printf("%d:%02d:%02d\n", hh, (*it/60)%60, *it%60);
		}
	}
	return SZ(s);
}

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int yy) {
	return (yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0;
}

int calc(int yy) {
	int ans = 0;
	for (int MM = 1; MM <= 12; ++MM) {
		int ndays = days[MM];
		if (MM == 2 && isLeap(yy)) {
			ndays++;
		}
		for (int dd = 1; dd <= ndays; ++dd) {
			int temp = 0;
			for (int hh = 0; hh <= 23; ++hh) {
				temp += calc(dd, MM, yy, hh);
			}
			printf("dd = %d, MM = %d, ans = %d\n", dd, MM, temp);
			ans += temp;
		}
	}
	return ans;
}

int main() {
	int ntc;
	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		int year;
		scanf("%d", &year);
		printf("%d\n", calc(year));
	}
	// int day, month, year;
	// scanf("%d%d%d", &day, &month, &year);
	// printf("%d\n", calc(day, month, year));

	return 0;
}