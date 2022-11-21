/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:16:36 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/21 20:03:06 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include "stdarg.h"

typedef struct s_formatoptions {
	int	byteswrotes;
	int	width;
	int	precision;
	int	dash;
	int	zero;
	int	hash;
	int	space;
	int	plus;
}	t_formatoptions;

int	ft_printf(const char *format, ...);

#endif
