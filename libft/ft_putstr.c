#include "libft.h"

void ft_putstr(char const *str)
{
	while (*str)
		write(1, str++, 1);
}
