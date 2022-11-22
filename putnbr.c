/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:19:10 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/22 19:14:10 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// precision pad on the left with 0
// width pad on the left with space or 0 if fo->zero is set
// if precision and zero set zero is ignored
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
	if (fo->precision == -1)
		fo->precision = 1;
	if (fo->dash == 0)
	{
			while (fo->width-- > ft_max(fo->precision, ft_nbrlen_base(n, 16)))
				if (fo->zero)
					fo->byteswrotes += ft_putchar('0');
				else
					fo->byteswrotes += ft_putchar(' ');
	}
	while (precision-- > ft_nbrlen_base(n, 16))
		fo->byteswrotes += ft_putchar('0');
	if (conversion == 'x')
		fo->byteswrotes += ft_putnbr_base(n, "0123456789abcdef");
	else
		fo->byteswrotes += ft_putnbr_base(n, "0123456789ABCDEF");
	if (fo->dash == 1)
		while (fo->width-- > ft_max(fo->precision, ft_nbrlen_base(n, 16)))
			fo->byteswrotes += ft_putchar(' ');
}
