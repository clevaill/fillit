/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clevaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 11:11:51 by clevaill          #+#    #+#             */
/*   Updated: 2017/10/09 10:38:45 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_tetri(char **tetriminos)
{
	int		i;

	i = 0;
	while (tetriminos[i])
	{
		tetriminos[i] = ft_convert(tetriminos[i], i);
		i++;
	}
	return (tetriminos);
}

int		ft_check(char *str)
{
	int i;
	int j;
	int k;
	int l;

	i = ft_check_length(str);
	if (i > 0)
		i = 1;
	j = ft_check_line(str);
	k = ft_check_sharp(str);
	l = ft_check_contact(str);
	return (i + j + k + l);
}

char	*ft_read_file(char *str)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*result;

	if ((fd = open(str, O_RDONLY)) == -1)
		return (NULL);
	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (NULL);
	buf[ret] = '\0';
	if (ft_check(buf) != 4)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	result = ft_strdup(buf);
	return (result);
}

int		main(int argc, char **argv)
{
	char	**map;
	char	**tab;
	char	**tetriminos;
	char	*string;
	int		size;

	if (argc != 2)
	{
		ft_putstr("usage : fillit expects only 1 argument");
		return (0);
	}
	if ((string = ft_read_file(argv[1])) == NULL)
		return (0);
	tab = ft_create_tab(string, ft_check_length(string), 0, -1);
	tetriminos = ft_tetri(ft_compare_tetriminos(tab, ft_check_length(string)));
	size = ft_define_size(ft_check_length(string));
	map = ft_create_map(size, 0);
	while ((ft_solve(map, tetriminos, 0, 0) != 1) && size < 50)
	{
		size++;
		map = ft_create_map(size, 0);
	}
	return (0);
}
