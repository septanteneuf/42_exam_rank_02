#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int    ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int    ft_putstr(char *s)
{
    int    count;

    count = 0;
   if (!s)
   {
       write(1, "(null)", 6);
       return (count + 6);
   }
    while (s[count])
    {
        count += write(1, &s[count], 1);
    }
    return (count);
}

int    ft_putnbr(int n)
{
    unsigned int    i;
    unsigned int    count;

    count = 0;
    if (n < 0)
    {
        count += ft_putchar('-');
        i = -n;
    }
    else
        i = n;
    if (i > 9)
    {
        count += ft_putnbr(i / 10);
        i %= 10;
    }
    ft_putchar(i + '0');
    count++;
    return (count);
}

int    ft_puthexa(unsigned int n, const char format)
{
    int    count;

    count = 0;
    if (n >= 16)
    {
        count += ft_puthexa(n / 16, format);
        count += ft_puthexa(n % 16, format);
    }
    else
    {
        if (n <= 9)
            ft_putchar(n + '0');
        else
            ft_putchar(n - 10 + format - ('x' - 'a'));
        count = 1;
    }
    return (count);
}

int	ft_formats(va_list args, const char *format)
{
	int	count;

	count = 0;
	if (format[1] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[1] == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (format[1] == 'x')
		count += ft_puthexa(va_arg(args, unsigned int), format[1]);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		count;
	char	*str;

	str = (char *)s;
	i = 0;
	count = 0;
	va_start(args, s);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_formats(args, &str[i]);
			i++;
		}
		else
		{
			count += ft_putchar(str[i]);
		}
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