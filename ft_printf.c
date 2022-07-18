#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int	ft_putstr(char *str)
{
	int	i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_puthexa(unsigned int i, int base)
{
	char	*base_set = "0123456789abcdef";
	int		count = 0;
	int		n;

	if (i / base > 0)
		count += ft_puthexa(i / base, base);
	n = i % base;
	count += write(1, &base_set[n], 1);
	return (count);
}

int	ft_putnbr(int i)
{
	int	count = 0;

	if (i < 0)
	{
		count += write(1, "-", 1);
		i *= -1;
	}
	count += ft_puthexa(i, 10);
	return (count);
}
int	ft_printf(char *format, ...)
{
	int			count = 0;
	va_list		args;
	int			i = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			if (format[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
			if (format[i] == 'x')
				count += ft_puthexa(va_arg(args, unsigned int), 16);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	*str = "42 Lausanne";
	char	*empty = NULL;
	int		integer = -2147483649;
	int		hexa = 42;

	printf(" : (%d) bytes printed\n", ft_printf("(%s)", str));
	printf(" : (%d) bytes printed\n", printf("(%s)", str));
	printf(" : (%d) bytes printed\n", ft_printf("(%s)", empty));
	printf(" : (%d) bytes printed\n", printf("(%s)", empty));
	printf(" : (%d) bytes printed\n", ft_printf("(%d)", integer));
	printf(" : (%d) bytes printed\n", printf("(%d)", integer));
	printf(" : (%d) bytes printed\n", ft_printf("(%x)", hexa));
	printf(" : (%d) bytes printed\n", printf("(%x)", hexa));
	return (0);
}
