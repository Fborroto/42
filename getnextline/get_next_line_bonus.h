/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:10:19 by fborroto          #+#    #+#             */
/*   Updated: 2023/03/18 00:10:19 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*get_theline(char *nextline);
char	*read_line(int fd, char *nxtl);
char	*fix_atnext(char *nextline);

int		ft_strlen(char *s);
char	*ft_strchr( char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
