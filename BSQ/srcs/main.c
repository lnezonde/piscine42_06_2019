/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:17:11 by cclaude           #+#    #+#             */
/*   Updated: 2019/06/26 22:40:12 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	bsq_launch(char *map, int params)
{
	char			**tab;
	char			**tab_copy;
	char			*file;
	struct s_coord	pos;

	if (params)
		file = ft_read_file(map);
	else
		file = ft_read_stdin();
	if (valid_buf(file) == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	tab = ft_make_tab(file);
	tab_copy = ft_make_tab(file);
	ft_trad_tab(tab, ft_find_info(file, 0));
	tab = pascal(tab);
	pos = find_square(tab);
	print_sol(tab_copy, pos, ft_find_info(file, 2));
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		bsq_launch("", 0);
	while (i < ac)
	{
		bsq_launch(av[i], 1);
		i++;
		if (i < ac)
			write(1, "\n", 1);
	}
	return (0);
}
