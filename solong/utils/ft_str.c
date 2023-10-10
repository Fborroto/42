/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:01:51 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/19 02:33:25 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	*ft_game_itoa(int n)
{
	int		i;
	char	*s;
	int		tmp;

	i = 0;
	tmp = n;
	while (tmp)
	{
		tmp /= 10;
		i ++;
	}
	s = (char *)malloc(i * sizeof(char));
	if (!s)
		return (NULL);
	s[i] = 0;
	if (n == 0)
		s[i] = '0';
	while (i--)
	{
		s[i] = n % 10 + '0';
		n /= 10;
	}
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n--)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return ((void *)dest);
}

char	*join_move(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = ft_strlen(s1);
	str = ft_memcpy(str, s1, i);
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}
