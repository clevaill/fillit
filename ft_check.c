/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 14:55:41 by sgauguet          #+#    #+#             */
/*   Updated: 2017/09/28 13:53:16 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_length(char *str)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			k++;
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			if (j != 20)
				return (0);
		}
		if (j == 20)
			j = -1;
		i++;
		j++;
	}
	if (j != 20 || k > 26)
		return (0);
	return (k);
}

int	ft_check_sharp(char *str)
{
	int i;
	int j;
	int result;

	i = 0;
	j = 1;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (str[i] == '#')
			result++;
		if (j == 20)
		{
			if (result != 4)
				return (0);
			j = -1;
			result = 0;
		}
		i++;
		j++;
	}
	return (1);
}

int	ft_check_loop(char *str, int i, int result, int len)
{
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#')
				result++;
			if (str[i + 1] == '#')
				result++;
			if (str[i - 5] == '#')
				result++;
			if (str[i + 5] == '#')
				result++;
		}
		if (i == len)
		{
			if (result < 6)
				return (0);
			result = 0;
			len = len + 21;
		}
	}
	if (result < 6)
		return (0);
	return (1);
}

int	ft_check_contact(char *str)
{
	int i;
	int result;
	int len;

	i = -1;
	result = 0;
	len = 20;
	return (ft_check_loop(str, i, result, len));
}

int	ft_check_line(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (j != 4)
				return (0);
			j = -1;
			if (str[i + 1] == '\n')
			{
				i++;
			}
		}
		i++;
		j++;
	}
	return (1);
}
