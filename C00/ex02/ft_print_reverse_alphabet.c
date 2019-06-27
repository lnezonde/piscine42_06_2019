/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:19:16 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/07 09:22:42 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int		c_ascii;
	char	c;

	c_ascii = 122;
	c = 'z';
	while (c_ascii >= 97)
	{
		c = (char)c_ascii;
		write(1, &c, 1);
		c_ascii--;
	}
}
