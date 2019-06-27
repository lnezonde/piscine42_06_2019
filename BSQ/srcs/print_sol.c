/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:00:13 by cclaude           #+#    #+#             */
/*   Updated: 2019/06/26 22:05:13 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			print_sol(char **tab, struct s_coord pos, char full)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((i <= pos.line && i > pos.line - pos.size)
				&& (j <= pos.col && j > pos.col - pos.size))
				write(1, &full, 1);
			else
				write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
