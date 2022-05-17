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

//int main()
//{
//	char *str = malloc(INT_MAX + 2L);
//	for (long i = 0; i < INT_MAX + 2L; i++)
//		str[i] = '1';
//	str[INT_MAX + 1L] = 0;
//	//ft_printf("%d\n", ft_printf("%s\n", str));
//	printf("%d\n", printf("%s\n", str));
//}

int main()
{
	int a, b, c, d, e, f, g, h, i, j;

	a = 10;
	b = 20;
	c= 30;
	d=40;
	e=50;
	f=60;
	g=70;
	h=80;
	i=90;
	j=100;
	printf("_printf : %d \n", printf("___printf : %p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n", &a,&b,&c,&d,&e,&f,&g,&h,&i,&j));
	printf("ft_printf : %d \n", ft_printf("ft_printf : %p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n%p\n", &a,&b,&c,&d,&e,&f,&g,&h,&i,&j));
}