/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:34:41 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/27 20:29:57 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_charset(int i, char *str, char *charset)
{
	int j;

	j = 0;
	while (charset[j])
	{
		if (str[i] == charset[j])
			return (j + 1);
		j++;
	}
	return (0);
}

int		ft_tab_size_i(char *str, char *charset)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (str[i] && ft_is_charset(i, str, charset) != 0)
		i++;
	while (str[i])
	{
		while (str[i] && ft_is_charset(i, str, charset) == 0)
			i++;
		while (str[i] && ft_is_charset(i, str, charset) != 0)
			i++;
		size++;
	}
	return (size);
}

int		ft_tab_size_j(int i, char *str, char *charset)
{
	int size;

	size = 0;
	while (str[i] && ft_is_charset(i, str, charset) != 0)
		i++;
	while (str[i] && ft_is_charset(i, str, charset) == 0)
	{
		i++;
		size++;
	}
	return (size);
}

void	ft_fill_tab(int k, char *str, char *charset, char *tab)
{
	int j;

	j = 0;
	while (str[k] && ft_is_charset(k, str, charset) != 0)
		k++;
	while (str[k] && ft_is_charset(k, str, charset) == 0)
	{
		tab[j] = str[k];
		j++;
		k++;
	}
	tab[j] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		size;
	int		i;
	int		k;

	i = 0;
	k = 0;
	size = ft_tab_size_i(str, charset);
	if (!(tab = malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
	{
		while (ft_is_charset(k, str, charset) != 0)
			k++;
		if (!(tab[i] = malloc(sizeof(char)
		* (ft_tab_size_j(k, str, charset) + 1))))
			return (NULL);
		ft_fill_tab(k, str, charset, tab[i]);
		k += ft_tab_size_j(k, str, charset);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
