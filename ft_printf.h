/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoran-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:52:18 by fmoran-m          #+#    #+#             */
/*   Updated: 2023/11/03 14:56:45 by fmoran-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

int	ft_printf(char const *format, ...);
int	write_string(va_list args);
int	write_char(va_list args);
int	write_module(void);
int	write_lower_hex(va_list args);
#endif
