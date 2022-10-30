#include "../../includes/libft.h"

static int	digit_count(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
		digits++;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	put_in_digits(char *arr, long buf)
{
	int	div;

	div = 1;
	if (buf < 0)
	{
		*arr = '-';
		buf *= -1;
		arr++;
	}
	while (buf / 10 >= div)
		div *= 10;
	while (div != 0)
	{
		*arr = (buf / div) + '0';
		buf %= div;
		div /= 10;
		arr++;
	}
	*(arr) = '\0';
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	buf;
	int		digits;	

	if (n == 0)
		return (ft_strdup("0"));
	digits = digit_count(n);
	arr = (char *)malloc(digits + 1);
	buf = (long)n;
	if (arr != NULL)
		put_in_digits(arr, buf);
	return (arr);
}
