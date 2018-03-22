/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:59:22 by lchappon          #+#    #+#             */
/*   Updated: 2017/12/12 12:39:35 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**arrange_up(int y_min, char **tab)
{
	int			i;

	i = 0;
	while (i + y_min < 4)
	{
		tab[i] = tab[i + y_min];
		i++;
	}
	while (i < 4 && y_min > 0)
	{
		tab[i] = "....\0";
		i++;
	}
	return (tab);
}

static char		**arrange_left(int x_min, char **tab)
{
	char		tmp;
	int			i;
	int			j;

	tmp = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (tab[i][j + x_min] != '\0')
		{
			tab[i][j] = tab[i][j + x_min];
			j++;
		}
		tmp = x_min;
		while (tmp > 0)
		{
			tab[i][4 - tmp] = '.';
			tmp--;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static int		get_y_min(char **tab)
{
	int			x;
	int			y;
	int			y_min;

	x = 0;
	y = 0;
	y_min = 0;
	while (x < 4)
	{
		while (tab[x][y] != '#' && tab[x][y] != '\0')
			y++;
		if (y == 4)
			y_min++;
		else
			return (y_min);
		y = 0;
		x++;
	}
	return (y_min);
}

static int		get_x_min(char **tab)
{
	int			x;
	int			y;
	int			x_min;

	x = 0;
	y = 0;
	x_min = 4;
	while (x < 4)
	{
		while (tab[x][y] != '#' && tab[x][y] != '\0')
			y++;
		x_min = (y < x_min) ? y : x_min;
		y = 0;
		x++;
	}
	return (x_min);
}

t_etris			*arrange(t_etris *start)
{
	t_etris *tmp;

	tmp = start;
	while (tmp)
	{
		tmp->tetrimino = arrange_left(get_x_min(tmp->tetrimino),
				tmp->tetrimino);
		tmp->tetrimino = arrange_up(get_y_min(tmp->tetrimino), tmp->tetrimino);
		tmp = tmp->next;
	}
	return (start);
}
