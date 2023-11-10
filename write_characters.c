/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:59:47 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/11/09 16:02:11 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(va_list args)
{
	int		typo;
	ssize_t	bytes;

	typo = va_arg(args, int);
	bytes = write(1, &typo, 1);
	return (bytes);
}

int	write_string(va_list args)
{
	char	*typo;
	int		len;
	ssize_t	bytes;

	typo = va_arg(args, char*);
	if (!typo)
	{
		bytes = write(1, "(null)", 6);
		if (bytes != 6)
			return (-1);
		return (bytes);
	}
	len = ft_strlen(typo);
	bytes = write(1, typo, len);
	if (bytes != len)
		return (-1);
	return (bytes);
}

int	write_module(void)
{
	ssize_t	bytes;

	bytes = write(1, "%", 1);
	return (bytes);
}
