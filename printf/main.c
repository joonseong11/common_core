//#include "./include/ft_printf.h"
//#include <stdio.h>
//
//int main()
//{
//	printf("return : %d", printf(NULL));
//	printf("return : %d", ft_printf(NULL));
//}

#include "./include/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	char *str = malloc(INT_MAX + 2L);
	for (long i = 0; i < INT_MAX + 2L; i++)
		str[i] = '1';
	str[INT_MAX + 1L] = 0;
	//ft_printf("%d\n", ft_printf("%s\n", str));
	printf("%d\n", printf("%s\n", str));
}