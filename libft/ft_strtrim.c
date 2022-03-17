/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:37:57 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:36 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int		ft_strtrimstar(char *s1, char *set)
{
	int lset;
	int i;
	int j;

	lset = ft_strlen(set);
	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s1[i] != set[j])
		{
			if (j == lset)
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}

static int		ft_strtrimend(char *s1, char *set)
{
	int lset;
	int i;
	int j;
	int count;

	lset = ft_strlen(set);
	i = ft_strlen(s1);
	i--;
	j = 0;
	count = 0;
	while (i != 0)
	{
		while (s1[i] != set[j])
		{
			if (j == lset)
				return (count);
			j++;
		}
		j = 0;
		i--;
		count++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		lenstart;
	int		lenend;
	size_t	lentrim;
	size_t	i;

	if (s1)
	{
		if (set[0] == '\0' || s1[0] == '\0')
			return (ft_strdup(s1));
		lenstart = ft_strtrimstar((char *)s1, (char *)set);
		lenend = ft_strtrimend((char *)s1, (char *)set);
		lentrim = ft_strlen((char *)s1);
		lentrim = lentrim - (lenstart + lenend);
		i = 0;
		if (!(trim = (char *)malloc(sizeof(char) * (lentrim + 1))))
			return (0);
		while (i < lentrim)
		{
			trim[i++] = s1[lenstart++];
		}
		trim[i] = '\0';
		return (trim);
	}
	return (0);
}
