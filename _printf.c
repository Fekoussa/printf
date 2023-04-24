#include "main.h"

/**
 * next_char - checks the next character after the %
 * @i: The character
 * @agp: argument pointer
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int	next_char(va_list agp, char i)
{
	int	count;

	count = 0;
	if (i == '%')
		count += _putchar('%');
	else if (i == 'c')
		count += _putchar(va_arg(agp, int));
	else if (i == 's')
		count += _putstr(va_arg(agp, char *));
	else if (i == 'r')
                count += print_rev(va_arg(agp, char *));
	else if (i == 'd' || i == 'i')
		count += _putnbr(va_arg(agp, int));
	else if (i == 'p')
        {
                count += _putstr("0x");
                count += _convert(va_arg(agp, unsigned long));
	}
	return (count);
}

/**
 * _printf - the main function
 * @format: the string
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printf(const char *format, ...)
{
	va_list	agp;
	int	i;
	int	count;

	va_start(agp, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += next_char(agp, format[i]);
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(agp);
	return (count);
}
