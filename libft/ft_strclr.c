#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;

	if (s)
	{
		i = ft_strlen(s);
		while (i >= 0)
		{
			s[i] = '\0';
			i--;
		}
	}
}
