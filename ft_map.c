/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 06:02:16 by slepetit          #+#    #+#             */
/*   Updated: 2023/01/07 21:08:56 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_assets(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				game->parse.p += 1;
			else if (map[i][j] == 'C')
				game->parse.c += 1;
			else if (map[i][j] == 'E')
				game->parse.e += 1;
			else if (map[i][j] == '0')
				game->parse.f += 1;
			else if (map[i][j] != '1')
				help_map(3, map);
		}
		j = -1;
	}
	if (game->parse.p != 1 || game->parse.e != 1 || game->parse.c < 1)
		help_map(3, map);
}

void	ft_surround_wall(t_game *game, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((i == 0 || i == game->ym - 1) && map[i][j] != '1')
				help_map(2, map);
			if ((j == 0 || j == game->xm - 1) && map[i][j] != '1')
				help_map(2, map);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_parse(t_game *game, char **map)
{
	size_t	i;

	i = 1;
	ft_init_struct(game);
	game->xm = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != game->xm)
			help_map(1, map);
		i++;
	}
	game->ym = i;
	ft_surround_wall(game, map);
	ft_assets(game, map);
}

char	**ft_map(char *av)
{
	char	**map;
	char	*s;
	char	*tmp;
	int		fd;

	fd = open(av, O_RDONLY);
	s = malloc(sizeof(char));
	if (!s)
		return (NULL);
	*s = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		s = ft_strjoin(s, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	if (!*s)
		help_gnl(s, tmp, 1);
	map = ft_split(s, '\n');
	if (!map)
		help_gnl(s, tmp, 2);
	free(s);
	close (fd);
	return (map);
}

void	ft_name(char *av)
{
	size_t	i;

	i = ft_strlen(av);
	if (i < 4 || (av[i -1] != 'r' && av[i -2] != 'e' && av[i -1] != 'b' \
				&& av[i -1] != '.'))
		help_file(2);
	if (ft_strlen(av) == 4)
		help_file(4);
}
