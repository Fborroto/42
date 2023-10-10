/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:12:14 by fborroto          #+#    #+#             */
/*   Updated: 2023/01/23 19:05:27 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s2;

	size = ft_strlen((char *)s1) + 1;
	if (!s1)
		return (0);
	s2 = (char *) malloc(size * sizeof (char));
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, size);
	return ((char *)s2);
}
