/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:58:05 by slepetit          #+#    #+#             */
/*   Updated: 2022/12/29 04:35:02 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_count(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_free_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_count(map);
	while (i < j)
		free(map[i++]);
	free(map);
}

void	ft_free(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->ym)
		free(game->map[i++]);
	free(game->map);
	exit(EXIT_SUCCESS);
}

int	ft_destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites.player);
	mlx_destroy_image(game->mlx, game->sprites.collectible);
	mlx_destroy_image(game->mlx, game->sprites.wall);
	mlx_destroy_image(game->mlx, game->sprites.floor);
	mlx_destroy_image(game->mlx, game->sprites.exit);
	mlx_destroy_window(game->mlx, game->pwin);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free(game);
	return (0);
}
