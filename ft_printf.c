/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:11:55 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/21 20:07:29 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include "stdarg.h"

int	callprinters(t_formatoptions *fo, char conversion, va_list args)
{
	int	i;

	i = 0;
	if (conversion == 'c')
	{
		// i += ft_putnbr(va_arg(args, int));
	} else if (conversion == 's')
	{
		// i += ft_putnbr(va_arg(args, int));
	} else if (conversion == 'p')
	{
		// i += ft_putnbr(va_arg(args, int));
	} else if (conversion == 'd' || conversion == 'i')
	{
		// i += ft_putnbr(va_arg(args, int));
	} else if (conversion == 'u')
	{
		// i += ft_putnbr(va_arg(args, int));
	} else if (conversion == 'x' && conversion == 'x')
	{
		// i += ft_putnbr(va_arg(args, int));
	}
	return (i);
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
	return (i);
}

int	fill_fo(t_formatoptions *fo, const char *format, va_list args)
{
	int	i;

	i = 0;
	i += parse_flag(fo, format);
	while (format[i] >= '1' && format[i] <= '9')
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
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				ret;
	va_list			args;
	t_formatoptions	fo;

	ret = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			ft_bzero(&fo, sizeof(t_formatoptions));
			fo.precision = -1;
			i += fill_fo(&fo, format, args);
			ret += fo.byteswrotes;
		}
		else
		{
			ret += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (ret);
}
