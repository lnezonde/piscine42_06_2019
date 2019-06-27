/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:00:43 by cclaude           #+#    #+#             */
/*   Updated: 2019/06/26 22:30:10 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_read_file(char *map)
{
	int		fd;
	int		ret;
	char	buf[4096];
	int		buf_size;
	char	*tmp;

	buf_size = 4096;
	tmp = malloc(sizeof(char));
	if ((fd = open(map, O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buf, buf_size)) != 0)
	{
		buf[ret] = '\0';
		tmp = ft_strcat(tmp, buf);
	}
	return (tmp);
}

char	*ft_read_stdin(void)
{
	int		ret;
	char	buf[4096];
	int		buf_size;
	char	*tmp;

	buf_size = 4096;
	tmp = malloc(sizeof(char));
	while ((ret = read(0, buf, buf_size)) != 0)
	{
		buf[ret] = '\0';
		tmp = ft_strcat(tmp, buf);
	}
	return (tmp);
}
