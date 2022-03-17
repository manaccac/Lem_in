/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:16:02 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:03:22 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int				i;
	int				a;
	long int		res;

	res = 0;
	a = 1;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		a = -a;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * a);
}

int		ft_atoi_pimp(const char *nptr, int i)
{
	int	res;
	int a;

	a = 1;
	res = 0;
	if (nptr[i] == '-')
		a = -1;
	while ((nptr[i] >= 48 && nptr[i] <= 57) && nptr[i])
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * a);
}

int			ft_atoi_char(char c)
{
	int		res;

	res = 0;
	res = c - 48;
	return (res);
}
