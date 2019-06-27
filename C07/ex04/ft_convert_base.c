/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:12:47 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/20 17:12:48 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_para_is_good(char *base);
int		ft_atoi_base(char *str, char *base);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_nbr_size(int nb, int size_base)
{
	int i;

	i = 0;
	if (nb < 0)
		i++;
	while (nb / size_base != 0)
	{
		nb /= size_base;
		i++;
	}
	return (i + 1);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		size_base;
	int		size_nbr;
	char	*nbr_conv;
	long	nb;

	nb = nbr;
	size_base = ft_strlen(base);
	size_nbr = ft_nbr_size(nb, size_base);
	nbr_conv = malloc(sizeof(char) * size_nbr + 1);
	nbr_conv[size_nbr--] = '\0';
	if (nb < 0)
	{
		nbr_conv[0] = '-';
		nb *= -1;
	}
	nbr_conv[size_nbr--] = base[nb % size_base];
	while (nb / size_base != 0)
	{
		nb /= size_base;
		nbr_conv[size_nbr--] = base[nb % size_base];
	}
	return (nbr_conv);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (ft_para_is_good(base_from) && ft_para_is_good(base_to))
		return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
	else
		return (NULL);
}
