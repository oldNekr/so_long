/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:00:00 by lrosby            #+#    #+#             */
/*   Updated: 2022/04/27 20:00:01 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	file_check(char *argv)
{
	int	fd;
	int	it;

	it = 0;
	while (argv[it] != '\0')
		it++;
	fd = open(argv, O_DIRECTORY);
	if (argv[it - 1] != 'r' || argv[it - 2] != 'e'
		|| argv[it - 3] != 'b' || argv[it - 4] != '.' || fd != -1)
		error(0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error(7);
}

static void	symbols_check(t_game *game, int x, int y)
{
	if (game->info.map[y][x] == 'C')
		game->info.collectible++;
	if (game->info.map[y][x] == 'E')
		game->info.exits++;
	if (game->info.map[y][x] == '0')
		game->info.space++;
	if (game->info.map[y][x] == 'X')
	{
		game->info.enemy_x = x;
		game->info.enemy_y = y;
	}
}

static void	line_check(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->info.map[++y])
	{
		x = -1;
		while (game->info.map[y][++x])
		{
			if (game->info.map[y][x] == '\n')
				break ;
			if (game->info.map[y][x] == 'P')
			{
				game->info.player_x = x;
				game->info.player_y = y;
				game->info.player++;
			}
			symbols_check(game, x, y);
		}
		if (x != game->info.width)
			error(4);
	}
}

static void	wall_check(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = -1;
	while (game->info.map[y][++x] != '\n')
		if (game->info.map[y][x] != '1')
			error(8);
	x--;
	while (y < game->info.height)
		if (game->info.map[y++][x] != '1')
			error(8);
	y--;
	while (x--)
		if (game->info.map[y][x] != '1')
			error(8);
	x++;
	while (y--)
		if (game->info.map[y][x] != '1')
			error(8);
}

void	map_check(t_game *game)
{
	line_check(game);
	wall_check(game);
	if (game->info.player != 1)
		error(1);
	else if (game->info.collectible < 1)
		error(2);
	else if (game->info.exits < 1)
		error(3);
	else if (game->info.height < 3 || game->info.width < 6
		|| game->info.space < 1)
		error(4);
}
