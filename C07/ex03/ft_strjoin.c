/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 10:02:30 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/20 10:02:32 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_put_sep(int i2, char *strf, char *sep)
{
	int i;

	i = 0;
	while (sep[i])
	{
		strf[i2] = sep[i];
		i2++;
		i++;
	}
	return (i2);
}

void	ft_fill_string(int size, char *strf, char **strs, char *sep)
{
	int i;
	int i2;
	int j;

	i = 0;
	i2 = 0;
	j = 0;
	while (i < size)
	{
		while (strs[i][j])
		{
			strf[i2] = strs[i][j];
			i2++;
			j++;
		}
		if (i < (size - 1))
			i2 = ft_put_sep(i2, strf, sep);
		j = 0;
		i++;
	}
	strf[i2] = '\0';
}

int		ft_def_size_strs(int size_strs, int size, char **strs)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < size)
	{
		while (strs[i][j])
			j++;
		size_strs += j;
		j = 0;
		i++;
	}
	return (size_strs);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*strf;
	int		size_strs;
	int		size_sep;

	if (sep == NULL || strs == NULL)
		return (NULL);
	if (size == 0)
	{
		strf = malloc(sizeof(char));
		strf[0] = '\0';
		return (strf);
	}
	size_strs = 0;
	size_strs = ft_def_size_strs(size_strs, size, strs);
	size_sep = 0;
	while (sep[size_sep])
		size_sep++;
	if (!(strf = malloc(sizeof(char) * ((size - 1)
	* size_sep) + size_strs + 1)))
		return (NULL);
	ft_fill_string(size, strf, strs, sep);
	return (strf);
}
