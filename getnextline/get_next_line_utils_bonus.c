/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:10:22 by fborroto          #+#    #+#             */
/*   Updated: 2023/03/18 00:10:22 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (0);
	s3 = (char *) malloc(ft_strlen((char *)s1)
			+ ft_strlen((char *)s2) + 1 * sizeof (char));
	if (!s3)
		return (0);
	while (s1[i])
		s3[i2++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[i2++] = s2[i++];
	s3[i2++] = 0;
	free (s1);
	return (s3);
}
