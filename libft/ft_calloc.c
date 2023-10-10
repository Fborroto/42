/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:59:00 by fborroto          #+#    #+#             */
/*   Updated: 2023/02/08 13:36:57 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	s = (void *)malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, size * count);
	return ((void *) s);
}
