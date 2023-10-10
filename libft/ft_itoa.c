/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:02:30 by fborroto          #+#    #+#             */
/*   Updated: 2023/01/31 19:46:37 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_size(int c)
{
	int	i;

	i = 0;
	if (c <= 0)
		i++;
	while (c)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int c)
{
	int			size;
	const char	*base = "01234567890";
	char		*ito;

	size = ft_size(c);
	ito = (char *)malloc(size + 1 * sizeof (char));
	if (!ito)
		return (0);
	if (c == 0)
		ito[0] = '0';
	if (c < 0)
		ito[0] = '-';
	ito[size] = 0;
	while (c)
	{
		if (c > 0)
			ito[--size] = base[c % 10];
		else
			ito[--size] = base[c % 10 * -1];
		c /= 10;
	}
	return (ito);
}
