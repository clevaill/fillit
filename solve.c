/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:52:27 by sgauguet          #+#    #+#             */
/*   Updated: 2017/10/05 16:16:57 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_convert(char *str, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 'A' + k;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			str[i] = j;
		i++;
	}
	return (str);
}

int		ft_define_size(int nb_tetriminos)
{
	int size;

	size = 2;
	while ((size * size) < (nb_tetriminos * 4))
	{
		size++;
	}
	return (size);
}

char	**ft_create_map(int size, int y)
{
	char	**map;
	int		x;

	map = malloc(sizeof(*map) * (size + 1));
	x = 0;
	while (x <= size)
	{
		map[x] = ft_memalloc(size + 1);
		x++;
	}
	x = 0;
	y = 0;
	while (x < size)
	{
		while (y < size)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y + 1] = '\0';
		y = 0;
		x++;
	}
	map[x] = NULL;
	return (map);
}
