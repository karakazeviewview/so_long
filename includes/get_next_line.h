#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "./libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FREE_NONE 0
# define FREE_FIRST_PARAM 1
# define FREE_SECOND_PARAM 2

char	*ft_strjoin_with_free(char *s1, char *s2, int to_free);

char	*get_next_line(int fd);

#endif