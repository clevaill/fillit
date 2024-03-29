/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:49:24 by sgauguet          #+#    #+#             */
/*   Updated: 2017/02/03 20:19:09 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *result;

	result = (char*)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}
