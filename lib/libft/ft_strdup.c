#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = (char *)malloc(ft_strlen(s1) + 1);
	if (dup != NULL)
		ft_strlcpy(dup, s1, ft_strlen(s1) + 1);
	return (dup);
}
