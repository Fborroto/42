/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:14:10 by fborroto          #+#    #+#             */
/*   Updated: 2023/01/31 18:38:20 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const s1, char const *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1 == s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		size;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 || !set)
		return (NULL);
	size = ft_strlen((char *) s1);
	while (s1[i] && ft_inset(s1[i], set))
		i ++;
	while (size > i && ft_inset(s1[size - 1], set))
		size --;
	trimmed = (char *) malloc((size - i + 1) * sizeof (char));
	if (!trimmed)
		return (NULL);
	while (i < size)
		trimmed[i2++] = s1[i++];
	trimmed[i2] = 0;
	return (trimmed);
}
