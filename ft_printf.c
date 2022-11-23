/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:11:55 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/23 17:58:59 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_bytes(int *counter, int byteswrotes)
{
	if (!counter)
		return ;
	if (byteswrotes < 0 || *counter < 0)
		*counter = -1;
	else
		*counter += byteswrotes;
}

int	ft_printf(const char *format, ...)
{
	int				i;
	int				byteswrotes;
	va_list			args;
	t_formatoptions	fo;

	i = 0;
	byteswrotes = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[++i] != '%')
		{
			ft_bzero(&fo, sizeof(t_formatoptions));
			fo.precision = -1;
			i += parse_callprinters(&fo, format + i, args);
			count_bytes(&byteswrotes, fo.byteswrotes);
		}
		else
		{
			count_bytes(&byteswrotes, ft_putchar(format[i]));
			i++;
		}
	}
	va_end(args);
	return (byteswrotes);
}

// #include "stdio.h"
// #include <limits.h>
// #include <unistd.h>
// 
// int	main(void)
// {
// char	*format = "%x hello%-2c%-6.5s%#-7.4x%u";
// printf(": %d\n", ft_printf(format, 300, '_', "worldaa", 42, 4294967295));
// printf(": %d\n",    printf(format, 300, '_', "worldaa", 42, 4294967295));

// test for -1
// setbuf(stdout, NULL);
// close(STDOUT_FILENO);
// dprintf(STDERR_FILENO, "Status: [%d]", ft_printf("123456789"));
// }
