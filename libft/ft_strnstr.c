#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	if (len <= n)
	{
		while ((*s1) && (n - len + 1 > 0))
		{
			if (*s1 == *s2)
				if (ft_memcmp((char *)s1, (char *)s2, len) == 0)
					return ((char *)s1);
			s1++;
			n--;
		}
	}
	return (NULL);
}
