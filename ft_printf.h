/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:16:36 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 12:21:35 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include "stdarg.h"
# include "stdio.h"
# include "limits.h"

typedef struct s_formatoptions
{
	int	byteswrotes;
	int	width;
	int	precision;
	int	dash;
	int	zero;
	int	hash;
	int	space;
	int	plus;
}	t_formatoptions;

void	ft_print_width_hex(t_formatoptions *fo, long long n);
void	ft_print_hash(t_formatoptions *fo, long long n, char conversion);
void	ft_print_string(t_formatoptions *fo, char *s);
void	ft_print_char(t_formatoptions *fo, unsigned char c);
void	ft_print_int(t_formatoptions *fo, int n);
void	ft_print_unsigned_int(t_formatoptions *fo, unsigned int n);
void	ft_print_hex(t_formatoptions *fo, unsigned int n, char conversion);
void	ft_print_pointer(t_formatoptions *fo, unsigned long long p);
int		fill_fo(t_formatoptions *fo, const char *format, va_list args);
int		ft_printf(const char *format, ...);

#endif