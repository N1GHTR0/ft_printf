#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int ft_values(va_list values, char value)
{
	int x;

	x = 0;
	if (value == 'c')
		x += ft_putchar(va_arg(values, int));
	if (value == 'd' || value == 'i')
		x += ft_itoa(va_arg(values, int));
	if (value == 's')
		x += ft_putstr(va_arg(values, char*));
	if (value == 'u')
		x += ft_uitoa(va_arg(values, unsigned int));
	if (value == 'x' || value == 'X')
		x += ft_hextoa(va_arg(values, unsigned int), value);
	if (value == 'p')
		x += ft_prpoint(va_arg(values, unsigned long long));
	if (value == '%')
		x += ft_putpercent();
	return (x);
}

int	ft_printf(const char *str, ...)
{
	va_list	values;
	int x;
	int len;

	x = 0;
	len = 0;
	va_start(values, str);
	while (str[x])
	{
		if (str[x] == '%')
		{
			len += ft_values(values, str[x + 1]);
			x++;
		}
		else
			len += ft_putchar(str[x]);
		x++;
	}
	va_end(values);
	return (len);}
