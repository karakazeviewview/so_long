#include "../../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((size_t) - 1 / count < size)
		return (NULL);
	ret = malloc(size * count);
	if (ret != NULL)
		ft_bzero(ret, size * count);
	return (ret);
}
