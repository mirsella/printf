/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:07:06 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/22 22:07:45 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "stdio.h"

int	main(void)
{
	char	*format = "hello%-2c%-6.5s%#-7.4x%0+8d";
	printf(": %d\n", ft_printf(format, '_', "worldaa", 42, 336));
	printf(": %d\n",    printf(format, '_', "worldaa", 42, 336));
}
