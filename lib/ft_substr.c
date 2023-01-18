/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slepetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:50:43 by slepetit          #+#    #+#             */
/*   Updated: 2022/04/11 18:18:55 by slepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)s;
	if (start > ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		if (str == NULL)
			return (NULL);
		return (str);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[start] && len--)
		str[i++] = s[start++];
	return (str);
}
