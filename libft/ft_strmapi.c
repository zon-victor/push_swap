#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*news;

	i = -1;
	if (s && f)
	{
		news = malloc(sizeof(char) * ft_strlen(s));
		while (*(s + (++i)) != '\0')
			*(news + i) = f(i, *(s + i));
		return (news);
	}
	return (NULL);
}
