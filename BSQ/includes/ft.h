/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:49:23 by cclaude           #+#    #+#             */
/*   Updated: 2019/06/26 22:40:05 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>

struct			s_coord
{
	int	size;
	int	line;
	int	col;
};

int				ft_char_is_num(char c);
int				ft_atoi(char *file);
char			ft_find_info(char *file, int pos);
void			ft_trad_tab(char **tab, char empty);
void			ft_put_lines_in_tab(char *file, char **tab);
char			*ft_read_file(char *map);
int				ft_map_size(char *file, char l);
char			**ft_make_tab(char *file);
void			bsq_launch(char *map, int params);
char			**pascal(char **tab);
struct s_coord	find_square(char **tab);
void			print_sol(char **tab, struct s_coord pos, char full);
int				ft_linelen(char *buf, int i);
void			first_line(char *buf, char *chars);
int				valid_lines(char *buf, int i, char *chars);
int				valid_buf(char *buf);
int				ft_strlen(char *str);
char			*ft_strcat(char *dest, char *src);
int				main(int ac, char **av);
char			*ft_read_stdin(void);
#endif
