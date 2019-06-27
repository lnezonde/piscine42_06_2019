/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:48:05 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/16 21:48:08 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_grid(char grid[4][4]);
int		ft_grid_is_valid(char grid[4][4], int pos, char tab_view[4][4]);

void	ft_fill_tab_views(char *str, char tab_views[4][4])
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= 3)
	{
		while (j <= 3)
		{
			tab_views[i][j] = str[k];
			k += 2;
			j++;
		}
		i++;
		j = 0;
	}
}

void	rush01(char *str)
{
	char grid[4][4];
	char tab_views[4][4];

	ft_fill_tab_views(str, tab_views);
	if (ft_grid_is_valid(grid, 0, tab_views))
		ft_print_grid(grid);
	else
		write(1, "Error\n", 6);
}
