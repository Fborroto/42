/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:08:19 by fborroto          #+#    #+#             */
/*   Updated: 2023/02/08 13:22:50 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;
	int		needlelen;

	i = 0;
	if (!haystack && len == 0)
		return (NULL);
	needlelen = ft_strlen((char *)needle);
	if (*needle == 0 || !needle)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{	
		i2 = 0;
		while (needle != 0 && i + i2 < len && needle[i2] == haystack[i + i2])
		{
			if ((int)i2 + 1 == needlelen)
				return ((char *)(haystack + i));
			i2++;
		}
		i++;
	}
	return (0);
}
