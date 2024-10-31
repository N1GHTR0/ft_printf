#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_itoa(int n);
int	ft_uitoa(unsigned int n);
int	ft_hextoa(unsigned int n, char c);
int	ft_prpoint(unsigned long long n);
int	ft_strlen(char *str);
int	ft_putstr(char *str);

#endif
