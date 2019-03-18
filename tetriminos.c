/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clevaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 14:50:32 by clevaill          #+#    #+#             */
/*   Updated: 2017/10/03 10:49:02 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_empty_tab(int nb_tetriminos, int x)
{
	char	**ptr;

	ptr = malloc(sizeof(*ptr) * (nb_tetriminos + 1));
	while (x <= nb_tetriminos)
	{
		ptr[x] = ft_memalloc(17);
		x++;
	}
	return (ptr);
}

char	**ft_create_tab(char *string, int nb_tetriminos, int x, int y)
{
	char	**ptr;
	int		i;

	ptr = ft_empty_tab(nb_tetriminos, x);
	i = 0;
	while (string[i] != '\0')
	{
		if (++y == 16)
		{
			ptr[x][y] = '\0';
			x++;
			y = 0;
			i++;
		}
		if (string[i] != '\n')
			ptr[x][y] = string[i];
		else
			y--;
		i++;
	}
	ptr[x] = NULL;
	return (ptr);
}

char	*ft_types_of_tetriminos(int i)
{
	char **tab;

	tab = malloc(sizeof(*tab) * 19);
	tab[0] = "#...\n#...\n#...\n#...\n\0";
	tab[1] = "####\n....\n....\n....\n\0";
	tab[2] = "##..\n##..\n....\n....\n\0";
	tab[3] = "###.\n.#..\n....\n....\n\0";
	tab[4] = ".#..\n###.\n....\n....\n\0";
	tab[5] = ".#..\n##..\n.#..\n....\n\0";
	tab[6] = "#...\n##..\n#...\n....\n\0";
	tab[7] = "###.\n#...\n....\n....\n\0";
	tab[8] = "#...\n#...\n##..\n....\n\0";
	tab[9] = "..#.\n###.\n....\n....\n\0";
	tab[10] = "##..\n.#..\n.#..\n....\n\0";
	tab[11] = "###.\n..#.\n....\n....\n\0";
	tab[12] = "##..\n#...\n#...\n....\n\0";
	tab[13] = "#...\n###.\n....\n....\n\0";
	tab[14] = ".#..\n.#..\n##..\n....\n\0";
	tab[15] = "##..\n.##.\n....\n....\n\0";
	tab[16] = ".#..\n##..\n#...\n....\n\0";
	tab[17] = ".##.\n##..\n....\n....\n\0";
	tab[18] = "#...\n##..\n.#..\n....\n\0";
	return (tab[i]);
}

char	*search_tetriminos(int i)
{
	char **tab;

	tab = malloc(sizeof(*tab) * 19);
	tab[0] = "#...#...#...#\0";
	tab[1] = "####\0";
	tab[2] = "##..##\0";
	tab[3] = "###..#\0";
	tab[4] = "#..###\0";
	tab[5] = "#..##...#\0";
	tab[6] = "#...##..#\0";
	tab[7] = "###.#\0";
	tab[8] = "#...#...##\0";
	tab[9] = "#.###\0";
	tab[10] = "##...#...#\0";
	tab[11] = "###...#\0";
	tab[12] = "##..#...#\0";
	tab[13] = "#...###\0";
	tab[14] = "#...#..##\0";
	tab[15] = "##...##\0";
	tab[16] = "#..##..#\0";
	tab[17] = "##.##\0";
	tab[18] = "#...##...#\0";
	return (tab[i]);
}

char	**ft_compare_tetriminos(char **tab, int nb_tetriminos)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = malloc(sizeof(*result) * (nb_tetriminos + 1));
	while (j < nb_tetriminos)
	{
		while ((ft_strstr(tab[j], search_tetriminos(i)) == NULL) && i < 18)
			i++;
		result[j] = ft_strdup(ft_types_of_tetriminos(i));
		i = 0;
		j++;
	}
	result[j] = NULL;
	return (result);
}
