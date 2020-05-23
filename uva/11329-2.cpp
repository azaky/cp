#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	int time_void;
	#define GetTime time_void = clock();\
	printf("Running time: %.3lf second\n",((double)time_void)/CLOCKS_PER_SEC);
#else
	#define debug(...) 
	#define GetTime 
#endif

inline int StringToInt(string s){
	int x;
	stringstream(s) >> x;
	return x;
}
inline string IntToString(int x){
	stringstream s;
	s << x;
	return s.str();
}

/* -------------- end of azaky's template -------------- */

#define MAXS 1 << 26
#define INF 1000000000

struct state{
	vector <string> board;
	vector <int> dice;
	/*
	 * rules for dice[]
	 * 0 = bottom
	 * 1 = up
	 * 2 = right
	 * 3 = down
	 * 4 = left
	 * 5 = top
	 */
/*
	void _dice(int _vdice){
		vector <int> ret;
		for (int i=0; i<6; ++i)
			ret.push_back(_vdice & (1 << i) > 0 ? 1 : 0);
		dice = ret;
		return;
	}
*/
	int dx,dy,step;
	int vdice(){
		int ret = 0;
		for (int i=0; i<6; ++i)
			if (dice[i]) ret += 1 << i;
		return ret;
	}
	int vboard(){
		int ret = 0;
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				if (board[i][j] == 'X') ret += 1 << (4*i + j);
		return ret;
	}
	int value(){
		return vboard() * (1 << 10) + vdice() * (1 << 4) + dx * (1 << 2) + dy;
	}
	void read(){
		string s;
		vector <string> _board;
		int _dx,_dy;
		for (int i=0; i<4; ++i){
			getline(cin,s);
			for (int j=0; j<4; ++j)
				if (s[j]== 'D'){
					_dx = i; _dy = j;
				}
			_board.push_back(s);
		}
		vector <int> _dice;
		for (int i=0; i<6; ++i) _dice.push_back(0);
		board = _board;
		dice = _dice;
		dx = _dx;
		dy = _dy;
		step = 0;
		return;
	}
	bool done(){
		return (vboard() == 0);
	}
	void create(vector <string> _board, vector <int> _dice, int _dx, int _dy, int _step){
		board = _board;
		dice = _dice;
		dx = _dx;
		dy = _dy;
		step = _step;
		return;
	}
	void print(){
		printf("--------------------------------\nState number #%d:\n",value());
		for (int i=0; i<4; ++i) printf("%s\n",board[i].c_str());
		for (int i=0; i<6; ++i) printf("%d",dice[i]); printf("\n");
		printf("%d %d\n",dx,dy);
		printf("Steps taken: %d\n--------------------------------\n",step);
		return;
	}
	string steps;
};

int calc(state now){
	int val = now.value();
	if (used[val] == -1) return INF;
	if (used[val] == 1) return step[val];
	used[val] = -1;
	step[val] = INF;
	if (now.done()){
		step[val] = 0;
		used[val] = 1;
		return step[val];
	}
	
	int _step = now.step + 1;
	vector<int> _dice;
	vector<string> _board;
			//roll up
			if (now.dx != 0){
				_dice.clear();
				_dice.push_back(now.dice[1]);
				_dice.push_back(now.dice[5]);
				_dice.push_back(now.dice[2]);
				_dice.push_back(now.dice[0]);
				_dice.push_back(now.dice[4]);
				_dice.push_back(now.dice[3]);
				_dx = now.dx - 1;
				_dy = now.dy;
				_board = now.board;
				if (_board[_dx][_dy]=='X' && _dice[0]==0){
					_board[_dx][_dy] = '.';
					_dice[0] = 1;
				}
				else if (_board[_dx][_dy]!='X' && _dice[0]!=0){
					_board[_dx][_dy] = 'X';
					_dice[0] = 0;
				}
				next.create(_board,_dice,_dx,_dy,_step);
				step[val] = 
				if (!used[next.value()]){
					used[next.value()] = 1;
					next.steps = now.steps + 'U';
					q.push(next);
				}
			}
			//roll right
			if (now.dy != 3){
				_dice.clear();
				_dice.push_back(now.dice[2]);
				_dice.push_back(now.dice[1]);
				_dice.push_back(now.dice[5]);
				_dice.push_back(now.dice[3]);
				_dice.push_back(now.dice[0]);
				_dice.push_back(now.dice[4]);
				_dx = now.dx;
				_dy = now.dy + 1;
				_board = now.board;
				if (_board[_dx][_dy]=='X' && _dice[0]==0){
					_board[_dx][_dy] = '.';
					_dice[0] = 1;
				}
				else if (_board[_dx][_dy]!='X' && _dice[0]!=0){
					_board[_dx][_dy] = 'X';
					_dice[0] = 0;
				}
				next.create(_board,_dice,_dx,_dy,_step);
				if (!used[next.value()]){
					used[next.value()] = 1;
					next.steps = now.steps + 'R';
					q.push(next);
				}
			}
			//roll down
			if (now.dx != 3){
				_dice.clear();
				_dice.push_back(now.dice[3]);
				_dice.push_back(now.dice[0]);
				_dice.push_back(now.dice[2]);
				_dice.push_back(now.dice[5]);
				_dice.push_back(now.dice[4]);
				_dice.push_back(now.dice[1]);
				_dx = now.dx + 1;
				_dy = now.dy;
				_board = now.board;
				if (_board[_dx][_dy]=='X' && _dice[0]==0){
					_board[_dx][_dy] = '.';
					_dice[0] = 1;
				}
				else if (_board[_dx][_dy]!='X' && _dice[0]!=0){
					_board[_dx][_dy] = 'X';
					_dice[0] = 0;
				}
				next.create(_board,_dice,_dx,_dy,_step);
				if (!used[next.value()]){
					used[next.value()] = 1;
					next.steps = now.steps + 'D';
					q.push(next);
				}
			}
			//roll left
			if (now.dy != 0){
				_dice.clear();
				_dice.push_back(now.dice[4]);
				_dice.push_back(now.dice[1]);
				_dice.push_back(now.dice[0]);
				_dice.push_back(now.dice[3]);
				_dice.push_back(now.dice[5]);
				_dice.push_back(now.dice[2]);
				_dx = now.dx;
				_dy = now.dy - 1;
				_board = now.board;
				if (_board[_dx][_dy]=='X' && _dice[0]==0){
					_board[_dx][_dy] = '.';
					_dice[0] = 1;
				}
				else if (_board[_dx][_dy]!='X' && _dice[0]!=0){
					_board[_dx][_dy] = 'X';
					_dice[0] = 0;
				}
				next.create(_board,_dice,_dx,_dy,_step);
				if (!used[next.value()]){
					used[next.value()] = 1;
					next.steps = now.steps + 'L';
					q.push(next);
				}
			}
		}

int tc,_step,_dx,_dy,used[MAXS],step[MAXS];
string s;
state init,now,next;
vector <int> _dice;
vector <string> _board;

int main(){
	scanf("%d",&tc);
	getline(cin,s);
	while (tc--){
		getline(cin,s); // newline
		init.read();
		int ans = calc(init);
		if (ans == INF) puts("impossible"); else printf("%d\n",ans);
	}
		init.steps = "";
		queue <state> q;
		memset(used,0,sizeof(used));
		q.push(init); used[init.value()] = 1;
		while (!q.empty()){
			now = q.front(); q.pop();
			if (now.done()){
				printf("%d\n%s\n",now.step,now.steps.c_str());
				break;
			}
			_step = now.step + 1;
			//now.print();
			//roll up
			if (now.dx != 0){
				_dice.clear();
				_dice.push_back(now.dice[1]);
				_dice.push_back(now.dice[5]);
				_dice.push_back(now.dice[2]);
				_dice.push_back(now.dice[0]);
				_dice.push_back(now.dice[4]);
				_dice.push_back(now.dice[3]);
				_dx = now.dx - 1;
				_dy = now.dy;
				_board = now.board;
				if (_board[_dx][_dy]=='X' && _dice[0]==0){
					_board[_dx][_dy] = '.';
					_dice[0] = 1;
				}
				else if (_board[_dx][_dy]!='X' && _dice[0]!=0){
					_board[_dx][_dy] = 'X';
					_dice[0] = 0;
				}
				next.create(_board,_dice,_dx,_dy,_step);
				if (!used[next.value()]){
					used[next.value()] = 1;
					next.steps = now.steps + 'U';
					q.push(next);
				}
			}
			//roll right
			if (now.dy != 3){
				_dice.clear();
				_dice.push_back(now.dice[2]);
				_dice.push_back(now.dice[1]);
				_dice.push_back(now.dice[5]);
				_dice.push_back(now.dice[3]);
				_dice.push_back(now.dice[0]);
				_dice.push_back(now.dice[4]);
				_dx = now.dx;
				_dy = now.dy + 1;
				_board = now.board;
				if (_board[_dx][_dy]=='X' && _dice[0]==0){
					_board[_dx][_dy] = '.';
					_dice[0] = 1;
				}
				else if (_board[_dx][_dy]!='X' && _dice[0]!=0){
					_board[_dx][_dy] = 'X';
					_dice[0] = 0;
				}
				next.create(_board,_dice,_dx,_dy,_step);
				if (!used[next.value()]){
					used[next.value()] = 1;
					next.steps = now.steps + 'R';
					q.push(next);
				}
			}
			//roll down
			if (now.dx != 3){
				_dice.clear();
				_dice.push_back(now.dice[3]);
				_dice.push_back(now.dice[0]);
				_dice.push_back(now.dice[2]);
				_dice.push_back(now.dice[5]);
				_dice.push_back(now.dice[4]);
				_dice.push_back(now.dice[1]);
				_dx = now.dx + 1;
				_dy = now.dy;
				_board = now.board;
				if (_board[_dx][_dy]=='X' && _dice[0]==0){
					_board[_dx][_dy] = '.';
					_dice[0] = 1;
				}
				else if (_board[_dx][_dy]!='X' && _dice[0]!=0){
					_board[_dx][_dy] = 'X';
					_dice[0] = 0;
				}
				next.create(_board,_dice,_dx,_dy,_step);
				if (!used[next.value()]){
					used[next.value()] = 1;
					next.steps = now.steps + 'D';
					q.push(next);
				}
			}
			//roll left
			if (now.dy != 0){
				_dice.clear();
				_dice.push_back(now.dice[4]);
				_dice.push_back(now.dice[1]);
				_dice.push_back(now.dice[0]);
				_dice.push_back(now.dice[3]);
				_dice.push_back(now.dice[5]);
				_dice.push_back(now.dice[2]);
				_dx = now.dx;
				_dy = now.dy - 1;
				_board = now.board;
				if (_board[_dx][_dy]=='X' && _dice[0]==0){
					_board[_dx][_dy] = '.';
					_dice[0] = 1;
				}
				else if (_board[_dx][_dy]!='X' && _dice[0]!=0){
					_board[_dx][_dy] = 'X';
					_dice[0] = 0;
				}
				next.create(_board,_dice,_dx,_dy,_step);
				if (!used[next.value()]){
					used[next.value()] = 1;
					next.steps = now.steps + 'L';
					q.push(next);
				}
			}
		}
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
