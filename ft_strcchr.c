#include "libft.h"

char	*ft_strcchr(const char *s, int c, char stop)
{
	while (*s || *s != stop)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
