/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_malloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:15:37 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/22 20:15:39 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#define BUF_SIZE 4096

void	ft_put_lines_in_tab(char *file, char **tab)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
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
}

void	ft_read_file(char *buf)
{
	int fd;
	int ret;

	if ((fd = open("numbers.dict", O_RDONLY)) == -1)
	{
		ft_putstr("Error\n");
	}
	else
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
	}
}

char	**ft_make_tab(void)
{
	char	**tab;
	char	*file;
	int		i;

	if (!(tab = malloc(sizeof(char *) * 41)))
		return (NULL);
	i = 0;
	while (i <= 41)
	{
		tab[i] = malloc(sizeof(char) * 500);
		i++;
	}
	if (!(file = malloc(sizeof(char) * BUF_SIZE)))
		return (NULL);
	ft_read_file(file);
	ft_put_lines_in_tab(file, tab);
	return (tab);
}
