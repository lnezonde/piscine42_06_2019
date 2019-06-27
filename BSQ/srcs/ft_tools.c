/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:52:39 by cclaude           #+#    #+#             */
/*   Updated: 2019/06/26 22:05:09 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		l_dest;
	int		l_src;
	char	*final;

	i = 0;
	l_dest = ft_strlen(dest);
	l_src = ft_strlen(src);
	final = malloc(sizeof(char) * (l_dest + l_src + 1));
	while (dest[i])
	{
		final[i] = dest[i];
		i++;
	}
	i = 0;
	while (src[i])
	{
		final[i + l_dest] = src[i];
		i++;
	}
	final[i + l_dest] = '\0';
	return (final);
}

int		ft_char_is_num(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_atoi(char *file)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (file[i] >= '0' && file[i] <= '9')
	{
		n = n * 10 + file[i] - 48;
		i++;
	}
	return (n);
}
