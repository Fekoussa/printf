#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _putstr - writes string to stdout
 * @s: string to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int	_putstr(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (!s)
	{
		_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		count += _putchar(s[i]);
		i++;
	}
	return (count);
}
/**
 * _putnbr - writes the number to stdout
 * @n: The number to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int	_putnbr(int n)
{
	int	count;

	count = 0;
	if (n >= 0 && n <= 9)
		count += _putchar(n + '0');
	else if (n > 9)
	{
		count += _putnbr(n / 10);
		count += _putnbr(n % 10);
	}
	else if (n < 0 && n != -2147483648)
	{
		count += _putchar('-');
		count += _putnbr(n * (-1));
	}
	else if (n == -2147483648)
	{
		_putchar('-');
		_putnbr(2);
		_putnbr(147483648);
		return (count + 11);
	}
	return (count);
}

/**
 * _convert - writes the number to stdout
 * @i: The number to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int	_convert(unsigned long i)
{
	char    *s;
	int             count;
	
	s = "0123456789abcdef";
	count = 0;
	if (i >= 0 && i <= 15)
		count += ft_putchar(s[i]);
	if (i > 15)
	{
		count += ft_convert(i / 16);
		count += ft_convert(i % 16);
	}
	return (count);
}
