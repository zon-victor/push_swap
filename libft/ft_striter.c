#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;

	if (s && f)
	{
		i = -1;
		while (*(s + (++i)) != '\0')
			f((s + i));
	}
}
