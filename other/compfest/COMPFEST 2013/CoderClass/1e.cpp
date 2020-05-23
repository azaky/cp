#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

char cc;
int n, rep, i;

char ending[] = {'C','O','M','P','F','E','S','T'};


int main()
{	
	i = n = rep = 0;
	
	while (scanf("%c", &cc) != EOF)
	{
		if (cc >= 'A' && cc <= 'Z')
		{
			++rep;
			
			if (cc == ending[i])
			{
				++i;
				
				if (i >= 8)
				{				
						printf("%d %d\n", n, rep-8);
						i = n = rep = 0;
				}
			}
			else
			{
				i = 0;
			}
		}
		else
		if (cc >= 'a' && cc <= 'z')
		{
			++n;
			i = 0;
		}
	}
	return 0;
}
