/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:35:53 by lchappon          #+#    #+#             */
/*   Updated: 2017/12/12 15:43:45 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "../libft/libft.h"

# define BUFF_SIZE 546

int						g_nb_tetrimino;

typedef struct			s_etris
{
	char				**tetrimino;
	char				letter;
	int					x;
	int					y;
	struct s_etris		*next;
}						t_etris;

t_etris					*arrange(t_etris *start);
int						check(char **tab);
int						get_nb_tetrimino(char *s);
char					**read_stdin(char *argv);
t_etris					*splittab(char **tab);
t_etris					*newtetri(char **tetrimino, int num);
char					**solve(t_etris *start, int square_size,
						char **tab_solved);
char					**create_tab(char **tab, int square_size);
void					free_tab(char **tab, int tab_size);
int						check_square(char *s);
int						check_bar(char *s);
int						get_height(char *s);
int						get_width(char *s);
int						check_void(char *s);
int						check_format(char *s);

#endif
