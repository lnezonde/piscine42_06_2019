/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 17:45:18 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/22 17:45:19 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_clean_spaces(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		str[i] = str[j];
		if (str[i] == ' ')
			while (str[j + 1] == ' ')
				j++;
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_search_num(int i, char **tab)
{
	int		j;
	char	*num;

	j = 0;
	if (!(num = malloc(sizeof(char) * ft_strlen(tab[i]))))
		return (NULL);
	while (tab[i][j] && ft_char_is_numeric(tab[i][j]))
	{
		num[j] = tab[i][j];
		j++;
	}
	return (num);
}

char	*ft_search_alpha(int i, char **tab)
{
	int j;

	j = 0;
	while (tab[i][j] != ':')
		j++;
	j++;
	while (tab[i][j] == ' ')
		j++;
	return (tab[i] + j);
}

void	ft_print_alpha(char **tab, char *to_find)
{
	int		i;
	int		k;
	char	*nb_alpha;
	char	*nb_num;

	i = 0;
	while (i < 42)
	{
		nb_num = ft_search_num(i, tab);
		if (ft_strlen(to_find) < ft_strlen(nb_num))
			k = ft_strlen(nb_num);
		else
			k = ft_strlen(to_find);
		if (ft_strncmp(to_find, nb_num, k) == 0)
		{
			ft_clean_spaces(nb_alpha = ft_search_alpha(i, tab));
			ft_putstr(nb_alpha);
			break ;
		}
		i++;
	}
}
