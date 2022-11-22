/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:03:20 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/22 18:02:09 by mirsella         ###   ########.fr       */
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

void	ft_print_pointer(t_formatoptions *fo, void *p)
{
	fo->hash = 1;
	ft_print_hex(fo, (unsigned long)p, 'x');
}
