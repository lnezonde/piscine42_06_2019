/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:37:26 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/17 19:16:19 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_para_is_good(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t'
		|| base[i] == '\r' || base[i] == '\n' || base[i] == '\v'
		|| base[i] == '\f' || base[i] == ' ')
			return (0);
		while (base[i + j])
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

int		ft_is_in_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_no_space_no_sign(char *str, int t)
{
	while ((str[0] == '\t' || str[0] == '\n' || str[0] == '\f' || str[0] == '\r'
			|| str[0] == ' ' || str[0] == '\v') && t == 0)
		str++;
	while ((str[0] == '-' || str[0] == '+') && t == 1)
		str++;
	return (str);
}

int		ft_pos_or_neg(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	if (j % 2 == 0)
		return (1);
	else
		return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	sign;
	int	str_int;

	i = 0;
	j = 0;
	str = ft_no_space_no_sign(str, 0);
	sign = ft_pos_or_neg(str);
	str = ft_no_space_no_sign(str, 1);
	while (base[i])
		i++;
	if (ft_para_is_good(base) == 0)
		return (0);
	str_int = 0;
	while (ft_is_in_base(base, str[j]) != -1)
	{
		str_int = str_int * i + ft_is_in_base(base, str[j]);
		j++;
	}
	return (str_int * sign);
}
