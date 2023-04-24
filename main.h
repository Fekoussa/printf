#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

int	_printf(const char *format, ...);
int	_putstr(char *s);
int	_putchar(char c);
int     _putnbr(int n);

#endif /* MAIN_H */
