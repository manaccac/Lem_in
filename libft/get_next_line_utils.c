/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:14:43 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:46 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char			*ft_strjoinfree(char *s1, char *s2)
{
	char		*str;
	int			i;
	int			j;
	int			len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	free(s1);
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}

char			*ft_strdupbn(char *str)
{
	int		j;
	int		i;
	char	*dup;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			if (!(dup = (char*)malloc(sizeof(char) * i + 1)))
				return (NULL);
			j = 0;
			while (j < i)
			{
				dup[j] = str[j];
				j++;
			}
			dup[j] = '\0';
			return (dup);
		}
		i++;
	}
	return (ft_strdup(str));
}

char			*ft_strchrcut(char *str, char c)
{
	int			i;
	char		*res;

	res = ft_strdup("");
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			res = ft_strjoin(res, str + (i + 1));
			free(str);
			return (res);
		}
		i++;
	}
	return (0);
}
