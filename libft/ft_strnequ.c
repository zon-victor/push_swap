#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
		if (!strncmp(s1, s2, n))
			return (1);
	return (0);
}
