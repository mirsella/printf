/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:56:14 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 16:09:05 by mirsella         ###   ########.fr       */
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

void	ft_print_width_ullhex(t_formatoptions *fo, unsigned long long n)
{
	while ((unsigned long long)fo->width-- > ft_ullmax(fo->precision, ft_ullnbrlen_base(n, 16)))
	{
		if (fo->zero)
			fo->byteswrotes += ft_putchar('0');
		else
			fo->byteswrotes += ft_putchar(' ');
	}
}

void	ft_print_ullhash(t_formatoptions *fo, unsigned long long n, char conversion)
{
	if (fo->hash && n != 0)
	{
		fo->width -= 2;
		if (fo->zero)
		{
			fo->byteswrotes += ft_printf("0%c", conversion);
			ft_print_width_ullhex(fo, n);
		}
		else
		{
			if (fo->dash == 0)
			{
				ft_print_width_ullhex(fo, n);
			}
			fo->byteswrotes += ft_printf("0%c", conversion);
		}
	}
	else if (fo->dash == 0)
		ft_print_width_ullhex(fo, n);
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
			ft_print_width_ullhex(fo, 100000);
		fo->byteswrotes += ft_putstr("(nil)");
		if (fo->dash == 1)
			ft_print_width_ullhex(fo, 100000);
	}
	else
	{
		ft_print_ullhash(fo, n, 'x');
		while (precision-- > ft_ullnbrlen_base(n, 16))
			fo->byteswrotes += ft_putchar('0');
		fo->byteswrotes += ft_putull_hex(n);
		if (fo->dash == 1)
			ft_print_width_ullhex(fo, n);
	}
}
