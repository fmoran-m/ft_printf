#include "ft_printf.h"

static void	invert(char *str)
{
	int		a;
	int		z;
	char	temp;

	a = 0;
	z = ft_strlen(str) - 1;
	while (a < z)
	{
		temp = str[a];
		str[a] = str[z];
		str[z] = temp;
		a++;
		z--;
	}
}

static char *reserve(unsigned long long n)
{
	int		size;
	char	*str;

	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (str);
}

static void	copy_string(unsigned long long n, char *str)
{
	char			*reference;
	unsigned int	temp;
	unsigned int	i;

	reference = "0123456789abcdef";
	i = 0;
	temp = 0;
	while (n != 0)
	{
		temp = n % 16;
		str[i] = reference[temp];
		n = n / 16;
		i++;
	}
}

static char	*ft_hextoa(unsigned long long n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	str = reserve(n);
	if (!str)
		return (NULL);
	copy_string(n, str);
	invert(str);
	return (str);
}

int	write_pointer_address(va_list args)
{
	ssize_t				bytes;
	unsigned long long	typo;
	int					size;
	char				*num;

	bytes = write (1, "0x", 2);
	if (bytes == -1)
		return (-1);
	typo = va_arg(args, unsigned long long);
	num = ft_hextoa(typo);
	size = ft_strlen(num);
	bytes += write(1, num, size);
	free (num);
	return (bytes);
}