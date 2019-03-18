/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:15:21 by sgauguet          #+#    #+#             */
/*   Updated: 2017/10/05 17:51:29 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	return (1);
}

int		ft_check_place(char **map, char *tetriminos, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!map || !tetriminos)
		return (0);
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] >= 'A' && tetriminos[i] <= 'Z')
		{
			if (!map[x] || map[x][y] != '.')
				return (0);
		}
		y++;
		j++;
		if (j == 5)
		{
			x++;
			y = y - j;
			j = 0;
		}
		i++;
	}
	return (1);
}

char	**ft_clean_tetriminos(char **map, char *tetriminos, int x, int y)
{
	char	a;
	int		i;

	i = 0;
	while (tetriminos[i] == '.' || tetriminos[i] == '\n')
		i++;
	a = tetriminos[i];
	while (map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == a)
				map[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	return (map);
}

char	**ft_add_tetriminos(char **map, char *tetriminos, int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!map || !tetriminos)
		return (NULL);
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] >= 'A' && tetriminos[i] <= 'Z')
			map[x][y] = tetriminos[i];
		y++;
		i++;
		j++;
		if (j == 5)
		{
			x++;
			y = y - j;
			j = 0;
		}
	}
	return (map);
}

int		ft_solve(char **map, char **tetriminos, int x, int y)
{
	if (*tetriminos == NULL)
	{
		ft_print_map(map);
		return (1);
	}
	while (map[x] != NULL)
	{
		while (map[x][y] != '\0')
		{
			if (ft_check_place(map, *tetriminos, x, y) == 1)
			{
				ft_add_tetriminos(map, *tetriminos, x, y);
				if (ft_solve(map, (tetriminos + 1), 0, 0) == 1)
					return (1);
				else
					ft_clean_tetriminos(map, *tetriminos, 0, 0);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
