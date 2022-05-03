/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:48:30 by lrosby            #+#    #+#             */
/*   Updated: 2022/04/27 20:48:31 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	img_check(t_game *game)
{
	if (game->img.water == NULL || game->img.lawn == NULL
		||game->img.bed == NULL || game->img.cow == NULL
		|| game->img.milk == NULL || game->img.cat_right == NULL
		|| game->img.cat_up == NULL || game->img.cat_left == NULL
		|| game->img.cat_down == NULL)
		error(9);
}

static void	init_img(t_game *game)
{
	int		img_width;
	int		img_height;

	game->img.water = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/water.xpm", &img_width, &img_height);
	game->img.lawn = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/lawn.xpm", &img_width, &img_height);
	game->img.bed = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/bed.xpm", &img_width, &img_height);
	game->img.cat_up = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/cat_down.xpm", &img_width, &img_height);
	game->img.cat_left = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/cat_left.xpm", &img_width, &img_height);
	game->img.cat_right = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/cat_right.xpm", &img_width, &img_height);
	game->img.cat_down = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/cat_up.xpm", &img_width, &img_height);
	game->img.milk = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/milk.xpm", &img_width, &img_height);
	game->img.cow = mlx_xpm_file_to_image(game->mlx.mlx,
			"./img/cow.xpm", &img_width, &img_height);
	img_check(game);
}

void	initialization(t_game *game)
{
	game->info.height = 0;
	game->info.width = 0;
	game->info.moves = 0;
	game->info.player = 0;
	game->info.collectible = 0;
	game->info.exits = 0;
	game->mlx.mlx = mlx_init();
	init_img(game);
}

int	ft_exit(t_game *game, int it)
{
	if (it == 1)
		printf("Didn't screw up, congratulations\n");
	else if (it == 2)
		printf("I'm sorry but you got caught stealing\n");
	else
		printf("Gave up?\n");
	printf("You made %d move(s).\n", game->info.moves);
	exit (0);
}
