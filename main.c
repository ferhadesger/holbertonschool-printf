#include <stdio.h>
#include "main.h"
#include <limits.h>

int main(void)
{
	int len;
        int len2;

	_printf("Character:[%c]\n", 'H');
	_printf("Character:[%s]\n", "sdsfdggh");
	_printf("%jdc");
	_printf("%");
	_printf(NULL);
	len = _printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len2);
	_printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));

	return (0);
}
