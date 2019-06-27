/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnezonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:20:54 by lnezonde          #+#    #+#             */
/*   Updated: 2019/06/23 23:20:58 by lnezonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>

void	ft_putchar(char c);
char	**ft_make_tab(void);
int		ft_char_is_numeric(char c);
void	ft_print_triplet(char *triplet, char **tab);
void	ft_print_alpha(char **tab, char *to_find);
int		ft_strlen(char *str);
char	**ft_split_nb(char *nb);
void	ft_send_triplet(char **tab_nb, char **tab);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_putstr(char *str);

#endif
