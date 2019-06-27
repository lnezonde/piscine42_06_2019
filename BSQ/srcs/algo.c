/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 23:42:47 by cclaude           #+#    #+#             */
/*   Updated: 2019/06/26 22:05:06 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char			**pascal(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 1;
		while (tab[i][j])
		{
			if (tab[i][j] != '0')
			{
				tab[i][j] = tab[i - 1][j - 1];
				if (tab[i][j] > tab[i][j - 1])
					tab[i][j] = tab[i][j - 1];
				if (tab[i][j] > tab[i - 1][j])
					tab[i][j] = tab[i - 1][j];
				tab[i][j] += 1;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

struct s_coord	find_square(char **tab)
{
	int				i;
	int				j;
	struct s_coord	pos;

	pos.size = '0';
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] > pos.size)
			{
				pos.size = tab[i][j];
				pos.line = i;
				pos.col = j;
			}
			j++;
		}
		i++;
	}
	pos.size = pos.size - 48;
	return (pos);
}
