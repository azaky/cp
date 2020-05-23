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

#define MAXLEN 50
#define MAXCMD 100000
#define MAXMEMO 333

int memo[MAXMEMO], nmemo, label[MAXCMD], B1, B2;
char _cmd[MAXLEN], cmd[MAXCMD][MAXLEN], sa[MAXLEN], sb[MAXLEN], sc[MAXLEN];
map<string, int> go;

int main(){
	gets(_cmd);
	sscanf(_cmd, "%X", &nmemo);
	int ncmd = 0;
	while (gets(_cmd)) {
		int start = 0;
		label[ncmd] = -1;
		if (sscanf(_cmd, "%s %s %s", sa, sb, sc) == 3) {
			go[sa] = ncmd;
			while (_cmd[start] != ' ') {
				start++;
			}
			while (_cmd[start] == ' ') {
				start++;
			}
		}
		strcpy(cmd[ncmd], _cmd + start);
		ncmd++;
	}
	
	int p = 0;
	while (p < ncmd) {
		int a1, a2, n;
		char lbl[MAXLEN];
		if (sscanf(cmd[p], "PRINT %X,%X", &a1, &a2) == 2) {
			// print the hexadecimal bytes stored in locations A1 to A2 (inclusive)
			FOR(i, a1, a2) {
				printf("%02X", memo[i]);
				if (i < a2) {
					printf(" ");
				}
				else {
					printf("\n");
				}
			}
			//puts("command 2");
		}
		else if (sscanf(cmd[p], "PRINT %X", &a1) == 1) {
			// print the hexadecimal byte stored at memory location A1
			printf("%02X\n", memo[a1]);
			//puts("command 1");
		}
		else if (sscanf(cmd[p], "MOVE #%X,%X", &n, &a1) == 2) {
			// move constant N to memory location A1
			memo[a1] = n;
			//puts("command 3");
		}
		else if (sscanf(cmd[p], "MOVE #%X,(%X)", &n, &a1) == 2) {
			// move constant N to the dereferenced address A1
			memo[memo[a1]] = n;
			//puts("command 4");
		}
		else if (sscanf(cmd[p], "MOVE (%X),%X", &a1, &a2) == 2) {
			// move the dereferenced addresss A1 into A2
			memo[a2] = memo[memo[a1]];
			//puts("command 5");
		}
		else if (sscanf(cmd[p], "MOVE (%X),(%X)", &a1, &a2) == 2) {
			// move the dereferenced address A1 into the dereferenced address A2
			memo[memo[a2]] = memo[memo[a1]];
			//puts("command 6");
		}
		else if (sscanf(cmd[p], "MOVE %X,(%X)", &a1, &a2) == 2) {
			// move the byte at A1 to the dereferenced address A2
			memo[memo[a2]] = memo[a1];
			//puts("command 7");
		}
		else if (sscanf(cmd[p], "MOVE %X,%X", &a1, &a2) == 2) {
			// move byte from memory location A1 to A2
			memo[a2] = memo[a1];
			//puts("command 8");
		}
		else if (sscanf(cmd[p], "ADD #%X,%X", &n, &a1) == 2) {
			// add constant N to the value stored at A1. Result stored in A1
			memo[a1] += n;
			memo[a1] %= 0x100;
			//puts("command 9");
		}
		else if (sscanf(cmd[p], "ADD %X,%X", &a1, &a2) == 2) {
			// add value from A1 to A2. Result stored in A2
			memo[a2] += memo[a1];
			memo[a2] %= 0x100;
			//puts("command 10");
		}
		else if (sscanf(cmd[p], "SUB #%X,%X", &n, &a1) == 2) {
			// subtract constant N to the value stored at A1. Result stored in A1
			memo[a1] += 0x100 - n;
			memo[a1] %= 0x100;
			//puts("command 11");
		}
		else if (sscanf(cmd[p], "SUB %X,%X", &a1, &a2) == 2) {
			// subtract value from A1 to A2. Result stored in A2
			memo[a2] += 0x100 - memo[a1];
			memo[a2] %= 0x100;
			//puts("command 12");
		}
		else if (sscanf(cmd[p], "AND #%X,%X", &n, &a1) == 2) {
			// Logical AND between constant N and A1. Result stored in A1
			memo[a1] &= n;
			//puts("command 13");
		}
		else if (sscanf(cmd[p], "AND %X,%X", &a1, &a2) == 2) {
			// Logical AND between values at A1 and A2. Result stored in A2
			memo[a2] &= memo[a1];
			//puts("command 14");
		}
		else if (sscanf(cmd[p], "OR #%X,%X", &n, &a1) == 2) {
			// Logical OR between constant N and A1. Result stored in A1
			memo[a1] |= n;
			//puts("command 15");
		}
		else if (sscanf(cmd[p], "OR %X,%X", &a1, &a2) == 2) {
			// Logical OR between values at A1 and A2. Result stored in A2
			memo[a2] |= memo[a1];
			//puts("command 16");
		}
		else if (sscanf(cmd[p], "XOR #%X,%X", &n, &a1) == 2) {
			// Logical XOR between constant N and A1. Result stored in A1
			memo[a1] ^= n;
			//puts("command 17");
		}
		else if (sscanf(cmd[p], "XOR %X,%X", &a1, &a2) == 2) {
			// Logical XOR between values at A1 and A2. Result stored in A2
			memo[a2] ^= memo[a1];
			//puts("command 18");
		}
		else if (sscanf(cmd[p], "COMP #%X,%X", &n, &a1) == 2) {
			// Compare constant N to A1. Result stored in the processor to use in the following branch operation
			B1 = n;
			B2 = memo[a1];
			//puts("command 19");
		}
		else if (sscanf(cmd[p], "COMP %X,%X", &a1, &a2) == 2) {
			// Compare values stored at A1 and A2. Result stored in the processor to use in the following branch operation
			B1 = memo[a1];
			B2 = memo[a2];
			//puts("command 20");
		}
		else if (sscanf(cmd[p], "BEQ %s", lbl) == 1) {
			// Branch to label if result of comparison is equal
			if (B1 == B2) {
				p = go[lbl];
				continue;
			}
			//puts("command 21");
		}
		else if (sscanf(cmd[p], "BNE %s", lbl) == 1) {
			// Branch to label if result of comparison is not equal
			if (B1 != B2) {
				p = go[lbl];
				continue;
			}
			//puts("command 22");
		}
		else if (sscanf(cmd[p], "BGT %s", lbl) == 1) {
			// Branch to label if result of comparison is true (A1 > A2)
			if (B1 > B2) {
				p = go[lbl];
				continue;
			}
			//puts("command 23");
		}
		else if (sscanf(cmd[p], "BLT %s", lbl) == 1) {
			// Branch to label if result of comparison is true (A1 < A2)
			if (B1 < B2) {
				p = go[lbl];
				continue;
			}
			//puts("command 24");
		}
		else if (sscanf(cmd[p], "BGE %s", lbl) == 1) {
			// Branch to label if result of comparison is true (A1 >= A2)
			if (B1 >= B2) {
				p = go[lbl];
				continue;
			}
			//puts("command 25");
		}
		else if (sscanf(cmd[p], "BLE %s", lbl) == 1) {
			// Branch to label if result of comparison is true (A1 <= A2)
			if (B1 <= B2) {
				p = go[lbl];
				continue;
			}
			//puts("command 26");
		}
		else {
			assert(false);
		}
		// move to the next command
		p++;
	}
	
	return 0;
}
