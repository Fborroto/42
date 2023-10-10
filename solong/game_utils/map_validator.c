/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:24:46 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/18 23:32:10 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_map_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == ft_map_y(map) - 1)
			{
				if (map[i][j] != '1')
					ft_error_free("Error\nMap not surrounded by walls\n", map);
			}
			else
			{
				if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
					ft_error_free("Error\nMap not surrounded by walls\n", map);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_rectangular(char **map)
{
	int	i;
	int	len;

	i = 0;
	while (map[i])
	{
		i++;
	}
	if (i == 0)
		ft_error_free("Error\nMap not rectangular\n", map);
	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			ft_error_free("Error\nMap not rectangular\n", map);
		i++;
	}
}

void	ft_check_map(t_data *data)
{
	ft_check_rectangular(data->map);
	ft_check_walls(data->map);
	ft_check_el(&data);
	ft_check_non_el(&data);
}
