#include "main.h"

/**
 * next_char - checks the next character after the %
 * @i: The character
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
	else if (i == 'd' || i == 'i')
		count += _putnbr(va_arg(agp, int));
	return (count);
}

/**
 * _printf - the main function
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

/*
int main(void)
{
	int	len;
	int	len2;
	len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
     _printf("*Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("*Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("*Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("*Let's try to printf a simple sentence.\n");
    printf("Let's try to printf a simple sentence.\n");
    _printf("*Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("*String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
}
*/
