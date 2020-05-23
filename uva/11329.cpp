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
	void _dice(int _vdice){
		vector <int> ret;
		for (int i=0; i<6; ++i)
			ret.push_back((_vdice & (1 << i)) > 0 ? 1 : 0);
		dice = ret;
		return;
	}
	int dx,dy,step;
	int vdice(){
		int ret = 0;
		for (int i=0; i<6; ++i)
			if (dice[i]) ret ^= 1 << i;
		return ret;
	}
	int vboard(){
		int ret = 0;
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				if (board[i][j] == 'X') ret ^= 1 << (4*i + j);
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
	void create(vector <string> &_board, vector <int> &_dice, int _dx, int _dy, int _step){
		board = _board;
		dice = _dice;
		dx = _dx;
		dy = _dy;
		step = _step;
		return;
	}
	void create(pair<int,int> _value){
		int value = _value.first, _step = _value.second;
		step = _step;
		dy = value & ((1 << 2) - 1);
		value >>= 2;
		dx = value & ((1 << 2) - 1);
		value >>= 2;
		int _vdice = value & ((1 << 6) - 1);
		value >>= 6;
		int _vboard = value;
		board.resize(4);
		for (int i=0; i < 4; ++i) board[i].resize(4);
		for (int i=0; i<4; ++i)
			for (int j=0; j<4; ++j)
				board[i][j] = _vboard & (1 << (4*i + j)) ? 'X' : '.';
		dice.resize(6);
		for (int i=0; i<6; ++i)
			dice[i] = (_vdice & (1 << i)) >> i;
	}
	void print(){
		printf("--------------------------------\nState number #%d:\n",value());
		for (int i=0; i<4; ++i) printf("%s\n",board[i].c_str());
		for (int i=0; i<6; ++i) printf("%d",dice[i]); printf("\n");
		printf("%d %d\n",dx,dy);
		printf("Steps taken: %d\n--------------------------------\n",step);
		return;
	}
//	string steps;
};

#define MAXS 1 << 26

int tc,_step,_dx,_dy;
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
//		init.steps = "";
		queue < pair<int,int> > q;
		map<int,int> used;
		q.push(make_pair(init.value(),0)); used[init.value()] = 1;
		while (!q.empty()){
			now.create(q.front()); q.pop();
			if (now.done()){
				printf("%d\n",now.step);
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
//					next.steps = now.steps + 'U';
					q.push(make_pair(next.value(),_step));
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
//					next.steps = now.steps + 'R';
					q.push(make_pair(next.value(),_step));
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
//					next.steps = now.steps + 'D';
					q.push(make_pair(next.value(),_step));
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
//					next.steps = now.steps + 'L';
					q.push(make_pair(next.value(),_step));
				}
			}
		}
		puts("impossible");
	}
	return 0;
}
	
	
	
	
	
	
	
	
	
