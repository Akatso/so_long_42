/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 03:54:53 by slepetit          #+#    #+#             */
/*   Updated: 2023/01/07 21:09:19 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "lib/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define A		97
# define W		119
# define S		115
# define D	    100
# define ESC    65307

typedef struct s_parse
{
	int	p;
	int	e;
	int	c;
	int	f;
}	t_parse;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}	t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*pwin;
	char		**map;
	size_t		xm;
	size_t		ym;
	size_t		step;
	int			bag;
	t_parse		parse;
	t_sprites	sprites;
}	t_game;

//HELP && SPLIT FAIL
void	help_file(int ac);
void	help_gnl(char *s, char *tmp, int i);
void	help_map(int i, char **map);

//PARSE & PATHFINDINDER
void	ft_name(char *av);
char	**ft_map(char *av);
void	ft_parse(t_game *game, char **map);
void	ft_surround_wall(t_game *game, char **map);
void	ft_assets(t_game *game, char **map);
void	ft_path(char **map, char *av);
char	**ft_borders(char **tmp, size_t y, size_t x);
void	ft_final_check(char **map, char **tmp);
void	ft_check_exit(char **map, char **tmp, size_t y, size_t x);

//INITS & KEYCODE MOVES
void	ft_init_xpm(t_game *game);
void	ft_init_struct(t_game *game);
int		ft_keycode(int keycode, t_game *game);
int		ft_unloop(t_game *game);

//GAME
void	ft_game(t_game *game, char **map);
void	ft_display(t_game *game);
void	ft_sprites(t_game *game, int x, int y);
void	ft_up(t_game *game);
void	ft_down(t_game *game);
void	ft_left(t_game *game);
void	ft_right(t_game *game);
int		ft_pos(t_game *game, int y, int x);

//FREE & DESTROY
void	ft_free(t_game *game);
int		ft_destroy(t_game *game);
size_t	ft_count(char **map);
void	ft_free_map(char **map);

#endif
