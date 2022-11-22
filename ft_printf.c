/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:11:55 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/22 15:00:51 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int				i;
	int				byteswrotes;
	va_list			args;
	t_formatoptions	fo;

	byteswrotes = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[++i] != '%')
		{
			ft_bzero(&fo, sizeof(t_formatoptions));
			fo.precision = -1;
			i += fill_fo(&fo, format + i, args);
			byteswrotes += fo.byteswrotes;
		}
		else
		{
			byteswrotes += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (byteswrotes);
}
