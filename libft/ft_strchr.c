/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:37:40 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:14 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int len;

	len = ft_strlen(s);
	i = 0;
	if (!(s))
		return (0);
	if (c == '\0')
		return ((char *)s + len);
	while (s[i] && s[i] != c)
		i++;
	if (i == len)
		return (0);
	else
		return ((char *)s + i);
}
