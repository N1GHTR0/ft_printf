#include "ft_printf.h"

int	find_digit(int n)
{
	int dig;

	dig = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n = n / 10;
		dig++;
	}
	return (dig);
}

int	ft_itoa(int n)
{
	long nb;
	char *str;
	int len;

	nb = n;
	len = find_digit(nb);
	if (nb < 0)
		len++;
	str = (char *)malloc(len * (sizeof(char) + 1));
	str[len] = '\0';
	len--;
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = 48;
	while (nb != 0)
	{
		str[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
int main()
{
	int x = 45654;
	ft_itoa(x);
}
