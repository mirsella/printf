/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:11:55 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/21 18:48:08 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include "stdarg.h"

int	callprinters(t_formatoptions *fo, char conversion)
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
	} else if (conversion == 'd')
	{
		// i += ft_putnbr(va_arg(args, int));
	} else if (conversion == 'i')
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

int	is_valid_flag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

// %[$][flags][width][.precision][length modifier]conversion
int	fillFormatOptions(t_formatoptions *fo, const char *format)
{
	int	i;

	i = 0;
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	ret;
	va_list	args;
	t_formatoptions fo;

	ret = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			ft_bzero(&fo, sizeof(t_formatoptions));
			i += fillFormatOptions(&fo, format);
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
