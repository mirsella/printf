/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:56:14 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 14:48:59 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_putull_hex(unsigned long long num)
{
	int	i;

	i = 0;
	if (num >= 16)
	{
		i += ft_putull_hex(num / 16);
		i += ft_putull_hex(num % 16);
	}
	else
	{
		if (num <= 9)
			i += ft_putchar(num + '0');
		else
			i += ft_putchar(num - 10 + 'a');
	}
	return (i);
}

void	ft_print_pointer(t_formatoptions *fo, unsigned long long n)
{
	int	precision;

	fo->hash = 1;
	precision = fo->precision;
	if (fo->precision >= 0)
		fo->zero = 0;
	if (n == 0)
	{
		if (fo->dash == 0)
			ft_print_width_hex(fo, 100000);
		fo->byteswrotes += ft_putstr("(nil)");
		if (fo->dash == 1)
			ft_print_width_hex(fo, 100000);
	}
	else
	{
		ft_print_hash(fo, n, 'x');
		while (precision-- > ft_nbrlen_base(ft_llabs(n), 16))
			fo->byteswrotes += ft_putchar('0');
		fo->byteswrotes += ft_putull_hex(n);
		if (fo->dash == 1)
			ft_print_width_hex(fo, n);
	}
}
