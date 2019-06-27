/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:46:14 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/16 21:46:20 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_verif_row_right(int i, char grid[4][4], int v1);
int		ft_verif_row_left(int i, char grid[4][4], int v1);
int		ft_verif_col_up(int j, char grid[4][4], int v1);
int		ft_verif_col_down(int j, char grid[4][4], int v1);

int		ft_not_row(int k, char grid[4][4], int i)
{
	int j;

	j = 0;
	while (j <= 3)
	{
		if (grid[i][j] == k)
			return (0);
		j++;
	}
	return (1);
}

int		ft_not_col(int k, char grid[4][4], int j)
{
	int i;

	i = 0;
	while (i <= 3)
	{
		if (grid[i][j] == k)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_view(char grid[4][4], char tab_view[4][4])
{
	int k;

	k = 0;
	while (k <= 3)
	{
		if (ft_verif_col_up(k, grid, tab_view[0][k]) == 0)
			return (0);
		if (ft_verif_col_down(k, grid, tab_view[1][k]) == 0)
			return (0);
		if (ft_verif_row_left(k, grid, tab_view[2][k]) == 0)
			return (0);
		if (ft_verif_row_right(k, grid, tab_view[3][k]) == 0)
			return (0);
		k++;
	}
	return (1);
}

int		ft_grid_is_valid(char grid[4][4], int pos, char tab_view[4][4])
{
	int		i;
	int		j;
	char	k;

	i = pos / 4;
	j = pos % 4;
	k = '1';
	if (pos == 16 && ft_check_view(grid, tab_view))
		return (1);
	while (k <= '4')
	{
		if (ft_not_row(k, grid, i) && ft_not_col(k, grid, j))
		{
			grid[i][j] = k;
			if (ft_grid_is_valid(grid, pos + 1, tab_view))
				return (1);
		}
		k++;
	}
	grid[i][j] = '0';
	return (0);
}
