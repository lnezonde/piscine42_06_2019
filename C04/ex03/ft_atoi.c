/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:59:25 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/17 18:38:55 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_num(char c)
{
	if (c < 48 || c > 57)
		return (0);
	else
		return (1);
}

char	*ft_no_space(char *str)
{
	while (str[0] == '\t' || str[0] == '\n' || str[0] == '\f' || str[0] == '\r'
			|| str[0] == ' ' || str[0] == '\v')
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

char	*ft_no_sign(char *str)
{
	while (str[0] == '-' || str[0] == '+')
		str++;
	return (str);
}

int		ft_atoi(char *str)
{
	int sign;
	int	str_int;
	int i;

	str = ft_no_space(str);
	sign = ft_pos_or_neg(str);
	str = ft_no_sign(str);
	i = 0;
	str_int = 0;
	while (ft_is_num(str[i]) == 1)
	{
		str_int = str_int * 10 + (str[i] - '0');
		i++;
	}
	return (str_int * sign);
}
