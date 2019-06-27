/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:34:08 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/24 18:34:09 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(int i, char *src)
{
	while (src[i])
	{
		write(1, &src[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(0, par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(0, par[i].copy);
		i++;
	}
}
