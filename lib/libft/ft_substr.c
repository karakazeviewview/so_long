#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	char	*sub;

	if (s == NULL)
		return (NULL);
	sub_len = ft_strnlen(s + start, len);
	if (*s == '\0' || sub_len == 0 || ft_strlen(s) <= start)
		return (ft_strdup(""));
	sub = (char *)malloc(sub_len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_len + 1);
	return (sub);
}
