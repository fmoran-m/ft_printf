/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:51:53 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/11/03 19:40:48 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_char(char const *format, int i, va_list args)
{
	int	typo;

	typo = va_arg(args, int);
	write(1, &typo, 1);
}

void	check_typo(char const *format, int i, va_list args)
{
	if (format[i] == 'c')
		write_char(format, i, args);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;	
	int		i;

	i = 0;
	va_start(args, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++; //Controlar errores
			check_typo(format, i, args);
		}
		else
			i++;
	}
	va_end(args);
	return (i);
}


int main (void)
{
	char c = 'z';
	ft_printf("mi char es: %c", c);
	return 0;
}
