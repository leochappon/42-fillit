/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:25:37 by lchappon          #+#    #+#             */
/*   Updated: 2017/12/12 12:39:49 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_char(char *s)
{
	int			i;
	int			hash;
	int			point;
	int			endline;

	i = 0;
	hash = 0;
	point = 0;
	endline = 0;
	while (s[i])
	{
		if (s[i] == '#')
			hash++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			endline++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (hash != 4 || point != 12 || endline != 4)
		return (0);
	return (1);
}

static int		check_line(char *s)
{
	int			x;
	int			y;
	int			endline;

	x = 0;
	y = 0;
	endline = 4;
	while (s[x])
	{
		if (s[x] == '.' || s[x] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[x] == '\n' && x == endline)
		{
			y = 0;
			endline += 5;
		}
		x++;
	}
	return (1);
}

static int		check_shape(char *s)
{
	int			height;
	int			width;

	height = get_height(s);
	width = get_width(s);
	if (check_void(s) == 0 || width == 0 || height == 0)
		return (0);
	if (height == 2 && width == 2)
		return (1);
	else if ((height == 2 && width == 3) || (height == 3 && width == 2))
		return (1);
	else if ((height == 1 && width == 4) || (height == 4 && width == 1))
		return (1);
	return (0);
}

int				check(char **tab)
{
	int			i;

	i = 0;
	if (tab[0] == NULL)
		return (0);
	while (i < g_nb_tetrimino)
	{
		if (check_char(tab[i]) != 1)
			return (0);
		if (check_line(tab[i]) != 1)
			return (0);
		if (check_shape(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int				check_format(char *s)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (s[x])
	{
		if (s[x] == '\n')
			y++;
		if (y == 4)
		{
			if (s[x + 1] != '\n' && s[x + 1] != '\0')
				return (0);
			if (s[x + 1] == '\n')
				x++;
			y = 0;
		}
		x++;
	}
	return (1);
}
