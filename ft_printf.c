#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(unsigned int i, int base)
{
	char	*base_set;
	int		count;
	int		n;

	base_set = "0123456789abcdef";
	count = 0;
	if (i / base > 0)
		count += ft_putnbr(i / base, base);
	n = i % base;
	count += ft_putchar(base_set[n]);
	return (count);
}

int	ft_putint(int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		count += ft_putchar('-');
		i *= -1;
	}
	count += ft_putnbr(i, 10);
	return (count);
}

int	ft_printf(char *format, ...)
{
	int			count;
	va_list		args;
	int			i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			if (format[i] == 'd')
				count += ft_putint(va_arg(args, int));
			if (format[i] == 'x')
				count += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	*str = "42";
	char	*empty = NULL;
	int		integer = 32;
	int		hexadecimal = 32;

	printf(" : (%d) bytes printed\n", ft_printf("(%s)", str));
	printf(" : (%d) bytes printed\n", ft_printf("(%s)", empty));
	printf(" : (%d) bytes printed\n", ft_printf("(%d)", integer));
	printf(" : (%d) bytes printed\n", ft_printf("(%x)", hexadecimal));
	return (0);
}
