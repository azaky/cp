#include <iostream>
using namespace std;

typedef unsigned long long uLL;
#define INF 1000000000000000000LL

int main(){
	uLL cot = 0;
	for (uLL x = 0, tx = 1; tx < INF; ++x, tx *= 2LL)
		for (uLL y = 0, ty = tx; ty < INF; ++y, ty *= 3LL)
			for (uLL z = 0, tz = ty; tz < INF; ++z, tz *= 5LL)
				for (uLL w = 0, tw = tz; tw < INF; ++w, tw *= 3LL)
					++cot;
	cout << cot << endl;
	
	return 0;
}
