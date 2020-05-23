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

string rock[11] = {"Kamen", "Rock", "Pierre", "Stein", "Ko", "Koe", "Sasso", "Roccia", "Guu", "Kamien", "Piedra"};
string scissor[10] = {"Nuzky", "Scissors", "Ciseaux", "Schere", "Ollo", "Olloo", "Forbice", "Choki", "Nozyce", "Tijera"};
string paper[8] = {"Papir", "Paper", "Feuille", "Papier", "Carta", "Rete", "Paa", "Papel"};

map<string, int> huba;

int getcode(const string &s) {
	return huba[s];
}

char buf1[111111], buf2[111111];
pair<string, string> tokenize(const string& s) {
	if (sscanf(s.c_str(), "%s %s", buf1, buf2) == 2) {
		return MP(string(buf1), string(buf2));
	}
	return MP(s, "");
}

int score[33][33];
string line;

int main(){
	REP(i, 11) {
		huba[rock[i]] = 0;
	}
	REP(i, 10) {
		huba[scissor[i]] = 1;
	}
	REP(i, 8) {
		huba[paper[i]] = 2;
	}

	score[0][1] = score[1][2] = score[2][0] = 1;
	int ngame = 0;

	while (++ngame) {
		getline(cin, line);
		pair<string, string> p1 = tokenize(line);
		getline(cin, line);
		pair<string, string> p2 = tokenize(line);
		int s1 = 0, s2 = 0;
		while (true) {
			getline(cin, line);
			if (line[0] == '-' || line[0] == '.') break;
			pair<string, string> g = tokenize(line);
			int c1 = getcode(g.A);
			int c2 = getcode(g.B);
			s1 += score[c1][c2];
			s2 += score[c2][c1];
		}

		printf("Game #%d:\n", ngame);
		printf("%s: %d point", p1.B.c_str(), s1);
		puts(s1 == 1 ? "" : "s");
		printf("%s: %d point", p2.B.c_str(), s2);
		puts(s2 == 1 ? "" : "s");
		if (s1 == s2) {
			puts("TIED GAME");
		} else if (s1 > s2) {
			printf("WINNER: %s\n", p1.B.c_str());
		} else {
			printf("WINNER: %s\n", p2.B.c_str());
		}
		puts("");
		if (line[0] == '.') break;
	}

	return 0;
}