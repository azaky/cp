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

#define MOD 1000000007LL

typedef vector<vector<long long> > Matrix;

Matrix product(Matrix a, Matrix b, int n){
	Matrix ret;
	ret.resize(n); for(int i=0; i < n; ++i) ret[i].resize(n);
	for (int i=0; i < n; ++i)
	for (int i=0; i < n; ++i)
		for (int j=0; j < n; ++j)
			for (int k=0; k < n; ++k)
				ret[i][j] += (a[i][k]*b[k][j])%MOD;
	return ret;
}
Matrix power(Matrix a, long long p, int n){
	if (p == 1LL) return a;
	Matrix ret = power(a,p/2LL,n);
	ret = product(ret,ret,n);
	if (p % 2LL == 1) ret = product(ret,a,n);
	return ret;
}

class PenguinEmperor {
public:
	int countJourneys(int numCities, long long daysPassed) {
		int n = numCities;
		long long d = daysPassed;
		long long F[400][400]; memset(F,0,sizeof(F));
		F[0][0] = 1;
		for (int day = 1; day <= n; ++day){
			for (int c = 0; c < n; ++c){
				F[day][c] = (F[day-1][(c-day+n)%n]+F[day-1][(c+day)%n])%MOD;
			}
		}
		if (d <= n) return F[d][0];
		//creating the matrix
		Matrix M, ret;
		M.resize(n); for(int i=0; i < n; ++i) M[i].resize(n);
		for (int i=0; i < n; ++i) for (int j=0; j < n; ++j) M[i][j] = F[n][(j-i+n)%n];
		
		ret = power(M,d/(long long)n, n);
		int res = (int)(d % (long long)n);
		for (int c = 0; c < n; ++c) F[0][c] = ret[0][c];
		for (int day = 1; day <= res; ++day)
			for (int c = 0; c < n; ++c)
				F[day][c] = (F[day-1][(c-day+n)%n]+F[day-1][(c+day)%n])%MOD;
		
		return F[res][0];
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, long long p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	PenguinEmperor *obj;
	int answer;
	obj = new PenguinEmperor();
	clock_t startTime = clock();
	answer = obj->countJourneys(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	
	int p0;
	long long p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 2ll;
	p2 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 4;
	p1 = 3ll;
	p2 = 2;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 36ll;
	p2 = 107374182;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 300;
	p1 = 751ll;
	p2 = 413521250;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 300;
	p1 = 750ll;
	p2 = 0;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 350;
	p1 = 1000000000000000000ll;
	p2 = 667009739;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 5;
	p1 = 7ll;
	p2 = 12;
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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