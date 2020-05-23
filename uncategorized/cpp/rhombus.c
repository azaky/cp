#include <stdio.h>

algoritma
{
	input(n)
	traversal(i,1,n)
	{
		repeat(n-i)
			output(' ')
		repeat(2*i-1)
			output('*')
		output('\n')
	}
	return 0;
}
