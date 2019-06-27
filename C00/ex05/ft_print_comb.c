/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:52:27 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/07 09:48:30 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(char i, char j, char k)
{
	if (j > i && k > j && k > i)
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
		if (!(i == '7' && j == '8' && k == '9'))
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	j = '1';
	k = '2';
	while (i <= '7')
	{
		while (j <= '8')
		{
			while (k <= '9')
			{
				ft_print_numbers(i, j, k);
				k++;
			}
			k = '2';
			j++;
		}
		j = '1';
		i++;
	}
}
