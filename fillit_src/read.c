/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:45:12 by lchappon          #+#    #+#             */
/*   Updated: 2017/12/12 12:40:17 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**fill_tab(char **tab, char *buf)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = 0;
	while (i < g_nb_tetrimino)
	{
		tab[i] = (char *)malloc(sizeof(char) * 20 + 1);
		if (tab[i] == NULL)
			return (NULL);
		while (j < 20)
		{
			tab[i][j] = buf[k];
			j++;
			k++;
		}
		tab[i][20] = '\0';
		j = 0;
		i++;
		k++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**read_stdin(char *argv)
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		**tmp;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	g_nb_tetrimino = get_nb_tetrimino(buf);
	tmp = (char **)malloc(sizeof(char *) * g_nb_tetrimino + 1);
	if (tmp == NULL)
		return (NULL);
	if (check_format(buf) == 0)
		return (NULL);
	tmp = fill_tab(tmp, buf);
	return (tmp);
}

t_etris			*splittab(char **tab)
{
	int			i;
	t_etris		*start;
	t_etris		*ptr;

	i = 1;
	start = NULL;
	ptr = NULL;
	start = newtetri(ft_strsplit(tab[0], '\n'), 0);
	ptr = start;
	while (i < g_nb_tetrimino)
	{
		ptr->next = newtetri(ft_strsplit(tab[i], '\n'), i);
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	return (start);
}
