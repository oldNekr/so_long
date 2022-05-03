/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:30:45 by lrosby            #+#    #+#             */
/*   Updated: 2022/03/29 18:30:47 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	width_and_height(char *argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (game->info.height == 0)
			game->info.width = ft_strlen_int(line) - 1;
		game->info.height++;
		free(line);
	}
	close(fd);
	game->mlx.win = mlx_new_window(game->mlx.mlx, ((int)game->info.width * 50),
			((int)game->info.height * 50), "so_cringe");
}

static void	img_upload(t_game *game, int y, int x)
{
	if (game->info.map[y][x] != '1')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.lawn, x * 50, y * 50);
	if (game->info.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.water, x * 50, y * 50);
	if (game->info.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.cat_down, x * 50, y * 50);
	if (game->info.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.milk, x * 50, y * 50);
	if (game->info.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.bed, x * 50, y * 50);
	if (game->info.map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
			game->img.cow, x * 50, y * 50);
}

static void	map_upload(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->info.map[++y])
	{
		x = -1;
		while (game->info.map[y][++x])
			img_upload(game, y, x);
	}
}

void	map(char *argv, t_game *game)
{
	int	fd;
	int	it;

	it = -1;
	file_check(argv);
	width_and_height(argv, game);
	game->info.map = malloc(sizeof(char *) * game->info.height);
	if (!game->info.map)
		error(6);
	fd = open(argv, O_RDONLY);
	while (++it < game->info.height)
		game->info.map[it] = get_next_line(fd);
	close(fd);
	game->info.map[it] = NULL;
	map_check(game);
	map_upload(game);
}
