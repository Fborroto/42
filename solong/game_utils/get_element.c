/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:26:44 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/20 01:08:21 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_player_position(t_elements *el)
{
	el->player++;
	el->player_x = el->x;
	el->player_y = el->y;
}

void	ft_check_el(t_data **data)
{
	(*data)->el = malloc(sizeof(t_elements));
	(*data)->el->y = 0;
	(*data)->el->collectible = 0;
	(*data)->el->exit = 0;
	(*data)->el->player = 0;
	while ((*data)->map[(*data)->el->y])
	{
		(*data)->el->x = 0;
		while ((*data)->map[(*data)->el->y][(*data)->el->x])
		{
			if ((*data)->map[(*data)->el->y][(*data)->el->x] == 'C')
				(*data)->el->collectible++;
			if ((*data)->map[(*data)->el->y][(*data)->el->x] == 'E')
				(*data)->el->exit++;
			if ((*data)->map[(*data)->el->y][(*data)->el->x] == 'P')
				ft_player_position((*data)->el);
			(*data)->el->x++;
		}
		(*data)->el->y++;
	}
	if ((*data)->el->collectible == 0 || (*data)->el->exit
		== 0 || (*data)->el->player != 1)
		ft_error_free("Error\nMap missing el\n", (*data)->map);
}

void	ft_check_non_el(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data)->map[i])
	{
		j = 0;
		while ((*data)->map[i][j])
		{
			if ((*data)->map[i][j] != '1' && (*data)->map[i][j] != '0'
				&& (*data)->map[i][j] != 'C' && (*data)->map[i][j] != 'E'
				&& (*data)->map[i][j] != 'P' && (*data)->map[i][j] != 'Q')
				ft_error_free("Error\nMap contains invalid characters\n",
					(*data)->map);
			j++;
		}
		i++;
	}
}
