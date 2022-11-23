/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:07:06 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 12:15:52 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	// char	*format = "%x hello%-2c%-6.5s%#-7.4x%u";
	// printf(": %d\n", ft_printf(format, -300, '_', "worldaa", 42, 4294967295));
	// printf(": %d\n",    printf(format, -300, '_', "worldaa", 42, 4294967295));

	char	*format = "%p %p %p %p %-8.3p";
	printf(": %d\n", ft_printf(format, LONG_MIN, LONG_MAX, ULONG_MAX, -ULONG_MAX, 0));
	printf(": %d\n",    printf(format, LONG_MIN, LONG_MAX, ULONG_MAX, -ULONG_MAX, 0));
	// char	*format = "%p\n";
	// ft_printf(format, LONG_MAX);
	// printf(format, LONG_MAX);
}
