/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 03:58:00 by slepetit          #+#    #+#             */
/*   Updated: 2022/12/29 05:02:07 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game(t_game *game, char **map)
{
	game->map = map;
	game->mlx = mlx_init();
	ft_init_xpm(game);
	game->pwin = mlx_new_window(game->mlx, \
			game->xm * 32, game->ym * 32, "Cat'n'Milk");
	ft_display(game);
	mlx_key_hook(game->pwin, ft_keycode, game);
	mlx_hook(game->pwin, 17, 0, ft_unloop, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;
	char	**map;

	map = NULL;
	if (ac == 2)
	{
		ft_name(av[1]);
		map = ft_map(av[1]);
		ft_parse(&game, map);
		ft_path(map, av[1]);
	}
	else if (ac < 2 || ac > 2)
		help_file(ac);
	ft_game(&game, map);
	ft_destroy(&game);
	return (0);
}
