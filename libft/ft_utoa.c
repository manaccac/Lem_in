/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:11:54 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:45 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int			ft_intlenunsigned(unsigned long n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char			*ft_intzero(unsigned int n)
{
	long int	nl;
	char		*res;

	nl = n;
	if (!(res = (char*)malloc(sizeof(char) * (2))))
		return (NULL);
	if (nl == 0)
	{
		res[0] = 0 + 48;
		res[1] = '\0';
		return (res);
	}
	return (res);
}

char				*ft_utoa(unsigned long n)
{
	unsigned long		nl;
	long int			len;
	char				*res;

	len = ft_intlenunsigned(n);
	nl = n;
	if (nl == 0)
	{
		res = ft_intzero(n);
		return (res);
	}
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	while (nl > 0)
	{
		res[len--] = (nl % 10) + 48;
		nl = nl / 10;
	}
	return (res);
}
