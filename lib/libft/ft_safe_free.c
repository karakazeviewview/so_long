#include "../../includes/libft.h"

void	ft_safe_free(char **pointer)
{
	if (*pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}
