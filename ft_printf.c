/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <fmoran-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:51:53 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/11/09 18:22:47 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_typo(char const *format, int i, va_list args)
{
	int counter;

	counter = 0;

	if (format[i] == 'c')
		counter = write_char(args);
	else if (format[i] == 's')
		counter = write_string(args);
	else if (format[i] == 'p')
		counter = write_pointer_address(args);
	else if (format[i] == 'd' || format[i] == 'i')
		counter = write_number(args);
	else if (format[i] == 'u')
		counter = write_unsigned(args);
	else if (format[i] == 'x')
		counter = write_lower_hex(args);
	else if (format[i] == 'X')
		counter = write_upper_hex(args);
	else if (format[i] == '%')
		counter = write_module();
	return (counter);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			i;
	int			counter;
	int			bytes;

	if (!format)
		return (0);
	i = 0;
	bytes = 0;
	counter = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			bytes = check_typo(format, i + 1, args);
			if (bytes == -1)
				return (-1);
			counter = counter + bytes;
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			counter++;
		}
	}
	va_end(args);
	return (counter);
}
