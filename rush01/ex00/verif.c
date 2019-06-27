/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:48:28 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/16 21:48:30 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_verif_row_left(int i, char grid[4][4], char v1)
{
	int		j;
	char	test;
	char	tmp;

	j = 1;
	tmp = '1';
	test = grid[i][0];
	while (j <= 3)
	{
		if (test < grid[i][j])
		{
			test = grid[i][j];
			tmp++;
		}
		j++;
	}
	if (v1 == tmp)
		return (1);
	else
		return (0);
}

int		ft_verif_row_right(int i, char grid[4][4], char v1)
{
	int		j;
	char	test;
	char	tmp;

	j = 2;
	tmp = '1';
	test = grid[i][3];
	while (j >= 0)
	{
		if (test < grid[i][j])
		{
			test = grid[i][j];
			tmp++;
		}
		j--;
	}
	if (v1 == tmp)
		return (1);
	else
		return (0);
}

int		ft_verif_col_up(int j, char grid[4][4], char v1)
{
	int		i;
	char	test;
	char	tmp;

	i = 1;
	tmp = '1';
	test = grid[0][j];
	while (i <= 3)
	{
		if (test < grid[i][j])
		{
			test = grid[i][j];
			tmp++;
		}
		i++;
	}
	if (v1 == tmp)
		return (1);
	else
		return (0);
}

int		ft_verif_col_down(int j, char grid[4][4], char v1)
{
	int		i;
	char	test;
	char	tmp;

	i = 2;
	tmp = '1';
	test = grid[3][j];
	while (i >= 0)
	{
		if (test < grid[i][j])
		{
			test = grid[i][j];
			tmp++;
		}
		i--;
	}
	if (v1 == tmp)
		return (1);
	else
		return (0);
}
