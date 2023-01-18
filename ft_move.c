/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:05:32 by slepetit          #+#    #+#             */
/*   Updated: 2023/01/07 22:04:09 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pos(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->step += 1;
		ft_printf("Step : %d\n", game->step);
		return (1);
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->bag += 1;
		game->step += 1;
		ft_printf("Step : %d\n", game->step);
		return (1);
	}
	if (game->map[y][x] == 'E' && (game->bag == game->parse.c))
	{
		game->map[y][x] = 'P';
		game->step += 1;
		ft_printf("Step : %d\n", game->step);
		ft_unloop(game);
		return (1);
	}
	return (-1);
}

void	ft_up(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				if (ft_pos(game, (y - 1), x) == -1)
					game->map[y][x] = 'P';
				ft_display(game);
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_display(game);
}

void	ft_down(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				if (ft_pos(game, (y + 1), x) == -1)
					game->map[y][x] = 'P';
				ft_display(game);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_display(game);
}

void	ft_left(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				if (ft_pos(game, y, (x - 1)) == -1)
					game->map[y][x] = 'P';
				ft_display(game);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_display(game);
}

void	ft_right(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				if (ft_pos(game, y, (x + 1)) == -1)
					game->map[y][x] = 'P';
				ft_display(game);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_display(game);
}
