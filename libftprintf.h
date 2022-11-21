/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:16:36 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/21 18:49:42 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"

// %[$][flags][width][.precision][length modifier]conversion
typedef struct s_formatoptions {
	int	byteswrotes;
	int	width;
	int	precision;
	int	zero;
	int	dot;
	int	dash;
	int	space;
}	t_formatoptions;

int	ft_printf(const char *format, ...);

#endif
