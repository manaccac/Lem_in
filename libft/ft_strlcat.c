/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:04:41 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:24 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst1;
	const char	*src1;
	size_t		i;
	size_t		len;

	dst1 = dst;
	src1 = src;
	i = size;
	while (i-- != 0 && *dst1 != '\0')
		dst1++;
	len = dst1 - dst;
	i = size - len;
	if (i == 0)
		return (len + ft_strlen(src1));
	while (*src1 != '\0')
	{
		if (i != 1)
		{
			*dst1++ = *src1;
			i--;
		}
		src1++;
	}
	*dst1 = '\0';
	return (len + (src1 - src));
}
