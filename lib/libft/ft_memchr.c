#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc_s = s;

	while (n--)
	{
		if (*uc_s == (unsigned char)c)
			return ((void *)uc_s);
		uc_s++;
	}
	return (NULL);
}
