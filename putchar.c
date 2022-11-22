/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:03:20 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/22 21:59:58 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void	ft_print_char(t_formatoptions *fo, unsigned char c)
{
	if (fo->dash)
	{
		fo->byteswrotes += ft_putchar(c);
		while (fo->width-- > 1)
			fo->byteswrotes += ft_putchar(' ');
	}
	else
	{
		while (fo->width-- > 1)
			fo->byteswrotes += ft_putchar(' ');
		fo->byteswrotes += ft_putchar(c);
	}
}

void	ft_print_string(t_formatoptions *fo, char *s)
{
	int	i;
	int	precision;

	i = 0;
	precision = fo->precision;
	if (fo->precision == -1)
		fo->precision = ft_strlen(s);
	if (fo->dash)
	{
		while (precision-- > 0 && s[i])
			fo->byteswrotes += ft_putchar(s[i++]);
		while (fo->width-- > ft_min(fo->precision, (int)ft_strlen(s)))
			fo->byteswrotes += ft_putchar(' ');
	}
	else
	{
		while (fo->width-- > ft_min(fo->precision, (int)ft_strlen(s)))
			fo->byteswrotes += ft_putchar(' ');
		while (precision-- > 0 && s[i])
			fo->byteswrotes += ft_putchar(s[i++]);
	}
}

static void	ft_print_width(t_formatoptions *fo, int n)
{
	while (fo->width-- > ft_max(fo->precision, ft_nbrlen_base(ft_abs(n), 16)))
	{
		if (fo->zero)
			fo->byteswrotes += ft_putchar('0');
		else
			fo->byteswrotes += ft_putchar(' ');
	}
}

void	ft_print_hash(t_formatoptions *fo, int n, char conversion)
{
	if (fo->hash && n != 0)
	{
		fo->width -= 2;
		if (fo->zero)
		{
			fo->byteswrotes += ft_printf("0%c", conversion);
			ft_print_width(fo, n);
		}
		else
		{
			if (fo->dash == 0)
			{
				ft_print_width(fo, n);
			}
			fo->byteswrotes += ft_printf("0%c", conversion);
		}
	}
	else if (fo->dash == 0)
		ft_print_width(fo, n);
}

void	ft_print_hex(t_formatoptions *fo, unsigned int n, char conversion)
{
	int	precision;

	precision = fo->precision;
	if (fo->precision == 0 && n == 0)
	{
		while (fo->width-- > 0)
			fo->byteswrotes += ft_putchar(' ');
		return ;
	}
	if (fo->precision >= 0)
		fo->zero = 0;
	ft_print_hash(fo, n, conversion);
	while (precision-- > ft_nbrlen_base(ft_abs(n), 16))
		fo->byteswrotes += ft_putchar('0');
	if (conversion == 'x')
		fo->byteswrotes += ft_putnbr_base(n, "0123456789abcdef");
	else
		fo->byteswrotes += ft_putnbr_base(n, "0123456789ABCDEF");
	if (fo->dash == 1)
		ft_print_width(fo, n);
}
