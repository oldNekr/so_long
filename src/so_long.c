/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 09:39:28 by lrosby            #+#    #+#             */
/*   Updated: 2022/03/18 09:39:29 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error(int flag)
{
	if (flag == 0)
		printf("This file is not a map, it must end with .ber\n");
	if (flag == 1)
		printf("Map must contain 1 starting position\n");
	if (flag == 2)
		printf("The map must contain at least 1 collectible\n");
	if (flag == 3)
		printf("The map must contain at least 1 exit\n");
	if (flag == 4)
		printf("An error was made in the compilation of the map\n");
	if (flag == 5)
		printf("You didn't write the name of the map\n");
	if (flag == 6)
		printf("Memory not allocated\n");
	if (flag == 7)
		printf("Unable to read file\n");
	if (flag == 8)
		printf("The map is not surrounded by walls\n");
	if (flag == 9)
		printf("Wrong image path or they don't exist\n");
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error(5);
	initialization(&game);
	map(argv[1], &game);
	mlx_hook(game.mlx.win, 17, 1L << 0, ft_exit, &game);
	mlx_hook(game.mlx.win, 2, 0, key_hook, &game);
	mlx_key_hook(game.mlx.win, key_hook, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
