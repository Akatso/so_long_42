/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:56:40 by slepetit          #+#    #+#             */
/*   Updated: 2022/12/28 05:57:31 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_sprites(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprites.player, x * 32, y * 32);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprites.exit, x * 32, y * 32);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprites.collectible, x * 32, y * 32);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprites.wall, x * 32, y * 32);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->pwin, \
				game->sprites.floor, x * 32, y * 32);
}

void	ft_display(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			ft_sprites(game, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
