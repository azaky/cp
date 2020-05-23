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


class DisjointSemicircles {
public:
	string getPossibility(vector <int> labels) {
		
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	DisjointSemicircles *obj;
	string answer;
	obj = new DisjointSemicircles();
	clock_t startTime = clock();
	answer = obj->getPossibility(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <int> p0;
	string p1;
	
	{
	// ----- test 0 -----
	int t0[] = {-1,0,-1,-1,0,-1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "POSSIBLE";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {1,-1,2,1,-1,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {2,-1,-1,0,-1,-1,2,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "POSSIBLE";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {-1,1,3,-1,1,3,-1,-1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {-1,5,-1,-1,3,6,8,-1,10,7,-1,7,8,0,11,-1,-1,11,0,10,4,-1,6,5,-1,-1,9,9,4,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "POSSIBLE";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	int t0[] = {4,-1,2,4,-1,3,3,12,2,5,-1,0,9,9,8,-1,12,8,-1,6,0,-1,-1,-1,5,6,10,-1,-1,10};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	int t0[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "POSSIBLE";
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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
