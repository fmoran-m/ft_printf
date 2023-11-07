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
	len = ft_strlen(typo);
	bytes = write(1, typo, len);
	return (bytes);
}
/*
int write_number(va_list args)
{

}
*/
int	write_module(void)
{
	ssize_t	bytes;
	bytes = write(1, "%", 1);
	return (bytes);
}


static int	check_typo(char const *format, int i, va_list args)
{
	int counter;

	counter = 0;
	if (format[i] == 'c')
		counter = write_char(args);
	else if (format[i] == 's')
		counter = write_string(args);
	//else if (format[i] == 'p')
		//counter = write_void(args);
	//else if (format[i] == 'd')
		//counter = write_number(args);
	//else if (format[i] == 'i')
		//counter = write_number(args);
	//else if (format[i] == 'u')
		//counter = write_unsigned(args);
	//else if (format[i] == 'x')
		//counter = write_lower_hex(args);
	//else if (format[i] == 'X')
		//counter = write_upper_hex(args);
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

	i = 0;
	bytes = 0;
	counter = 0;
	va_start(args, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			bytes = check_typo(format, i, args);
			if (bytes == -1)
				return (-1);
			counter = counter + bytes;
			i++;
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

int main (void)
{
	char c = 'z';
	char *s = "string";
	//void *a = "b";
	//int num = 41;
	ft_printf("mi char es %c\nmi string es %s\nmi modulo es %%\n", c, s);
    return (0);
}