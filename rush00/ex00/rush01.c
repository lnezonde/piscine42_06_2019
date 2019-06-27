/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grhaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 19:45:23 by grhaton           #+#    #+#             */
/*   Updated: 2019/06/09 19:45:25 by grhaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush_l1(int col)
{
	ft_putchar('/');
	while (col > 0)
	{
		ft_putchar('*');
		col--;
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

void	rush_l(int col, int lin)
{
	int col_0;

	col_0 = col;
	while (lin > 0)
	{
		ft_putchar('*');
		while (col > 0)
		{
			ft_putchar(' ');
			col--;
		}
		if (col == 0)
			ft_putchar('*');
		ft_putchar('\n');
		lin--;
		col = col_0;
	}
}

void	rush_l3(int col)
{
	ft_putchar('\\');
	while (col > 0)
	{
		ft_putchar('*');
		col--;
	}
	ft_putchar('/');
	ft_putchar('\n');
}

void	rush(int col, int lin)
{
	if (col > 0 && lin > 0)
	{
		if (col == 1 && lin >= 1)
		{
			ft_putchar('/');
			ft_putchar('\n');
		}
		else if (lin >= 1)
			rush_l1(col - 2);
		rush_l(col - 2, lin - 2);
		if (col == 1 && lin >= 2)
		{
			ft_putchar('\\');
			ft_putchar('\n');
		}
		else if (lin >= 3)
			rush_l3(col - 2);
	}
}
