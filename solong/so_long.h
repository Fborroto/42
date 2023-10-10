/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:48:38 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/21 01:13:08 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __APPLE__
#  include "mlx.h"
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define ESC 53

# elif __linux__
#  include "./mlx_linux/mlx.h"
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
#  define ESC 65307 
# endif

# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# include <unistd.h>

typedef struct s_elements
{
	int		x;
	int		y;
	int		collectible;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		wall;
}		t_elements;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*w_img;
	void		*c_img;
	void		*p_img;
	void		*p2_img;
	void		*f_img;
	void		*n_img;
	void		*q_img;
	char		**map;
	int			win_x;
	int			win_y;
	int			movements;
	int			collectibles;
	t_elements	*el;
}		t_data;

int		ft_strlen(char *s);
char	*ft_strchr( char *s, int c);
char	**ft_split(char *s, char c);
void	ft_error_free(char *str, char **map);
void	ft_error(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_game_itoa(int n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*join_move(char *s1, char *s2);

int		ft_filename(char *str);
char	**ft_get_map(char *filename);
int		ft_map_y(char **map);
void	ft_check_map(t_data *data);
void	ft_data_init(t_data *data);
void	ft_free_data(t_data **data);
int		ft_close(t_data *data);
void	ft_draw_map(t_data *data);
void	ft_check_el(t_data **data);
void	ft_check_walls(char **map);
void	ft_check_rectangular(char **map);
void	ft_check_non_el(t_data **data);
void	ft_move(int keycode, t_data **data);
int		ft_key_hook(int keycode, t_data *data);

void	ft_put_sprite(t_data **data, int y, int x);
void	open_images(t_data **data);
void	ft_image_to_win(t_data **data, int x, int y, void *img);
void	ft_player_position(t_elements *el);
void	ft_endgame(char *str, t_data ***data);
int		ft_loop_hook(t_data *data);

#endif