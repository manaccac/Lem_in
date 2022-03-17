/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:22:22 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:35 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int			len;

	len = ft_strlen(s);
	if (s[0] == '\0')
		return (0);
	if (c == '\0')
		return ((char *)s + len);
	len--;
	while (len > 0 && s[len] != c)
		len--;
	if (len == 0 && s[len] != c)
		return (0);
	return ((char *)s + len);
}
