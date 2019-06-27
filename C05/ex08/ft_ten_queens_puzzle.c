/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:57:41 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/18 13:57:43 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_diag_col_row(char grid[10][10], int i, int j)
{
	int k;

	k = 0;
	while (k <= 9)
	{
		if (grid[i][k] == 'q')
			return (0);
		if (grid[k][j] == 'q')
			return (0);
		if ((i + k) <= 9 && (j + k) <= 9 && grid[i + k][j + k] == 'q')
			return (0);
		if ((i - k) >= 0 && (j - k) >= 0 && grid[i - k][j - k] == 'q')
			return (0);
		if ((i - k) >= 0 && (j + k) <= 9 && grid[i - k][j + k] == 'q')
			return (0);
		if ((i + k) <= 9 && (j - k) >= 0 && grid[i + k][j - k] == 'q')
			return (0);
		k++;
	}
	return (1);
}

void	ft_print_chessboard(char grid[10][10], int *nb_sol)
{
	char	sol[10];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j <= 9)
	{
		while (i <= 9)
		{
			if (grid[i][j] == 'q')
				sol[j] = ('0' + i);
			i++;
		}
		i = 0;
		j++;
	}
	write(1, sol, 10);
	write(1, "\n", 1);
	*nb_sol = *nb_sol + 1;
}

void	ft_valid_chessboard(char grid[10][10], int j, int *nb_sol)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		if (ft_check_diag_col_row(grid, i, j))
		{
			grid[i][j] = 'q';
			if (j < 9)
				ft_valid_chessboard(grid, j + 1, nb_sol);
			if (j == 9)
				ft_print_chessboard(grid, nb_sol);
			grid[i][j] = '0';
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	char	grid[10][10];
	int		nb_sol;

	nb_sol = 0;
	ft_valid_chessboard(grid, 0, &nb_sol);
	return (nb_sol);
}
