/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:20:35 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 12:21:31 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_width_hex(t_formatoptions *fo, long long n)
{
	while (fo->width-- > ft_max(fo->precision, ft_nbrlen_base(ft_llabs(n), 16)))
	{
		if (fo->zero)
			fo->byteswrotes += ft_putchar('0');
		else
			fo->byteswrotes += ft_putchar(' ');
	}
}

void	ft_print_hash(t_formatoptions *fo, long long n, char conversion)
{
	if (fo->hash && n != 0)
	{
		fo->width -= 2;
		if (fo->zero)
		{
			fo->byteswrotes += ft_printf("0%c", conversion);
			ft_print_width_hex(fo, n);
		}
		else
		{
			if (fo->dash == 0)
			{
				ft_print_width_hex(fo, n);
			}
			fo->byteswrotes += ft_printf("0%c", conversion);
		}
	}
	else if (fo->dash == 0)
		ft_print_width_hex(fo, n);
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
	while (precision-- > ft_nbrlen_base(ft_llabs(n), 16))
		fo->byteswrotes += ft_putchar('0');
	if (conversion == 'x')
		fo->byteswrotes += ft_putnbr_base(n, "0123456789abcdef");
	else
		fo->byteswrotes += ft_putnbr_base(n, "0123456789ABCDEF");
	if (fo->dash == 1)
		ft_print_width_hex(fo, n);
}
