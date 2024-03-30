#include "main.h"
#include <string.h>
/**
 * sprint - prints s format
 * Return: (str)
 *
 */
int sprint(va_list args)
{
	int len = 0, i = 0;
	char *str;
	str = va_arg(args, char *);
	len = strlen(str);
	if (str != NULL)
	{
		while (i < len)
		{
			_putchar(str[i]);
			i++;
		}
		return(0);
	}
	else
	{
		{
		_putchar('(');
		_putchar('n');
		_putchar('u');
		_putchar('l');
		_putchar('l');
		_putchar(')');
		}
		return(0);
	}
}
