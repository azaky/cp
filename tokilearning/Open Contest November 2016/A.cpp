#include <bits/stdc++.h>
using namespace std;

int ntc, v;
char card[10], s;

int main () {
	scanf("%d", &ntc);
	while (ntc--) {
		scanf("%s", card);
		if (strlen(card) == 2) {
			if ('2' <= card[0] && card[0] <= '9') {
				v = card[0] - '0';
			} else switch (card[0]) {
				case 'J': v = 11; break;
				case 'Q': v = 12; break;
				case 'K': v = 13; break;
				case 'A': v = 1; break;
				default: assert(false);
			}
			s = card[1];
		} else if (strlen(card) == 3) {
			v = 10;
			s = card[2];
			assert(card[0] == '1' && card[1] == '0');
		}
		if (((string)"CDHS").find(s) == string::npos) {
			assert(false);
		}

		int l = v, r = v;
		for (int i = 0; i < 12; ++i) {
			int x = r + 1;
			if (x > 13 || (l > 1 && (rand() & 1))) {
				x = l - 1;
			}
			if (x > r) {
				r++;
			} else {
				l--;
			}
			if (2 <= x && x <= 10) {
				printf("%d", x);
			} else switch (x) {
				case 1: putchar('A'); break;
				case 11: putchar('J'); break;
				case 12: putchar('Q'); break;
				case 13: putchar('K'); break;
				default: printf("x = %d\n", x); assert(false);
			}
			putchar(s);
			if (i < 11) {
				putchar(' ');
			} else {
				putchar('\n');
			}
		}
	}

	return 0;
}