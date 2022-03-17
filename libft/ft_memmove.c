/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 09:42:20 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:03:54 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int		check(const char *src, const char *dst)
{
	if (src < dst)
		return (1);
	return (0);
}

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;
	int				size;

	size = len;
	i = 0;
	tmp_dst = (unsigned char*)dst;
	tmp_src = (unsigned char*)src;
	if (!(dst || src))
		return (NULL);
	if (check(src, dst))
		while (size > 0)
		{
			size--;
			*(tmp_dst + size) = *(tmp_src + size);
		}
	else
		while (i < len)
		{
			*(tmp_dst + i) = *(tmp_src + i);
			i++;
		}
	dst = tmp_dst;
	return (dst);
}
