/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saciurus <saciurus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:37:37 by saciurus          #+#    #+#             */
/*   Updated: 2025/05/16 17:41:49 by saciurus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
	int		collected;
}			t_map;

typedef struct s_pathcheck
{
	int		collect_found;
	int		exit_found;
	int		enemy_found;
}			t_pathcheck;

typedef struct s_imgs
{
	void	*wall;
	void	*floor;
	void	*player_up;
	void	*player_down;
	void	*player_right;
	void	*player_left;
	void	*collectible;
	void	*open_exit;
	void	*closed_exit;
	void	*ennemy;
}			t_imgs;

typedef struct s_data
{
	t_map	*map;
	t_imgs	*imgs;
	void	*mlx;
	void	*win;
	char	**mapc;
	int	moves;
}			t_data;

//map parse
int			validate_map(t_map *map);
int			count_lines(int fd);
int			count_rows(int fd);
void		fill_sprites_map(char **map, void *mlx, void *win, t_imgs *imgs);

// free game
void		free_map(t_map *map);
void		free_copy(char **copy);
char	*ft_itoa(int n);

//map acces
int			is_map_playable(t_map *map, t_pathcheck *check);
char		**copy_map(t_map *map);

//window/inputs
int			launch_game(char **mapc, t_imgs *imgs, t_map *map);
void	handle_cases(t_data *data, int x, int y);
int	handle_key(int keycode, void *param);
int	handle_close(void *mlx);
int	right(int keycode, t_data *data, int x, int y);
int	left(int keycode, t_data *data, int x, int y);
int	up(int keycode, t_data *data, int x, int y);
int	down(int keycode, t_data *data, int x, int y);

#endif