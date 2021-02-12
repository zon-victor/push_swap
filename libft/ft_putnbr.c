#include "libft.h"

void	ft_putnbr(int n)
{
	int		i;
	int		a[10];

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (!n)
		ft_putchar('0');
	while (n)
	{
		*(a + i) = n % 10;
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(*(a + i) + 48);
	}
}
