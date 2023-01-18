/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:00:08 by slepetit          #+#    #+#             */
/*   Updated: 2023/01/07 21:09:38 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_xpm(t_game *game)
{
	int	size;

	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/wall.xpm", &size, &size);
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/floor.xpm", &size, &size);
	game->sprites.player = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/player.xpm", &size, &size);
	game->sprites.collectible = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/item.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, \
			"./sprites/exit.xpm", &size, &size);
}

void	ft_init_struct(t_game *game)
{
	game->map = NULL;
	game->xm = 0;
	game->ym = 0;
	game->step = 0;
	game->bag = 0;
	game->parse.p = 0;
	game->parse.e = 0;
	game->parse.c = 0;
	game->parse.f = 0;
}

int	ft_keycode(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_unloop(game);
	else if (keycode == W)
		ft_up(game);
	else if (keycode == A)
		ft_left(game);
	else if (keycode == S)
		ft_down(game);
	else if (keycode == D)
		ft_right(game);
	return (0);
}

int	ft_unloop(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}
