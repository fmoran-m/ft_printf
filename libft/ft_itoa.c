/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 19:27:04 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/10/06 13:49:03 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*reserve(int n)
{
	int		nr;
	int		negative;
	char	*str;

	nr = 0;
	negative = 0;
	if (n < 0)
		negative = 1;
	while (n != 0)
	{
		n = n / 10;
		nr++;
	}
	str = (char *)malloc(nr * sizeof(char) + 1 + negative);
	if (str == NULL)
		return (NULL);
	return (str);
}

static void	copy_string(int n, char *str)
{
	int	i;
	int	original_n;

	i = 0;
	original_n = n;
	while (n != 0)
	{
		str[i] = (n % 10);
		if (str[i] < 0)
			str[i] = str[i] * -1;
		str[i] = str[i] + 48;
		n = n / 10;
		i++;
	}
	if (original_n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = 0;
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = reserve(n);
	if (str == NULL)
		return (NULL);
	copy_string(n, str);
	invert(str);
	return (str);
}
