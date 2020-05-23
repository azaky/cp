#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0));
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 100000; ++j) {
			putchar('a' + (rand() % 26));
		}
		putchar('\n');
	}
	
	return 0;
}