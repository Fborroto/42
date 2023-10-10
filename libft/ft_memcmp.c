/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:37:31 by fborroto          #+#    #+#             */
/*   Updated: 2023/01/31 18:51:59 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1copy;
	unsigned char	*s2copy;

	s1copy = (unsigned char *) s1;
	s2copy = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s1copy[i] != s2copy[i])
			return ((unsigned char) s1copy[i] - (unsigned char) s2copy[i]);
		i ++;
	}
	return (0);
}
