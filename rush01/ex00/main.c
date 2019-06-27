/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 21:46:46 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/16 21:47:34 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush01(char *str);

int		ft_check_arg(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (i % 2 == 0 && (tab[i] < '1' || tab[i] > '4'))
			return (0);
		else if (i % 2 != 0 && tab[i] != ' ')
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	else
		return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2 && ft_check_arg(av[1]))
	{
		rush01(av[1]);
	}
	else
		write(1, "Error\n", 6);
}
