/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:19:10 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 16:08:13 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <bits/types.h>

void	ft_print_width(t_formatoptions *fo, long long n)
{
	while (fo->width-- > ft_llmax(fo->precision, ft_nbrlen(ft_llabs(n))))
	{
		if (fo->zero)
			fo->byteswrotes += ft_putchar('0');
		else
			fo->byteswrotes += ft_putchar(' ');
	}
}

void	ft_print_int(t_formatoptions *fo, int n)
{
	int	precision;

	precision = fo->precision;
	if (n == 0 && fo->precision == 0)
	{
		ft_print_width(fo, 0);
		return ;
	}
	if (fo->precision >= 0)
		fo->zero = 0;
	if ((fo->plus || fo->space) || n < 0)
		fo->width--;
	if (fo->dash == 0 && fo->zero == 0)
		ft_print_width(fo, n);
	if (n < 0)
		fo->byteswrotes += ft_putchar('-');
	else if (fo->plus)
		fo->byteswrotes += ft_putchar('+');
	else if (fo->space)
		fo->byteswrotes += ft_putchar(' ');
	if (fo->dash == 0 && fo->zero == 1)
		ft_print_width(fo, n);
	while (precision-- > ft_nbrlen(ft_llabs(n)))
		fo->byteswrotes += ft_putchar('0');
	fo->byteswrotes += ft_putnbr(ft_llabs(n));
	if (fo->dash == 1)
		ft_print_width(fo, n);
}

void	ft_print_unsigned_int(t_formatoptions *fo, unsigned int n)
{
	int	precision;

	precision = fo->precision;
	if (n == 0 && fo->precision == 0)
	{
		ft_print_width(fo, 0);
		return ;
	}
	if (fo->precision >= 0)
		fo->zero = 0;
	if (fo->dash == 0 && fo->zero == 0)
		ft_print_width(fo, n);
	if (fo->dash == 0 && fo->zero == 1)
		ft_print_width(fo, n);
	while (precision-- > ft_nbrlen(ft_llabs(n)))
		fo->byteswrotes += ft_putchar('0');
	fo->byteswrotes += ft_putnbr(ft_llabs(n));
	if (fo->dash == 1)
		ft_print_width(fo, n);
}
