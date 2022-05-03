/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:33:51 by lrosby            #+#    #+#             */
/*   Updated: 2022/03/26 20:33:58 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../get_next_line/inc/get_next_line.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct s_info
{
	char	**map;
	int		player;
	int		collectible;
	int		exits;
	int		space;

	int		player_y;
	int		player_x;
	int		enemy_y;
	int		enemy_x;
	int		height;
	int		width;
	int		moves;
	char	*moves_str;
}				t_info;

typedef struct s_image
{
	void	*water;
	void	*lawn;
	void	*cow;
	void	*bed;
	void	*cat_down;
	void	*cat_left;
	void	*cat_right;
	void	*cat_up;
	void	*milk;
}				t_image;

typedef struct s_game
{
	t_mlx	mlx;
	t_info	info;
	t_image	img;
}				t_game;

void	error(int flag);
void	initialization(t_game *game);
void	map(char *argv, t_game *game);
void	file_check(char *argv);
void	map_check(t_game *game);
int		key_hook(int keycode, t_game *game);
int		ft_exit(t_game *game, int it);

#endif
