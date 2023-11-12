/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 00:54:07 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/21 01:09:14 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_loop_hook(t_data *data)
{
	static int	frame;

	frame++;
	if (frame > 10000)
	{
		ft_image_to_win(&data, data->el->player_x * 64,
			data->el->player_y * 64, data->p_img);

	}
	if (frame == 20000)
	{
		frame = 0;
		ft_image_to_win(&data, data->el->player_x * 64,
			data->el->player_y * 64, data->p2_img);
	}
	return (0);
}
