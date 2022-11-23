/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:07:06 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 15:52:51 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "stdio.h"
#include <limits.h>

int	main(void)
{
	// char	*format = "%x hello%-2c%-6.5s%#-7.4x%u";
	// printf(": %d\n", ft_printf(format, -300, '_', "worldaa", 42, 4294967295));
	// printf(": %d\n",    printf(format, -300, '_', "worldaa", 42, 4294967295));
	char	*format = " %-13p %-14p ";
	printf(": %d\n", ft_printf(format, ULONG_MAX, -ULONG_MAX));
	printf(": %d\n",    printf(format, ULONG_MAX, -ULONG_MAX));
}
