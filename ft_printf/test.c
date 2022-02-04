//
// Created by Junseong Jeon on 1/23/22.
//

#include <stdio.h>
#include <stdarg.h>

void	printnumbers(int args, ...)
{
	va_list	ap;

	va_start(ap, args);
	for (int i = 0; i < args; i++)
	{
		int	num = va_arg(ap, int);
		printf("%d ", num);
	}
	va_end(ap);
	printf("\n");
}

int	main(void)
{
	printnumbers(1, 10);
	printnumbers(2, 10, 20);
	printnumbers(3, 10, 20, 30);
	printnumbers(4, 10, 20, 30, 40);
	return (0);
}
