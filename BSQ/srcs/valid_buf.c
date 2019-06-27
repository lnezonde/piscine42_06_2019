/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:05:46 by cclaude           #+#    #+#             */
/*   Updated: 2019/06/26 22:05:16 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_linelen(char *buf, int i)
{
	int	c;

	c = 0;
	while (buf[i++] != '\n')
		c++;
	return (c);
}

void	first_line(char *buf, char *chars)
{
	int		i;

	i = 0;
	if (ft_atoi(buf) <= 0)
		return ;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	if (buf[i] < 32)
		return ;
	if (buf[i + 1] < 32 || buf[i + 1] == buf[i])
		return ;
	if (buf[i + 2] < 32 || buf[i + 2] == buf[i - 1] || buf[i + 2] == buf[i])
		return ;
	if (buf[i + 3] != '\n')
		return ;
	chars[0] = buf[i];
	chars[1] = buf[i + 1];
}

int		valid_lines(char *buf, int i, char *chars)
{
	int	count;
	int	line;

	count = 0;
	line = ft_linelen(buf, i);
	while (buf[i] != '\0')
	{
		if (ft_linelen(buf, i) != line)
			return (0);
		while (buf[i] != '\n')
		{
			if (buf[i] != chars[0] && buf[i] != chars[1])
				return (0);
			i++;
		}
		i++;
		count++;
	}
	if (count != ft_atoi(buf))
		return (0);
	return (1);
}

int		valid_buf(char *buf)
{
	int		i;
	char	chars[2];

	chars[0] = 0;
	chars[1] = 0;
	first_line(buf, chars);
	if (chars[0] == 0)
		return (0);
	i = 0;
	while (buf[i] != '\n')
		i++;
	i++;
	if (valid_lines(buf, i, chars) == 0)
		return (0);
	return (1);
}
