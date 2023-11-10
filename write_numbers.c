/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:57:30 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/11/09 18:52:55 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_upper_hex(va_list args)
{
	ssize_t			bytes;
	unsigned int	typo;
	int				size;
	char			*num;

	typo = va_arg(args, unsigned int);
	num = ft_upper_hextoa(typo);
  if (!num)
    return (-1);
	size = ft_strlen(num);
	bytes = write(1, num, size);
	if (bytes != size)
		return (free(num), -1);
	free (num);
	return (bytes);
}

int	write_lower_hex(va_list args)
{
	ssize_t			bytes;
	unsigned int	typo;
	int				size;
	char			*num;

	typo = va_arg(args, unsigned int);
	num = ft_lower_hextoa(typo); //Controlar reserva
	if (!num)
		return (-1);
	size = ft_strlen(num);
	bytes = write(1, num, size);
	if (bytes != size)
		return (free(num), -1);
	free (num);
	return (bytes);
}

int	write_pointer_address(va_list args)
{
	ssize_t				bytes;
	unsigned long long	typo;
	int					size;
	char				*num;

	bytes = write (1, "0x", 2);
	if (bytes != 2)
		return (-1);
	typo = va_arg(args, unsigned long long);
	num = ft_long_hextoa(typo);
  if (!num)
    return (-1);
	size = ft_strlen(num);
	bytes += write(1, num, size);
	if (bytes != size + 2)
		return (free(num), -1);
	free (num);
	return (bytes);
}

int	write_number(va_list args)
{
	ssize_t		bytes;
	int				typo;
	int				size;
	char			*num;

	typo = va_arg(args, int);
	num = ft_itoa(typo);
  if (!num)
    return (-1);
	size = ft_strlen(num);
	bytes = write(1, num, size);
	if (bytes != size)
		return (free (num), -1);
	free (num);
	return (bytes);
}

int	write_unsigned(va_list args)
{
	ssize_t			bytes;
	unsigned int	typo;
	int				size;
	char			*num;

	typo = va_arg(args, unsigned int);
	num = ft_utoa(typo);
  if (!num)
    return (-1);
	size = ft_strlen(num);
	bytes = write(1, num, size);
	if (bytes != size)
		return (free(num), -1);
	free (num);
	return (bytes);
}
