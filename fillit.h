/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 14:51:38 by sgauguet          #+#    #+#             */
/*   Updated: 2017/10/05 16:24:46 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define BUFF_SIZE 550

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_check_contact(char *str);
int		ft_check_loop(char *str, int i, int result, int len);
int		ft_check_length(char *str);
int		ft_check_sharp(char *str);
int		ft_check_line(char *str);
char	*ft_convert(char *str, int k);
char	**ft_create_map(int size, int y);
int		ft_check(char *str);
int		ft_define_size(int nb_tetriminos);
int		ft_check_place(char **map, char *tetriminos, int x, int y);
char	**ft_create_tab(char *string, int nb_tetriminos, int x, int y);
int		ft_solve(char **map, char **tetriminos, int x, int y);
int		ft_print_map(char **map);
char	**ft_compare_tetriminos(char **tab, int nb_tetriminos);
char	*ft_types_of_tetriminos(int i);
char	**ft_tetri(char **tetriminos);
char	**ft_empty_tab(int nb_tetriminos, int x);

#endif
