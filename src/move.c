/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:58:35 by lrosby            #+#    #+#             */
/*   Updated: 2022/05/02 13:58:37 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	step_move(t_game *game)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->img.water, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.win,
		10, 10, 0x000000, game->info.moves_str);
}

static void	step(t_game *game, int x, int y)
{
	step_move(game);
	free(game->info.moves_str);
	game->info.map[game->info.player_y + y][game->info.player_x + x] = 'P';
	if (x == 0 && y == -1)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.cat_up,
			(game->info.player_x + x) * 50, (game->info.player_y + y) * 50);
	if (x == -1 && y == 0)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.cat_left, (game->info.player_x + x) * 50,
			(game->info.player_y + y) * 50);
	if (x == 0 && y == 1)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.cat_down, (game->info.player_x + x) * 50,
			(game->info.player_y + y) * 50);
	if (x == 1 && y == 0)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.cat_right, (game->info.player_x + x) * 50,
			(game->info.player_y + y) * 50);
	game->info.map[game->info.player_y][game->info.player_x] = '0';
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.lawn,
		game->info.player_x * 50, game->info.player_y * 50);
	game->info.player_x += x;
	game->info.player_y += y;
}

static void	enemy_step(t_game *game, int x, int y)
{
	if (game->info.map[game->info.enemy_y + y][game->info.enemy_x + x] == '0')
	{
		game->info.map[game->info.enemy_y + y][game->info.enemy_x + x] = 'X';
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.cow,
			(game->info.enemy_x + x) * 50, (game->info.enemy_y + y) * 50);
		game->info.map[game->info.enemy_y][game->info.enemy_x] = '0';
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.lawn,
			game->info.enemy_x * 50, game->info.enemy_y * 50);
		game->info.enemy_x += x;
		game->info.enemy_y += y;
	}
}

static void	move(t_game *game, int x, int y)
{
	enemy_step(game, -x, -y);
	if (game->info.map[game->info.player_y + y][game->info.player_x + x] != '1')
	{
		if (game->info.map[game->info.player_y + y]
			[game->info.player_x + x] != 'E')
			game->info.moves_str = ft_itoa((game->info.moves++) + 1);
		if (game->info.map[game->info.player_y + y]
			[game->info.player_x + x] == '0')
			step(game, x, y);
		else if (game->info.map[game->info.player_y + y]
			[game->info.player_x + x] == 'C')
		{
			step(game, x, y);
			game->info.collectible--;
		}
		else if (game->info.map[game->info.player_y + y]
			[game->info.player_x + x] == 'E'
			&& game->info.collectible == 0)
			ft_exit(game, 1);
		else if (game->info.map[game->info.player_y + y]
			[game->info.player_x + x] == 'X')
			ft_exit(game, 2);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit(game, 0);
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2
		|| keycode == 126 || keycode == 123 || keycode == 125 || keycode == 124)
	{
		if (keycode == 13 || keycode == 126)
			move(game, 0, -1);
		if (keycode == 0 || keycode == 123)
			move(game, -1, 0);
		if (keycode == 1 || keycode == 125)
			move(game, 0, 1);
		if (keycode == 2 || keycode == 124)
			move(game, 1, 0);
	}
	return (0);
}
