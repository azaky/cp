#include <stdio.h>
#include <algorithm>

using namespace std;

int n, t, arr[10000], ans = 0;

int main () {
scanf ("%d %d", &n, &t);
for (int i = 0; i < n; i ++)
scanf ("%d", &arr[n]);

while (next_permutation (arr, arr + n)) {
bool bener = 1;
for (int i = 0; i < n - 1; i ++)
if (arr[i] - arr[i + 1] > t)
bener = 0;
if (bener)
ans ++;
}

printf ("%d\n", ans);

return 0;
}
