/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:23:15 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/18 23:31:51 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_data_init(t_data *data)
{
	data->win_x = ft_strlen(data->map[0]);
	data->win_y = ft_map_y(data->map);
	data->movements = 0;
	data->collectibles = 0;
}

int	ft_filename(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e'
		|| str[i - 3] != 'b' || str[i - 4] != '.')
		return (1);
	return (0);
}

char	**ft_get_map(char *str)
{
	int		fd;
	char	*map;
	char	*line;
	char	**mapped;

	map = malloc(sizeof(char) * 1);
	line = "";
	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nMap not found\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map = ft_strjoin(map, line);
		free(line);
	}
	close(fd);
	free(line);
	if (!map)
		ft_error("Error\nMap not found\n");
	mapped = ft_split(map, '\n');
	free(map);
	return (mapped);
}
