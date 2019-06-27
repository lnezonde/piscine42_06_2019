/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:13:06 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/07 09:24:19 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	chiffre_char;
	int		chiffre;

	chiffre_char = '0';
	chiffre = 48;
	while (chiffre <= 57)
	{
		chiffre_char = (char)chiffre;
		write(1, &chiffre_char, 1);
		chiffre++;
	}
}
