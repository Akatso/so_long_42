/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:07:17 by slepetit          #+#    #+#             */
/*   Updated: 2022/12/29 05:08:44 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_exit(char **map, char **tmp, size_t y, size_t x)
{
	if (tmp[y][x - 1] == 'x' || tmp[y][x + 1] == 'x' || tmp[y - 1][x] == 'x' \
	|| tmp[y + 1][x] == 'x')
		return ;
	else
	{
		ft_free_map(map);
		help_map(4, tmp);
	}
}

void	ft_final_check(char **map, char **tmp)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (tmp[y])
	{
		while (tmp[y][x])
		{
			if (tmp[y][x] == 'C')
			{
				ft_free_map(map);
				help_map(4, tmp);
			}
			else if (tmp[y][x] == 'E')
				ft_check_exit(map, tmp, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

char	**ft_borders(char **tmp, size_t y, size_t x)
{
	if (tmp[y][x - 1] != '1' && tmp[y][x - 1] != 'x' && tmp[y][x - 1] != 'o' \
	&& tmp[y][x - 1] != 'E')
		tmp[y][x - 1] = 'o';
	if (tmp[y][x + 1] != '1' && tmp[y][x + 1] != 'x' && tmp[y][x + 1] != 'o' \
	&& tmp[y][x + 1] != 'E')
		tmp[y][x + 1] = 'o';
	if (tmp[y - 1][x] != '1' && tmp[y - 1][x] != 'x' && tmp[y - 1][x] != 'o' \
	&& tmp[y - 1][x] != 'E')
		tmp[y - 1][x] = 'o';
	if (tmp[y + 1][x] != '1' && tmp[y + 1][x] != 'x' && tmp[y + 1][x] != 'o' \
	&& tmp[y + 1][x] != 'E')
		tmp[y + 1][x] = 'o';
	return (tmp);
}

void	ft_path(char **map, char *av)
{
	char	**tmp;
	size_t	x;
	size_t	y;

	x = 0;
	y = 1;
	tmp = ft_map(av);
	while (tmp[y])
	{
		while (tmp[y][x])
		{
			if (tmp[y][x] == 'P' || tmp[y][x] == 'o')
			{
				tmp[y][x] = 'x';
				tmp = ft_borders(tmp, y, x);
				y = 0;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_final_check(map, tmp);
	ft_free_map(tmp);
}
