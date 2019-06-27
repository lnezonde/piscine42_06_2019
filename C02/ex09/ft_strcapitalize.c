/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:56:30 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/11 15:44:31 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_char_is_alpha(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int		ft_char_is_number(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	str = ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (ft_char_is_alpha(str[i]) == 1)
		{
			if (i == 0)
			{
				str[i] -= 32;
				i++;
			}
			if (ft_char_is_alpha(str[i - 1]) == 0 &&
					ft_char_is_number(str[i - 1]) == 0)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
