#include "ft_printf.h"

int	find_udigit(unsigned int n)
{
	int x;

	x = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

int	ft_uitoa(unsigned int n)
{
	char *str;
	unsigned int len;

	len = find_udigit(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = 48;
	while (len != 0)
	{
		len--;
		str[len] = (n % 10) + 48;
		n = n / 10;
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
