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
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

#define A first
#define B second
#define MP make_pair
#define PB push_back

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

/* -------------- end of azaky's template -------------- */

/** Range Minimum/Maximum Query
 * usage:
 * RMQ rmq(n);							// Initialize rmq with size n. All values will be set
 * rmq.init(n);							// to zero.
 * RMQ rmq(a.begin(), a.end());			// Initialize the rmq with values of a.
 * rmq.init(a.begin(), a.end());		// 
 * 
 * rmq.update(pos, value);				// Update the value in index pos.
 * rmq.updateRange(left, right, value); // Update the value in range [left..right].
 * rmq.add(pos, value);					// Add value at index pos.
 * rmq.addRange(left, right, value);	// Add value to all elements in [left..right].
 * 
 * int vmax = rmq.max(left, right);		// Find max value in [left..right].
 * int vmin = rmq.min(left, right);		// Find min value in [left..right].
 * int imax = rmq.idxMax(left, right);	// Find the index of largest value in [left..right].
 *										// If it is not unique, the leftmost index is returned.
 * int imin = rmq.idxMin(left, right);	// Find the index of smallest value in [left..right].
 *										// If it is not unique, the leftmost index is returned.
 * 
 * note:
 * * All indices are 1-based. Valid indices are from 1 to n.
 * * Initialization takes O(n), and all updates and queries take O(log(n)). Memory complexity
 *   will be O(n) (13*n to be exact).
 * * While using methods with range [left..right], make sure that left <= right and the range
 *   is within [1..n]. If the range is invalid, unexpected behavior may occur.
 */
struct RMQ {
	// data type to hold information in each node of the tree
	struct RMQInfo {
		RMQInfo() : imin(0), imax(0), vmin(0), vmax(0) {}
		int imin, imax; // index of smallest and largest values
		int vmin, vmax; // the smallest and largest value itself
		void combine(RMQInfo &left, RMQInfo &right) {
			if (left.vmin <= right.vmin) {
				this->vmin = left.vmin;
				this->imin = left.imin;
			}
			else {
				this->vmin = right.vmin;
				this->imin = right.imin;
			}
			if (left.vmax >= right.vmax) {
				this->vmax = left.vmax;
				this->imax = left.imax;
			}
			else {
				this->vmax = right.vmax;
				this->imax = right.imax;
			}
		}
	};

	RMQ() {
		this->n = 0;
	}
	RMQ(int n) {
		init(n);
	}
	template <class Iterator> RMQ(Iterator begin, Iterator end) {
		init(begin, end);
	}
	void init(int n, bool reset = true) {
		// this->n will be set to the smallest power of 2 greater/equal to n
		this->n = 1;
		while (this->n < n) this->n <<= 1;

		// resize the containers
		if (reset) a.clear();
		a.resize(this->n + 1);
		rmq.resize(this->n << 1);
		change.resize(this->n << 1);

		// reset the value
		build(1, 1, this->n);
	}
	template <typename Iterator> void init(Iterator begin, Iterator end) {
		// insert values into a
		a.clear();
		a.push_back(0);
		while (begin != end) {
			a.push_back(*begin);
			begin++;
		}
		int n = a.size() - 1;

		init(n, false);
	}
	void build(int v, int l, int r) {
		if (l == r) {
			rmq[v].imin = rmq[v].imax = l;
			rmq[v].vmin = rmq[v].vmax = a[l];
		}
		else {
			int vl = v << 1;
			int vr = vl | 1;
			int m = (l + r) >> 1;
			build(vl, l, m);
			build(vr, m+1, r);
			rmq[v].combine(rmq[vl], rmq[vr]);
		}
	}

	void addChange(int v, int l, int r, pair<int,int> c) {
		if (change[v].first == 0 || c.first == 1) {
			change[v] = c;
		}
		else if (c.first == 2) {
			change[v].second += c.second;
		}
	}
	void applyChanges(int v, int l, int r) {
		if (change[v].first) {
			int vl = v << 1;
			int vr = vl | 1;
			int m = (l + r) >> 1;
			// apply update
			if (change[v].first == 1) {
				rmq[v].vmin = rmq[v].vmax = change[v].second;
				rmq[v].imin = rmq[v].imax = l;
			}
			// apply add
			else if (change[v].first == 2) {
				rmq[v].vmin += change[v].second;
				rmq[v].vmax += change[v].second;
			}
			if (l < r) {
				// propagate change to children
				addChange(vl, l, m, change[v]);
				addChange(vr, m+1, r, change[v]);
			}
			// reset
			change[v].first = 0;
		}
	}

	void update(int pos, int value) {
		update(1, 1, n, pos, pos, value, 1);
	}
	void updateRange(int left, int right, int value) {
		update(1, 1, n, left, right, value, 1);
	}
	void add(int pos, int value) {
		update(1, 1, n, pos, pos, value, 2);
	}
	void addRange(int left, int right, int value) {
		update(1, 1, n, left, right, value, 2);
	}
	void update(int v, int l, int r, int left, int right, int value, int type) {
		// apply changes to current node
		applyChanges(v, l, r);

		int vl = v << 1;
		int vr = vl | 1;
		int m = (l + r) >> 1;
		if (left <= l && r <= right) {
			if (type == 1) {
				rmq[v].imax = rmq[v].imin = l;
				rmq[v].vmax = rmq[v].vmin = value;
			}
			else if (type == 2) {
				rmq[v].vmax += value;
				rmq[v].vmin += value;
			}
			if (l < r) {
				addChange(vl, l, m, make_pair(type, value));
				addChange(vr, m+1, r, make_pair(type, value));
			}
		}
		else if (l <= right && left <= r) {
			update(vl, l, m, left, right, value, type);
			update(vr, m+1, r, left, right, value, type);
			rmq[v].combine(rmq[vl], rmq[vr]);
		}
	}

	pair<int, int> min(int left, int right) {
		RMQInfo info = query(1, 1, n, left, right);
		return make_pair(info.vmin, info.imin);
	}
	pair<int, int> max(int left, int right) {
		RMQInfo info = query(1, 1, n, left, right);
		return make_pair(info.vmax, info.imax);
	}
	int valMin(int left, int right) {
		return query(1, 1, n, left, right).vmin;
	}
	int valMax(int left, int right) {
		return query(1, 1, n, left, right).vmax;
	}
	int idxMin(int left, int right) {
		return query(1, 1, n, left, right).imin;
	}
	int idxMax(int left, int right) {
		return query(1, 1, n, left, right).imax;
	}
	RMQInfo query(int v, int l, int r, int left, int right) {
		applyChanges(v, l, r);
		if (left <= l && r <= right) {
			return rmq[v];
		}
		else {
			int vl = v << 1;
			int vr = vl | 1;
			int m = (l + r) >> 1;
			RMQInfo infoLeft, infoRight, result;
			if (left <= m) {
				infoLeft = query(vl, l, m, left, right);
				if (right <= m) {
					return infoLeft;
				}
			}
			if (right > m) {
				infoRight = query(vr, m+1, r, left, right);
				if (left > m) {
					return infoRight;
				}
			}
			result.combine(infoLeft, infoRight);
			return result;
		}
	}

	int n;
	vector<RMQInfo> rmq;
	vector<pair<int, int> > change;
	vector<int> a;
};

class OneDimensionalRobot {
public:
	long long theSum(vector <string> commands1, vector <string> commands2, int minA, int maxA, int minB, int maxB) {
		string s = "";
		FORIT(it, commands1) s += *it;
		FORIT(it, commands2) s += *it;
		int n = SZ(s);

		long long ans = 0;
		for (int a = minA; a <= maxA; ++a) {
			vector<int> pos(n);
			for (int i = 0; i < n; ++i) {
				int replacement = s[i] == 'L' ? -1 : +1;
				if (i) {
					pos[i] = replacement + pos[i - 1];
				} else {
					pos[i] = replacement;
				}
				if (pos[i] < -a) pos[i] = -a;
				if (pos[i] > maxB) pos[i] = maxB;
			}
			RMQ rmq(ALL(pos));
			for (int b = maxB; b >= minB; --b) {
				int ansNow = rmq.valMax(n, n);
				//printf("ans[%d..%d] = %d\n", -a, b, ansNow);
				ans += (long long)ansNow;
				bool changed = true;
				while (changed) {
					pair<int, int> qmax = rmq.max(1, n);
					if (qmax.A == b) {
						rmq.addRange(qmax.B, n, -1);
						pair<int, int> qmin = rmq.min(1, n);
						if (qmin.A < -a) {
							rmq.addRange(qmin.B, n, +1);
						}
					} else break;
				}
			}
		}
		return ans;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, vector <string> p1, int p2, int p3, int p4, int p5, bool hasAnswer, long long p6) {
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
	cout << "}" << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	OneDimensionalRobot *obj;
	long long answer;
	obj = new OneDimensionalRobot();
	clock_t startTime = clock();
	answer = obj->theSum(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	vector <string> p0;
	vector <string> p1;
	int p2;
	int p3;
	int p4;
	int p5;
	long long p6;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"RRLRLLRRLL"};
	p1 = {};
	p2 = 2;
	p3 = 2;
	p4 = 1;
	p5 = 1;
	p6 = -1ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"RLRRLRLLRRLLLRLRLLRL"};
	p1 = {};
	p2 = 2;
	p3 = 3;
	p4 = 1;
	p5 = 2;
	p6 = -9ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"RLRRLRRRLLLLLRLRRLLLLRRRRLLRLLRLRRRLLRRLRLLRLLRRRL","LRLRLRLLRLLLRRLLRLRRLLLRLLRLLRLLLLRRRLLRLRRRLLRRRR"};
	p1 = {};
	p2 = 3;
	p3 = 5;
	p4 = 2;
	p5 = 4;
	p6 = 17ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"LRRRRLLLRLRLLLRRLLLRRRLLLLLLRLLRLRRLLRLLLLLRRLLLLR","RLLLLRRRLRLLRLRRLRLRRLLRRLRRRRLLLRRLLRRLRRRLLRLRLL","RLRRRLLLRLRRLRLLLRLLLLRRRLLRLRRLRRRRRLRLLLLLRLLRLR","LLRLRRRLRLLLRLLRRLRLRLRLRRRLLRRRLRRRLRLRLRRLLRLRLR","LRRRRRLLLRLLRRLLRRRRLLLLRRRRLRRRLLLRRLLRRRRRRLLRLR","LRLLRLRLLLLRLLLRLLRRRRLRRLLLLRRRLRRLRLRRLLLRLRLRLR"};
	p1 = {};
	p2 = 1;
	p3 = 608;
	p4 = 1;
	p5 = 608;
	p6 = -1417089ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"LRRRRRLRRRLLLRLLLLRLRLLLRLLRLLRRLRRLRRLLRLLLRLLLLL","RRRLRLRRLLLRLLRRRRLLLRLRLRRLLLRLRRLLRLRLRLLLRLRLLR","RLLLLLRLRRLLLRRRLLRLRLLRRLLLLRRLRLRLRRRLRRLRRLLRLL","RRLRLRLRLLLLRRRRLLLRLLRLLLLRLLLRLLLRLRLRLRRRLRRRRR","LRRLRLLRLLRRLRRLLRLRLRRLRRLLLLLLLRRRLRLLRRRRRRLRRR","RLRLLLRLRLLRRLRLLLLLRLRRLRLLLRRRLRLRLRLLLRLRLLLRRL","LRLRRLRRLLLRRLLLRRLRRRLLLLLLLLLLLLLRLLLRLLLRLLLRLL","LLLRLRRRRLRRLLRLRLLLRLLLRRLRRLRLRRLLLLRRLRRRLLLRLR","RLRLLRRRRRLLLRLRRLRLLRLRLLLRLLLRRLRLRLRRRLRRLLRRRL","RLLLLRRRLRRLRRRLRRRLRLLRRRLLLRRLRLLLLLLLLRLLRLLRRL","RRLLLRRLRLLRLLLRRRLRRLLLRLLRLRRRLRRRRRLRRRRRLRLLLR","LLLLRLRLRLLLLRLLRRLLLRLLLRLLLLRLRRRLRRRLRLRLRLRLRR","LLLLRLRLRLRLRLLLRLLRLLRLLLLLLLRRLRRRLRRLLLLLRLLLLL","RRLLRLLLRRLRLLLLRRRRLLLLRLLRLLLLLRLLLLRRLRLLRLRLLR","LRRLLLLRLLRRLRRRRRLLRLLLRLRLLLLLRLLRRLLLLLLRLRLLLR","LRLLRRLLLRLRLLLLRLLRRLLLRLLLRLRLRRLRRRLLLLRRRLRLLL","LLLRRLRLLLLRLRRLRLRLRRRRLLLLLLLRLLLRRLRRLLLLRLLLLR","RRLRLLLRLRRLRRRLRLLRRLLLLLRLRLRRLRLLLLLLLLLRRLRRLL","LRRLLLLRLLLRRRLLLRLLRRLLLRRLLLRRLLLRRLLRLRRRLL"
			"RLLL","LRRRRLLRRLLLLLRLLLRLRRLLRLLLLLLLRRRLLLRLLLLLLLRLRR","LLRRRLRLRLLRLRRLRLRRLLRLLLLLLRRLLRLRLRLLLLRLRLRRRR","RRLRLLLLLRLRRLLLLLRLLLRLLLRLLRLLLLLRLLLRRLRRLLLLRR","RLLLRLLLLLLLLLRRRLLLRRRLRRLRRRLLLRLRLLRLLLRLLRRRRL","LRLLLRRRLRLRRLLRLLRLRRLRLRLLLLRLLLRLLLLRRRRLRLRLRR","RLRRLLLLLRRLRLRLRRRLLLRLRRRLRLRLRLLRRLLLLRRLLRRRLL","RLLRRLRRLRLRLRLLLLLLRLLLLRRLLRLRLRRLLRLRRLLRLRLLLR","LRLLLLRLRLLLRLRLLRLLRRLLRLLLLLRRLRLRRLLLRLLLLLLRLL","LRLRLRLLLLLLRRLLLRLLRLRLRRRRLLLLLRLLLLRLLRRLRLLLLL","LLRLRRLLLRLLLRRLRLLRLRLLLLLLRLLRLRLRRLRLRLLLRRLLLR","LLLLLLLLRRLLLLRLRRRLRRLLRRLRLLLLRLLRLRRLLLLLRRLLLL","RRLLLLRRRRLLLLLRRLLLRLRLRRLLLLLLLRLRRRLRLLRLLLLLRL","RLLRRLRRLRRLRLLRLLLRLRRRLRRLLLLLRRRLLRRLRLRLLRLLRL","LRLRLLLRLLLRLRRRRRLRLRRLRLRLLLRRLRLLRLRLLLLRLLLLLR","LLLLRRRRLLLRLLRRLLLLLRRLLLRLRRRLRLRLRRLLRLRRLLRLLL","RLLRLLLRRLRRRRLLRLRRRRRLRLLRLLLLRRLLRLLLLRRLRLLLRL","LRRLLLLRRLLRLLLLLRRLRLRRLRLLRRRRRLRLLLRLLRLRRLLLRR","LLRRLLRLLRRLRRLRLRLLLRRRRLLLRLLRRLLLLRRLRLLRLLLLRR","LRLLRRRRLLRLRLLLLLLLLLRLLRLLLRLRLRRRLLLL"
			"RRRRLRLLLR","RRLLLLLLLLRRLLRRRLLRLLLLRLLLLLRLRLLLLRLRRRRRLRLLRL","RRRLLRRLLLLLRRRLLLLLLLRLLLRRLLRLRRLLLRLRLLLLRLRLLL","LLRRRRLRLRRRRRLRRRRRRRLLLLLLLLLLRRRRLLLRLRLLLLRRLL","RLLLLRLLLRRLRRLRRLLRRLLLLLRLLRRRRRRLLLLRLLLLLRRLLL","RLRLLRRRLLLLLRRRLLLRRLLLLLRRLLRRLRRRRLRRLLRRRLLLRL","LLLRLLRLRRLLRRRLRRRLLLRLLLLLLRRLLRRRLLRRRRLRLLLRRL","RLLLRLLRLLRLRLRLRLRRLLLLLLLRLRRLLRLRLRRRLLLRLLRRLR","LLRLRLRLRLLLRRLLLRRLRRLLLLRRLLRLLLRLLRRLLRRRLRRLRL","RRLRLRRLRRRLLLRRRLRRRLLLLLLLLLRRRRLRRLRRRLRLRRLRRL","LLLRRLRLLRLRLLLRRLRRLLRLLLLRRLRRLRRLLLLRLLRLRLRRLL","RLRLLLLLLRLRRLLRRRLLLRRLLRRLRLRRLLLRLLLLLRLRRLRLRR","LLLLRRRRRLLLRLLRLRRLLRRRLRLLRLLLRLLLLRLRRRRLRRLLLL"};
	p1 = {"LLLLRRRLRLLLRRLRLRRLRLLLLLLLRRLRLRRLLRRLLRLRRRRLRL","LLLRRLLRLRLLRLLLRLLLLRLLLLLRLLLLRRLRLRLRRLLLRRLLLL","RRLLLRRRLRLLRLRLLRLLLRLLLRLLLLLLLRLLLLLLLLLRLLRLLR","LLRLLRRRLLRLLRLRLRRLRLLLLLLLRLLLRRLRLLLLLLLLLLRRRL","LLRRRRLLRLLLRRLLLLLLRLLLRRLLLRLRRRRLLLRRLLRLRLRLLL","LLLRLLLRLLLLRLLLLLRRLLLRRLLLRLRRRRLLLRRLLLLLLLRLRL","RLRRLRRRRRLRLRLLLRLRRRRLLRLRLLLLLLLLLLRRLLLLRRRLLL","RRRLRLLRRRLLRRLLRLLLRLRLRRRLLRLLLLRLLRRRRLRRLLLRLL","RLLRLLRLLLLLLRLLLRLLLLLRRRLRLRRRLLRRLRRRLLRRRRLLLR","RRLRRRLLRLLLLRLRRLRLLLLLRLRRRLLLLLLRLLRLLRLLLRLLLL","LLLRLLLRRLRLLLLLLLLRLLLLLLLLLRRLLLRLLRLLRLLLLLRLRR","LRRRLLRRRRLRRLRLLRRRLLLLRRLRRLRRLRLLLLLLRLRRLLLRLL","RLLLRRRRLLRLRLLRLLLRLLLRLLRRRLLRLLRRLLLLLLLRRRRRRL","LLRRRLRLLRRRLRLLLRLRLLLLLRRLLRLLRLLLRLRLRLLRLLRLRR","LLRLRRRRLLRRLLLRRLLRLLLLLLLRRLRLRLLRRLLLLRRRLLRRLR","LRLLRLLRLLRLLLLLRLLRLLRLLRLRLLRLLLRLRLRLLLLLRLLLRR","LRRRLRLLRLLRLLRRRLRRLRLLLRLRLLLLLLLLLRLRLRRRRRLRLL","LLLLLLRLRLLLLRRRLRLLRRRRLRLRLLLLLRRLRRLLRRLLLRLLRL","LRLRLLLLLLRLLLLLLLLLRLLLRLLRLLRLRRRRLRRRRLRLRL"
			"LLLL","RLLLLLLRLRLLRRLRLLRLLRLLRLRLRRRLLRRLRLRLRRLLRRLRLR","LRRRLRLLRLLLLLRLRLRLLLRLLLLLLRRLRLLLRLRLLRLLLLLRRL","LRLLLRRLRLLLRLRRLLRLRLLLLLLRLLLLRRRLLLLRRRRLLRRRRL","LRRLRLRLRRRRRRLRLLLRRRLLLRLLRRLLRLLRRLLRLLLRRRRLRL","LLRLLRLRLRLLLRRLLLRLRLLLRLRRRLRLRLLLRRLLLRLRRLRLLR","RRLLLLLLLLLLRRRLLLRRLLLLLRRLLLLRLRRLRLRLLLLLRRLLRL","LRRRLLRLLLRRRLLLLRLRLLRRLLLRRRRRLLLLRRRLLLRRRLLLRL","LRRLLLRLLRRLLLRLLRLRLRRLLLLRRRLLRLLLRLRLLRLLRLLLLL","LRLLRRLLLLLLRRRLLRLLLLLLLLRRRLLLRLLRRRRLLLLLLLRLLL","LLLRLLRRLLRLLRLRLLRRRLLLLLLRRLLLLLLLLLLLRLLLLLLRLR","LLLLLRRRRLLLLLRRRRLLRLRRLLLLLLLLRRLLLRRRLRRLLRLRRL","RLRLRLRRLLRLLRRRRLLRLLLLLRLRLLRLLLLLRLRRRRRLRRRLRR","RLRRLRRRLLRLLRLRLRLLLLRLRLLLRLRRRLLLRRLLRRLLRLRRLL","RLLLRRRRRLLLLLLLLLRRLRRLLLRLLLRLLLLRRLRLLLLLRLLLRR","LLLRRRLLLLLLLLLRRLRLRLLLLRLLRLRRLLRRRLRRRRLRRRLLLL","LRRLLLLLRLRLRLLRRRRLLLLRLRRLLRRRRLRLRLRRRRRRLRLLRL","RRRLLRLLRLLRLRRLRRLLLLLRRLLLRLLRRLLLLRRRLRLRLRRLRL","LRLRLLRLLRRRRLLRRRLLLLRRLRLLLLLLRRRLLRRLLLLLLRRRLL","RRRRRLRLRLLRLLLRLRLRLLLLRLLLLRLRLLRLLRLL"
			"RLLRRRLLRL","RLRRRLLLRLRLRRLLRLLLLLLLLLLRRLRRLRLLRRLRRLLRLRLLLL","RRLRLRLRRLLLLLLRRLLLRRLRLLLLLLLLLLRLRLLLRLLRRLLLLR","RLLLRLRRLLRLLRRRRLLRLLRLRLLLRLRLRRLLLLRLRLLRRRLLLL","RLRLLRLLRRRLLLLRLLLRLLRLRRLLLLRRLRRRLRRRLLRLRRRRLR","LLRLRLRLLRLRRRRRRLLLLLLLRLLLRLRLRLLRRRLRRLLLRLLRRL","RLLRLLRRLRRLLLRLLRLLLLRRLLRLRRRLRRLRRLLRRRRRLLRLRL","LRRLLLLLLLLLLRLLLLLRRLLLRRRRLRLRRLLLRRRRRRLRRRLRLL","RRRLRLLLLLLLLRRLLRLRLRLRLLLLLRRLLRLLLLLRLLRRLLLRLL","RLLLLRLRLLLLLRRLLLLRRLLRRLLLLLLRLLRLRLRLLRLLLLRLRR","LLLRLRLRRRLRLLLRRLLLRLRLLRLRLLLLLLLLLRRLRLLLLRRRLR","LRLRLLLLLRRLLRLRLLRLLLLRRLRRRLRRLRRRRLLLRRRLLRRLLL","LRLLRRLRRLLLLRLLLLLLLLLLRLLLLLRRRLRLLLLLLLRLLRLLRR"};
	p2 = 1;
	p3 = 5000;
	p4 = 1;
	p5 = 5000;
	p6 = -19478907170ll;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
