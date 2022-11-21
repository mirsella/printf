/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:07:06 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/21 19:43:49 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "stdio.h"

// %[$][flags][width][.precision][length modifier]conversion
int	main(void)
{
	char	*format = "hello %d";
	printf(": %d\n", ft_printf(format, 1));
	printf(": %d\n", printf(format, 123));
}
