#include "ft_printf.h"

int	find_ptshexlen(unsigned long long n)
{
	int x;

	x = 0;
	if (n == 0)
	       return (1);	
	while (n != 0)
	{
		n = n / 16;
		x++;
	}
	return (x);
}
int	prhex_translator(int n)
{
	if (n < 10)
		n = n + 48;
	else if (n > 9)
		n = n + 87;
	return (n);
}
int	ft_prpoint(unsigned long long n)
{
	char	*str;
	int	len;

	len = find_ptshexlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = 48;
	while (len > 0)
	{
		len--;
		str[len] = prhex_translator(n % 16);
		n = n / 16;
	}
	write(1, "0x", 2);
	ft_putstr(str);
	return (ft_strlen(str) + 2);
}
