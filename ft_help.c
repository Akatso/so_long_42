/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:58:21 by slepetit          #+#    #+#             */
/*   Updated: 2023/01/01 15:21:19 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	help_file(int ac)
{
	ft_printf("Error\n");
	if (ac < 2)
		ft_printf("There must be the map file.\n");
	else if (ac > 2)
		ft_printf("There should only be the map file.\n");
	else if (ac == 2)
		ft_printf("The map file must have the extension .ber.\n");
	exit(EXIT_FAILURE);
}

void	help_map(int i, char **map)
{
	ft_printf("Error\n");
	if (i == 1)
		ft_printf("Must be rectangular.\n");
	if (i == 2)
		ft_printf("The map must be surrounded by walls(1).\n");
	if (i == 3)
	{
		ft_printf("Should only contain 1 player(P), 1 exit(E), ");
		ft_printf("at least 1 collectible(C).\n");
	}
	if (i == 4)
		ft_printf("The path is invalid, impossible to win the game.\n");
	ft_free_map(map);
	exit(EXIT_FAILURE);
}

void	help_gnl(char *s, char *tmp, int i)
{
	if (i == 1)
		ft_printf("Error\nThe file is empty.\n");
	if (i == 2)
		ft_printf("Error\nSplit in function 'ft_map' failed.\n");
	free(s);
	free(tmp);
	exit(EXIT_FAILURE);
}
