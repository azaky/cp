#include <iostream>
#include <string>
using namespace std;

int main(){
	pair<string,long long> winner = make_pair("",-1);
	long long skor;
	string s;
	
	while (cin >> s >> skor) if (skor > winner.second) winner = make_pair(s,skor);
	cout << winner.first << endl;
	return 0;
}
