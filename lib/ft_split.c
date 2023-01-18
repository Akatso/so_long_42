/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:46:51 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/15 19:36:44 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_strs(char const *s, char c)
{
	size_t	i;
	size_t	strs;

	i = 0;
	strs = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || !s[i + 1])
			strs++;
		i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_strs(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			tab[j++] = ft_substr(s, i, ft_len(((char *)&s[i]), c));
			i += ft_len(((char *)&s[i]), c);
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
