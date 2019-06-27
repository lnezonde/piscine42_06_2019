/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:39:56 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/07 10:12:42 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(char i, char j, char k, char l)
{
	if (!(k < i || (k == i && l <= j)))
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, " ", 1);
		write(1, &k, 1);
		write(1, &l, 1);
		if (!(i == '9' && j == '8' && k == '9' && l == '9'))
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	ft_print(char i, char j)
{
	char	k;
	char	l;

	k = '0';
	l = '0';
	while (k <= '9')
	{
		while (l <= '9')
		{
			ft_print_numbers(i, j, k, l);
			l++;
		}
		k++;
		l = '0';
	}
}

void	ft_print_comb2(void)
{
	char i;
	char j;

	i = '0';
	j = '0';
	while (i <= '9')
	{
		while (j <= '9')
		{
			ft_print(i, j);
			j++;
		}
		i++;
		j = '0';
	}
}
