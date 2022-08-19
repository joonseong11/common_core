#include <stdio.h>

void	hi(int *i)
{
	*i = 1;
	(*i)++;
}

int main()
{
	int i;

	hi(&i);
	printf("%d\n", i);
}
