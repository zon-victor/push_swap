#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s1);
	while ((s1[i] = s2[j]))
	{
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
