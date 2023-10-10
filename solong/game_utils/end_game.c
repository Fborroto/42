/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:43:47 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/21 01:27:56 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free_data(t_data **data)
{
	int	i;

	i = 0;
	while ((*data)->map[i])
	{
		free((*data)->map[i]);
		i++;
	}
	free((*data)->map);
	free((*data)->el);
	mlx_destroy_image((*data)->mlx, (*data)->f_img);
	mlx_destroy_image((*data)->mlx, (*data)->c_img);
	mlx_destroy_image((*data)->mlx, (*data)->p_img);
	mlx_destroy_image((*data)->mlx, (*data)->p2_img);
	mlx_destroy_image((*data)->mlx, (*data)->w_img);
	mlx_destroy_image((*data)->mlx, (*data)->n_img);
	mlx_destroy_image((*data)->mlx, (*data)->q_img);
	exit(0);
}

int	ft_close(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->el);
	mlx_destroy_image(data->mlx, data->f_img);
	mlx_destroy_image(data->mlx, data->c_img);
	mlx_destroy_image(data->mlx, data->p_img);
	mlx_destroy_image(data->mlx, data->p2_img);
	mlx_destroy_image(data->mlx, data->w_img);
	mlx_destroy_image(data->mlx, data->q_img);
	mlx_destroy_image(data->mlx, data->n_img);
	exit(0);
}

void	ft_endgame(char *str, t_data ***data)
{
	int	i;

	i = 0;
	ft_putstr(str);
	while ((**data)->map[i])
	{
		free((**data)->map[i]);
		i++;
	}
	free((**data)->map);
	free((**data)->el);
	mlx_destroy_image((**data)->mlx, (**data)->f_img);
	mlx_destroy_image((**data)->mlx, (**data)->c_img);
	mlx_destroy_image((**data)->mlx, (**data)->p_img);
	mlx_destroy_image((**data)->mlx, (**data)->p2_img);
	mlx_destroy_image((**data)->mlx, (**data)->w_img);
	mlx_destroy_image((**data)->mlx, (**data)->q_img);
	mlx_destroy_image((**data)->mlx, (**data)->n_img);
	exit(0);
}
