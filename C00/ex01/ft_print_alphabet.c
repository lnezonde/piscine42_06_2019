/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:53:19 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/07 09:20:25 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int		c_ascii;
	char	c;

	c_ascii = 97;
	c = 'a';
	while (c_ascii <= 122)
	{
		c = (char)c_ascii;
		write(1, &c, 1);
		c_ascii++;
	}
}
