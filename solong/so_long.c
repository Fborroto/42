/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:41:58 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/21 00:53:45 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data		data;

	data.mlx = mlx_init();
	if (argc != 2 || ft_filename(argv[1]))
	{
		ft_putstr("Error\n");
		ft_putstr("Usage: ./so_long [map.ber]\n");
		exit(1);
	}
	data.map = ft_get_map(argv[1]);
	ft_check_map(&data);
	ft_data_init(&data);
	data.win = mlx_new_window(data.mlx,
			data.win_x * 64, data.win_y * 64 + 50, "so_long");
	ft_draw_map(&data);
	mlx_string_put(data.mlx, data.win, 0,
		data.win_y * 64 + 10, 0xccccff, "Moves: 0");
	mlx_key_hook(data.win, *ft_key_hook, &data);
	mlx_hook(data.win, 17, 0, ft_close, (void *)&data);
	mlx_loop_hook(data.mlx, *ft_loop_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
