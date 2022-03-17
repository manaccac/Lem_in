/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:30:57 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:43 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int					ft_unsignedlenbase(unsigned long n, char *base)
{
	int	a;
	int	len;

	a = ft_strlen(base);
	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / a;
		len++;
	}
	return (len);
}

char				*ft_utoa_base(unsigned long n, char *base)
{
	unsigned long		nl;
	unsigned long		len;
	char				*res;
	int					a;

	a = ft_strlen(base);
	len = ft_unsignedlenbase(n, base);
	nl = n;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nl == 0)
		res[0] = 0 + 48;
	while (nl > 0)
	{
		res[len--] = base[(nl % a)];
		nl = nl / a;
	}
	return (res);
}
