/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:23:43 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/09 14:23:23 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int size_2;

	size_2 = 0;
	size--;
	while (size_2 < size)
	{
		i = tab[size];
		tab[size] = tab[size_2];
		size--;
		tab[size_2] = i;
		size_2++;
	}
}
