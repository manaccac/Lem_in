/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:11:54 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:03:43 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int					ft_intlenbase(long int n, char *base)
{
	int				a;
	int				len;

	a = ft_strlen(base);
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / a;
		len++;
	}
	return (len);
}

char				*ft_itoa_base(long n, char *base)
{
	long int		nl;
	long int		len;
	char			*res;
	int				a;

	a = ft_strlen(base);
	len = ft_intlenbase(n, base);
	nl = n;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nl == 0)
		res[0] = 0 + 48;
	if (nl < 0)
	{
		res[0] = '-';
		nl = nl * -1;
	}
	while (nl > 0)
	{
		res[len--] = base[(nl % a)];
		nl = nl / a;
	}
	return (res);
}
