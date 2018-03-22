/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:40:19 by lchappon          #+#    #+#             */
/*   Updated: 2017/12/12 13:48:51 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		puttab(char **tab)
{
	int			i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

static int		get_square_size(void)
{
	int			square_size;

	square_size = ft_sqrt((g_nb_tetrimino) * 4);
	return (square_size);
}

void			free_tab(char **tab, int tab_size)
{
	int			i;

	i = 0;
	while (i < tab_size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_strdel(tab);
}

int				main(int argc, char **argv)
{
	t_etris		*start;
	char		**tab;

	start = NULL;
	tab = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit input_file");
		return (-1);
	}
	if ((tab = read_stdin(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (-1);
	}
	if (check(tab) == 0)
	{
		ft_putendl("error");
		free_tab(tab, g_nb_tetrimino + 1);
		return (-1);
	}
	start = splittab(tab);
	free_tab(tab, g_nb_tetrimino + 1);
	puttab(solve(start, get_square_size(), NULL));
	return (0);
}
