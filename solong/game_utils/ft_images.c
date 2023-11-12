/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:11:45 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/21 00:56:23 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_image_to_win(t_data **data, int x, int y, void *img)
{
	mlx_put_image_to_window((*data)->mlx, (*data)->win, img, x, y);
}

void	open_images(t_data **data)
{	
	int		img_x;
	int		img_y;

	(*data)->w_img = mlx_xpm_file_to_image((*data)->mlx,
			"img/wall.xpm", &img_x, &img_y);
	(*data)->p_img = mlx_xpm_file_to_image((*data)->mlx,
			"img/player.xpm", &img_x, &img_y);
	(*data)->c_img = mlx_xpm_file_to_image((*data)->mlx,
			"img/coin.xpm", &img_x, &img_y);
	(*data)->f_img = mlx_xpm_file_to_image((*data)->mlx,
			"img/floor.xpm", &img_x, &img_y);
	(*data)->n_img = mlx_xpm_file_to_image((*data)->mlx,
			"img/nero.xpm", &img_x, &img_y);
	(*data)->q_img = mlx_xpm_file_to_image((*data)->mlx,
			"img/enemy.xpm", &img_x, &img_y);
	(*data)->p2_img = mlx_xpm_file_to_image((*data)->mlx,
			"img/player2.xpm", &img_x, &img_y);
}

void	ft_draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	open_images(&data);
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				ft_image_to_win(&data, x * 64, y * 64, data->w_img);
			if (data->map[y][x] == 'C')
				ft_image_to_win(&data, x * 64, y * 64, data->c_img);
			if (data->map[y][x] == 'P')
				ft_image_to_win(&data, x * 64, y * 64, data->p_img);
			if (data->map[y][x] == '0')
				ft_image_to_win(&data, x * 64, y * 64, data->f_img);
			if (data->map[y][x] == 'Q')
				ft_image_to_win(&data, x * 64, y * 64, data->q_img);
			x++;
		}
		y++;
	}
}

void	ft_moves(t_data ***data)
{
	char	*str;
	char	*str2;

	(**data)->movements += 1;
	str = ft_game_itoa((**data)->movements);
	str2 = join_move("Moves: ", str);
	mlx_put_image_to_window((**data)->mlx, (**data)->win,
		(**data)->n_img, 0, (**data)->win_y * 64);
	mlx_string_put((**data)->mlx, (**data)->win, 0,
		(**data)->win_y * 64 + 10, 0xccccff, str2);
	free(str);
	free(str2);
}

void	ft_put_sprite(t_data **data, int y, int x)
{
	int	x1;
	int	y1;

	ft_moves(&data);
	if ((*data)->map[y][x] == 'Q')
		ft_endgame("You lose!\n", &data);
	if ((*data)->map[y][x] == 'C')
	{
		(*data)->el->collectible--;
		(*data)->map[y][x] = '0';
	}
	if ((*data)->map[y][x] == 'E')
		ft_endgame("You win!\n", &data);
	x1 = (*data)->el->player_x;
	y1 = (*data)->el->player_y;
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->p_img, x * 64, y * 64);
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->f_img, x1 * 64, y1 * 64);
	(*data)->el->player_x = x;
	(*data)->el->player_y = y;
}
