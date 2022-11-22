/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:40:14 by mirsella          #+#    #+#             */
/*   Updated: 2022/11/22 18:47:33 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		i++;
	}
	return (i);
}

static int	ft_isbase(char *base)
{
	int	j;
	int	i;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-'
			|| (base[i] < 32 || base[i] > 126))
			return (0);
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == base[i] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		baselen;
	int		i;
	int		nb;

	baselen = ft_strlen(base);
	i = 0;
	nb = nbr;
	if (!ft_isbase(base))
		return (0);
	if (nbr < 0)
	{
		i += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= baselen)
		i += ft_putnbr_base(nb / baselen, base);
	i += write(1, &base[nb % baselen], 1);
	return (i);
}
