/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_pimp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:21:35 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:16 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char			*ft_strcpy_pimp(char *src, int i)
{
	int 	j;
	char 	*dest;

	j = (ft_strlen(src) - i);
	dest = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}