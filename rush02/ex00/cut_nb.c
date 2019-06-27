/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:15:19 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/23 17:15:22 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_fill_0(char **tab_nb, char *nb)
{
	int i;
	int j;
	int n;

	i = ft_strlen(nb);
	while (i % 3 != 0)
		i++;
	n = i - ft_strlen(nb);
	j = 0;
	while (j < n)
	{
		tab_nb[0][j] = '0';
		j++;
	}
	return (j);
}

char	**ft_split_nb(char *nb)
{
	char	**tab_nb;
	int		i;
	int		j;
	int		k;

	i = 0;
	if (!(tab_nb = malloc(sizeof(char *) * (ft_strlen(nb) / 3 + 2))))
		return (NULL);
	while (i <= (ft_strlen(nb) / 3))
	{
		tab_nb[i++] = malloc(sizeof(char) * 4);
	}
	i = 0;
	j = ft_fill_0(tab_nb, nb);
	k = 0;
	while (nb[k])
	{
		while (j < 3 && nb[k])
			tab_nb[i][j++] = nb[k++];
		tab_nb[i++][j] = '\0';
		j = 0;
	}
	tab_nb[i] = NULL;
	return (tab_nb);
}

void	ft_fill_tab_big(char *tab_big_nb[13])
{
	tab_big_nb[0] = "1000";
	tab_big_nb[1] = "1000000";
	tab_big_nb[2] = "1000000000";
	tab_big_nb[3] = "1000000000000";
	tab_big_nb[4] = "1000000000000000";
	tab_big_nb[5] = "1000000000000000000";
	tab_big_nb[6] = "1000000000000000000000";
	tab_big_nb[7] = "1000000000000000000000000";
	tab_big_nb[8] = "1000000000000000000000000000";
	tab_big_nb[9] = "1000000000000000000000000000000";
	tab_big_nb[10] = "100000000000000000000000000000000";
	tab_big_nb[11] = "100000000000000000000000000000000000";
	tab_big_nb[12] = NULL;
}

void	ft_send_triplet(char **tab_nb, char **tab)
{
	char	*tab_big_nb[13];
	int		i;
	int		i2;
	int		len;

	ft_fill_tab_big(tab_big_nb);
	i = 0;
	len = 0;
	while (tab[i][0] == '0' && tab_nb[i][1] == '0' && tab_nb[i][2] == '0')
		i++;
	i2 = i;
	while (tab_nb[i++])
		len++;
	len -= 2;
	ft_print_triplet(tab_nb[i2++], tab);
	while (tab_nb[i2])
	{
		ft_putchar(' ');
		ft_print_alpha(tab, tab_big_nb[len--]);
		ft_putchar(' ');
		ft_print_triplet(tab_nb[i2], tab);
		i2++;
	}
	ft_putchar('\n');
}
