/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:10:12 by fborroto          #+#    #+#             */
/*   Updated: 2023/03/18 00:10:12 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *nxtl)
{
	int		nread;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	nread = 1;
	while (ft_strchr(nxtl, '\n') == 0 && nread != 0)
	{
		nread = read(fd, buffer, BUFFER_SIZE);
		if (nread == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[nread] = 0;
		nxtl = ft_strjoin(nxtl, buffer);
	}
	free (buffer);
	return (nxtl);
}

char	*get_theline(char *nextline)
{
	int		i;
	int		i2;
	char	*theline;

	i = 0;
	i2 = 0;
	if (!nextline[i])
		return (NULL);
	while (nextline[i] && nextline[i - 1] != '\n')
	i ++;
	theline = (char *)malloc(sizeof(char) * (i + 1));
	if (!theline)
		return (NULL);
	while (i2 < i)
	{
		theline[i2] = nextline[i2];
		i2++;
	}
	theline[i2] = 0;
	return (theline);
}

char	*fix_atnext(char *nextline)
{
	int		i;
	int		i2;
	char	*newnext;

	i = 0;
	i2 = 0;
	while (nextline[i] && nextline[i - 1] != '\n')
		i++;
	if (!nextline[i])
	{
		free(nextline);
		return (NULL);
	}
	newnext = (char *) malloc(sizeof (char) * (ft_strlen(nextline) - i + 1));
	if (!newnext)
		return (NULL);
	while (nextline[i])
	{
		newnext[i2] = nextline[i];
		i2 ++;
		i ++;
	}
	newnext[i2] = 0;
	free(nextline);
	return (newnext);
}

char	*get_next_line(int fd)
{
	static char	*nextline[4096];
	char		*theline;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nextline[fd] = read_line(fd, nextline[fd]);
	if (!nextline[fd])
		return (NULL);
	theline = get_theline(nextline[fd]);
	nextline[fd] = fix_atnext(nextline[fd]);
	return (theline);
}
