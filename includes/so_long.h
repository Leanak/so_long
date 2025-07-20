/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenakach <lenakach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:56:39 by lenakach          #+#    #+#             */
/*   Updated: 2025/07/20 21:37:54 by lenakach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>

# define W		119 
# define A		97
# define S		115
# define D		100
# define ESC	65307
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363

typedef struct s_window
{
	void	*mlx;
	void	*mlx_win;
	int		img_width;
	int		img_height;
	void	*img_back;
	void	*img_wall_ext;
	void	*img_wall;
	void	*img_fence_up;
	void	*img_fence_down;
	void	*img_fence_left;
	void	*img_fence_right;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		x;
	int		y;
	char	**map;
	int		collect_max;
	int		collect;
	int		exit_max;
	int		step;
}			t_window;

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

//Maps parsing
char	**read_map(char *filename, t_window *game);
int		is_mur(char **map);
int		is_rectangle(char **map);
int		check_elements(char **map, t_window *game);
int		check_playability(char **map, t_window *game);

//Maps utils
int		count_len(char *str);
int		count_true_line(char**map);
int		count_lines(int fd);
char	**dup_map(char **map);
void	free_map(char **map);
void	free_struct(t_window *game);

//Test
void	print_map(char **map);

//Affichage
void	render_map(t_window *game);
void	init_images(t_window *game);

//Mouvements
int	handle_key(int keycode, t_window *game);

#endif
