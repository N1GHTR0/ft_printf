#include "ft_printf.h"

int	find_hexlen(unsigned int n)
{
	int x;

	x = 0;
	if (n == 0)
		return (1);
	while(n != 0)
	{
		n = n / 16;
		x++;
	}
	return (x);
}

int	hex_translator(int n, char c)
{
	if (n < 10)
		n = n + 48;
	else if (n > 9 && c == 'x')
		n = n + 87;
	else if (n > 9 && c == 'X')
		n = n + 55;
	return (n);
}

int	ft_hextoa(unsigned int n, char c)
{
	char *str;
	unsigned int len;
	int x;

	len = find_hexlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = 48;
	while (len != 0)
	{
		len--;
		x = n % 16;
		str[len] = hex_translator(x, c);
		n = n / 16;
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
