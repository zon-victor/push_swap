#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	int		len;

	len = -1;
	while (s1[++len])
		;
	c = (char *)malloc(len * sizeof(char) + 1);
	if (c != NULL)
		ft_strcpy(c, s1);
	*(c + len) = '\0';
	return (c);
}
