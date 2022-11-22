/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:59:31 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/22 19:02:27 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	callprinters(t_formatoptions *fo, char conversion, va_list args)
{
	if (conversion == 'c')
	{
		ft_print_char(fo, va_arg(args, int));
	}
	else if (conversion == 's')
	{
		ft_print_string(fo, va_arg(args, char *));
	}
	else if (conversion == 'p')
	{
		ft_print_pointer(fo, va_arg(args, void *));
	}
	else if (conversion == 'd' || conversion == 'i')
	{
		// ft_print_int(fo, va_arg(args, int));
	}
	else if (conversion == 'u')
	{
		// ft_print_unsigned_int(fo, va_arg(args, unsigned int));
	}
	else if (conversion == 'x' || conversion == 'X')
	{
		ft_print_hex(fo, va_arg(args, unsigned int), conversion);
	}
}

int	parse_flag(t_formatoptions *fo, const char *format)
{
	int	i;

	i = 0;
	while (format[i] == '-' || format[i] == '0' || format[i] == '#'
		|| format[i] == ' ' || format[i] == '+')
	{
		if (format[i] == '-')
			fo->dash = 1;
		else if (format[i] == '0')
			fo->zero = 1;
		else if (format[i] == '#')
			fo->hash = 1;
		else if (format[i] == ' ')
			fo->space = 1;
		else if (format[i] == '+')
			fo->plus = 1;
		i++;
	}
	if (fo->dash == 1)
		fo->zero = 0;
	return (i);
}

int	fill_fo(t_formatoptions *fo, const char *format, va_list args)
{
	int	i;

	i = 0;
	i += parse_flag(fo, format);
	while (format[i] >= '0' && format[i] <= '9')
	{
		fo->width = fo->width * 10 + (format[i] - '0');
		i++;
	}
	if (format[i] == '.' && format[i + 1] != '-')
	{
		i++;
		fo->precision = 0;
		while (format[i] >= '0' && format[i] <= '9')
		{
			fo->precision = fo->precision * 10 + (format[i] - '0');
			i++;
		}
	}
	callprinters(fo, format[i], args);
	return (i + 1);
}