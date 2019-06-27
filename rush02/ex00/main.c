/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carendt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:03:29 by carendt           #+#    #+#             */
/*   Updated: 2019/06/23 23:03:33 by carendt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	char **tab_nb;
	char **tab;

	if (argc == 2)
	{
		tab = ft_make_tab();
		tab_nb = ft_split_nb(argv[1]);
		ft_send_triplet(tab_nb, tab);
	}
	else
		ft_putstr("Error\n");
}
