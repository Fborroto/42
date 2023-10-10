/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:13:27 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/21 01:19:37 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(int key, t_data **data)
{
	int	x;
	int	y;

	x = (*data)->el->player_x;
	y = (*data)->el->player_y;
	if ((key == UP && (*data)->map[y - 1][x] != '1') && (
		(*data)->map[y - 1][x] != 'E' || (*data)->el->collectible == 0))
		ft_put_sprite(data, (*data)->el->player_y - 1, (*data)->el->player_x);
	else if (key == LEFT && (*data)->map[y][x - 1] != '1' && (
		(*data)->map[y][x - 1] != 'E' || (*data)->el->collectible == 0))
		ft_put_sprite(data, (*data)->el->player_y, (*data)->el->player_x - 1);
	else if (key == RIGHT && (*data)->map[y][x + 1] != '1' && (
		(*data)->map[y][x + 1] != 'E' || (*data)->el->collectible == 0))
		ft_put_sprite(data, (*data)->el->player_y, (*data)->el->player_x + 1);
	else if (key == DOWN && (*data)->map[y + 1][x] != '1' && (
		(*data)->map[y + 1][x] != 'E' || (*data)->el->collectible == 0))
		ft_put_sprite(data, (*data)->el->player_y + 1, (*data)->el->player_x);
}

int	ft_key_hook(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		ft_free_data(&data);
	}
	if (key == UP)
		ft_move(UP, &data);
	if (key == DOWN)
		ft_move(DOWN, &data);
	if (key == LEFT)
		ft_move(LEFT, &data);
	if (key == RIGHT)
		ft_move(RIGHT, &data);
	return (0);
}
