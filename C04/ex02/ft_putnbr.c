/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:59:34 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/13 17:44:27 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_print_number('-');
		if (nb == -2147483648)
		{
			ft_print_number('2');
			nb = 147483648;
		}
		else
			nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_print_number('0' + nb % 10);
}
