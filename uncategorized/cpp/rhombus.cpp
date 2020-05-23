#include <stdio.h>
using namespace std;

#define algoritma int main()
#define input(n) scanf("%d",&n);
#define traversal(i,a,b) for (int i=a; (a <= b && i <= b) || (a >= b && i >= b); i+=(a <= b ? 1 : -1))
#define repeat(n) for (int _x=0; _x < n; ++_x)
#define output(...) printf(__VA_ARGS__);

int n;

algoritma
{
	input(n)
	traversal(i,1,n)
	{
		repeat(n-i)
			output(" ")
		repeat(2*i-1)
			output("*")
		output("\n")
	}
	traversal(i,n-1,1)
	{
		repeat(n-i)
			output(" ")
		repeat(2*i-1)
			output("*")
		output("\n")
	}
	return 0;
}
