/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:11:05 by fborroto          #+#    #+#             */
/*   Updated: 2023/01/23 19:58:55 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const*s2)
{
	int		size;
	char	*s3;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (0);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	s3 = (char *) malloc(size * sizeof (char));
	if (!s3)
		return (0);
	while (s1[i])
		s3[i2++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[i2++] = s2[i++];
	s3[i2++] = 0;
	return (s3);
}
