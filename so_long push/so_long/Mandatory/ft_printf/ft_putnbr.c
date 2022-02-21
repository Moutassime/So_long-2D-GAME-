/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:28:14 by eseiv             #+#    #+#             */
/*   Updated: 2021/12/03 00:28:15 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *cp)
{
	long long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-', cp);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, cp);
		ft_putchar((nbr % 10) + '0', cp);
	}
	else
		ft_putchar(nbr + '0', cp);
}
