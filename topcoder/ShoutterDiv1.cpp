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
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<int> adj[3000];
		
class ShoutterDiv1 {
public:
	int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1) {
		int n = 0, s[3000], t[3000], ans = 0;
		
		for (int i=0; i < s1000.size(); ++i){
			for (int j=0; j < s1000[i].length(); ++j){
				s[n] = 1000*int(s1000[i][j]-'0')
				     +  100*int( s100[i][j]-'0')
				     +   10*int(  s10[i][j]-'0')
				     +    1*int(   s1[i][j]-'0');
				t[n] = 1000*int(t1000[i][j]-'0')
				     +  100*int( t100[i][j]-'0')
				     +   10*int(  t10[i][j]-'0')
				     +    1*int(   t1[i][j]-'0');
				n++;
			}
		}
		/*
		printf("%d\n",n);
		for (int i=0; i < n; ++i) printf("[%d][%d]\n",s[i],t[i]);
		*/
		for (int i=0; i < n; ++i)
			for (int j=0; j < n; ++j)
				if (i != j && !(t[i] < s[j] || t[j] < s[i])) adj[i].push_back(j);
		
		queue<int> Q;
		int visit[3000];
		Q.push(0);
		while (!Q.empty()){
			int v = Q.front(); Q.pop();
			if (visit[v]) continue; else visit[v] = 1;
			for (int i=0; i < (int)adj[v].size(); ++i) if (!visit[adj[v][i]]) Q.push(adj[v][i]);
		}
		for (int i=0; i < n; ++i) if (!visit[i]) return -1;
		
		for (int i=0; i < n; ++i)
			for (int j=0; j < n; ++j)
				if (t[i] < s[j] || t[j] < s[i]) ans++;
		
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, vector <string> p2, vector <string> p3, vector <string> p4, vector <string> p5, vector <string> p6, vector <string> p7, bool hasAnswer, int p8) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p3.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p3[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p4[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p5.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p5[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p6.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p6[i] << "\"";
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p7.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p7[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ShoutterDiv1 *obj;
	int answer;
	obj = new ShoutterDiv1();
	clock_t startTime = clock();
	answer = obj->count(p0, p1, p2, p3, p4, p5, p6, p7);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p8 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p8;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <string> p0;
	vector <string> p1;
	vector <string> p2;
	vector <string> p3;
	vector <string> p4;
	vector <string> p5;
	vector <string> p6;
	vector <string> p7;
	int p8;
	
	{
	// ----- test 0 -----
	string t0[] = {"22","2"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00","0"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"11","1"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"21","4"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"22","2"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"00","0"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"11","1"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"43","6"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"00"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"00"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"13"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"00"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"00"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"00"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"24"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = -1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"0000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"0000"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"1234"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"0000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"0000"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"0000"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"2345"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 6;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"0000000000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"0000000000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"0000000000"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"7626463146"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"0000000000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"0000000000"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"0000000000"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"9927686479"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 18;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"00000000000000000000000000000000000000000000000000"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	string t1[] = {"00000000000000000000000000000000000000000000000000"};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"50353624751857130208544645495168271486083954769538"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	string t3[] = {"85748487990028258641117783760944852941545064635928"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	string t4[] = {"00000000000000000000000000000000000000000000000000"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	string t5[] = {"00000000000000000000000000000000000000000000000000"};
			p5.assign(t5, t5 + sizeof(t5) / sizeof(t5[0]));
	string t6[] = {"61465744851859252308555855596388482696094965779649"};
			p6.assign(t6, t6 + sizeof(t6) / sizeof(t6[0]));
	string t7[] = {"37620749792666153778227385275518278477865684777411"};
			p7.assign(t7, t7 + sizeof(t7) / sizeof(t7[0]));
	p8 = 333;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, p6, p7, true, p8) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
