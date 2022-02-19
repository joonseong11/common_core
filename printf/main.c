
#include <stdio.h>
#include "include/ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	a;

	a = 10;
	printf("^ return of printf : %d\n", printf("%p %p", -9223372036854775808, 9223372036854775807));
	printf("^ return of ft_printf : %d\n", ft_printf("%p %p", -9223372036854775808, 9223372036854775807));
}