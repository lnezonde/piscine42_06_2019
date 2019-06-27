/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triplet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:58:40 by piguillo          #+#    #+#             */
/*   Updated: 2019/06/23 21:20:58 by piguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_print_hundred(char *triplet, char **tab, int i, char *s1)
{
	s1[0] = triplet[0];
	ft_print_alpha(tab, s1);
	ft_putchar(' ');
	ft_print_alpha(tab, "100");
	ft_putchar(' ');
	return (i);
}

int	ft_print_double(char *triplet, char **tab, int i, char *s1)
{
	s1[0] = triplet[i];
	s1[1] = triplet[i + 1];
	ft_print_alpha(tab, s1);
	return (i);
}

int	ft_print_decade(char *triplet, char **tab, int i, char *s1)
{
	s1[0] = triplet[i];
	s1[1] = '0';
	ft_print_alpha(tab, s1);
	ft_putchar(' ');
	return (i);
}

int	ft_print_last(char *triplet, char **tab, int i, char *s1)
{
	s1[0] = triplet[i];
	s1[1] = '\0';
	ft_print_alpha(tab, s1);
	return (i);
}

void	ft_print_triplet(char *triplet, char **tab)
{
	int		i;
	char	*s1;

	s1 = (char*)malloc(3 * sizeof(char));
	s1[2] = '\0';
	i = 0;
	while (i < 3)
	{
		if (triplet[i] == '0')
			i++;
		if (i == 0)
			ft_print_hundred(triplet, tab, i++, s1);
		if (i == 1 && triplet[1] < '2')
		{
			ft_print_double(triplet, tab, i++, s1);
			break ;
		}
		else
			ft_print_decade(triplet, tab, i++, s1);
		if (i == 2)
			ft_print_last(triplet, tab, i++, s1);
	}
}
