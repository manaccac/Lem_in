/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manaccac <manaccac@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:14:31 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/01 14:04:49 by manaccac         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				strbn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int				checkstr(char **str, char **line)
{
	while (*str != NULL)
	{
		if (strbn(*str) == 1)
		{
			if ((*line = ft_strdupbn(*str)) == NULL)
				return (-1);
			if ((*str = ft_strchrcut(*str, '\n')) == NULL)
				return (-1);
			return (1);
		}
		else if (strbn(*str) == 0)
		{
			*line = *str;
			*str = NULL;
			return (0);
		}
	}
	if (*str == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (0);
}

static int				nlishere(char **str, char **line)
{
	if (strbn(*str) == 1)
	{
		if ((*line = ft_strdupbn(*str)) == NULL)
			return (-1);
		*str = ft_strchrcut(*str, '\n');
		return (1);
	}
	return (0);
}

int						get_next_line(int fd, char **line)
{
	static char		*str;
	int				ret;
	int				ret1;
	char			buf[2048];

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, 2048)) > 0)
	{
		if (str == NULL)
			if ((str = ft_strdup("")) == NULL)
				return (-1);
		buf[ret] = '\0';
		if ((str = ft_strjoin(str, buf)) == NULL)
			return (-1);
		if ((ret1 = nlishere(&str, line)) != 0)
			return (ret1);
	}
	if (ret == -1)
		return (-1);
	if ((ret1 = checkstr(&str, line)) == 0)
		return (0);
	else
		return (1);
}
