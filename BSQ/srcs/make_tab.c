/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:56:59 by cclaude           #+#    #+#             */
/*   Updated: 2019/06/26 22:05:12 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_put_lines_in_tab(char *file, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (file[k] != '\n')
		k++;
	k++;
	while (file[k])
	{
		if (file[k] == '\n')
		{
			tab[i][j] = '\0';
			i++;
			k++;
			j = 0;
		}
		tab[i][j] = file[k];
		j++;
		k++;
	}
	tab[i] = NULL;
}

int		ft_map_size(char *file, char l)
{
	int	i;
	int	size_j;

	i = 0;
	size_j = 0;
	if (l == 'i')
		return (ft_atoi(file));
	else
	{
		while (file[i])
		{
			if (file[i] == '\n')
				size_j++;
			i++;
		}
		return (size_j);
	}
}

char	ft_find_info(char *file, int pos)
{
	char	info[3];
	int		i;

	i = 0;
	while (ft_char_is_num(file[i]))
		i++;
	info[0] = file[i++];
	info[1] = file[i++];
	info[2] = file[i];
	return (info[pos]);
}

char	**ft_make_tab(char *file)
{
	int		i;
	char	**tab;

	if (!(tab = malloc(sizeof(char *) * (ft_map_size(file, 'i') + 1))))
		return (NULL);
	i = 0;
	while (i <= ft_map_size(file, 'i'))
	{
		tab[i] = malloc(sizeof(char) * (ft_map_size(file, 'j') + 1));
		i++;
	}
	ft_put_lines_in_tab(file, tab);
	return (tab);
}
