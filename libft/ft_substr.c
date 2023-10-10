/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:23:46 by fborroto          #+#    #+#             */
/*   Updated: 2023/02/08 11:59:29 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	size;
	size_t	end;

	end = 0;
	if (!s)
		return (NULL);
	size = ft_strlen((char *)s);
	if (start < size)
		end = size - start;
	if (end > len)
		end = len;
	subs = (char *) malloc((end + 1) * sizeof (char));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, end + 1);
	return (subs);
}
