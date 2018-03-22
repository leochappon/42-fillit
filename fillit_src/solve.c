/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:17:58 by lchappon          #+#    #+#             */
/*   Updated: 2017/12/12 12:40:41 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		test_pos(t_etris *start, char **tab, int square_size)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == '#' && (start->x + j >= square_size
						|| start->y + i >= square_size))
				return (0);
			if (start->tetrimino[i][j] == '#' &&
					ft_isalpha(tab[start->y + i][start->x + j]) == 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static char		**placement(t_etris *start, char **tab)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (start->tetrimino[i][j] == '#')
				tab[start->y + i][start->x + j] = start->letter;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

static char		**delete(t_etris *start, char **tab)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == start->letter)
				tab[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int				place(t_etris *start, int square_size, char **tab)
{
	if (start != NULL)
	{
		while (start->y * start->x < square_size * square_size)
		{
			if ((test_pos(start, tab, square_size)) == 1)
			{
				tab = placement(start, tab);
				if (place(start->next, square_size, tab) == 1)
					return (1);
				tab = delete(start, tab);
			}
			if (start->x < square_size)
				start->x++;
			else
			{
				start->x = 0;
				start->y++;
			}
		}
		start->x = 0;
		start->y = 0;
		return (0);
	}
	return (1);
}

char			**solve(t_etris *start, int square_size, char **tab_solved)
{
	arrange(start);
	tab_solved = create_tab(tab_solved, square_size);
	while (place(start, square_size, tab_solved) == 0)
	{
		square_size++;
		start->x = 0;
		start->y = 0;
		free_tab(tab_solved, square_size);
		tab_solved = create_tab(tab_solved, square_size);
	}
	return (tab_solved);
}
