/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:20:48 by fborroto          #+#    #+#             */
/*   Updated: 2023/02/08 17:40:38 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	i2;

	if (!dest && size == 0)
		return (0);
	if (((size_t)ft_strlen(dest) >= size))
		return (size + (size_t)ft_strlen(src));
	i2 = ft_strlen(dest);
	i = 0;
	while (src[i] != 0 && i2 + 1 < size)
	{
		dest[i2] = src[i];
		i2++;
		i++;
	}
	dest[i2] = '\0';
	return (ft_strlen(dest) + ft_strlen(src + i));
}
