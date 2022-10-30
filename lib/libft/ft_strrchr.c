#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;

	end = (char *)s + ft_strlen(s);
	while (*end != (char)c)
		if (end-- == s)
			return (NULL);
	return (end);
}
