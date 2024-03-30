#include "main.h"

/**
 * cprint - prints c format
 * Return: (char)
 *
 */

int cprint(va_list args)
{

char array;
array = va_arg(args, int);
_putchar(array);
return(1);
}
