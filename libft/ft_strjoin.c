/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:12:31 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:22 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int		ft_lent(char *s1, char *s2)
{
	int len;

	len = (ft_strlen(s1)) + (ft_strlen(s2));
	return (len);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	int			i;
	int			j;
	int			len;

	if (s1 && s2)
	{
		len = ft_lent(((char *)s1), ((char *)s2));
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		i = 0;
		j = 0;
		while (s1[i])
		{
			str[j++] = s1[i++];
		}
		i = 0;
		while (s2[i])
		{
			str[j++] = s2[i++];
		}
		str[j] = '\0';
		return (str);
	}
	return (0);
}
