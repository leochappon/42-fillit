/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:56:10 by lchappon          #+#    #+#             */
/*   Updated: 2017/12/12 12:41:02 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_nb_tetrimino(char *s)
{
	int			i;
	int			nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}

t_etris			*newtetri(char **tetrimino, int num)
{
	t_etris		*new;

	new = NULL;
	new = (t_etris *)malloc(sizeof(t_etris));
	if (new == NULL)
		return (NULL);
	new->tetrimino = tetrimino;
	new->letter = 'A' + num;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

char			**create_tab(char **tab, int square_size)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	tab = ft_memalloc(sizeof(char *) * square_size + 1);
	while (i < square_size)
	{
		tab[i] = ft_memalloc(sizeof(char) * square_size + 1);
		i++;
	}
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
		{
			tab[j][i] = '.';
			i++;
		}
		tab[j][i] = '\0';
		i = 0;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
