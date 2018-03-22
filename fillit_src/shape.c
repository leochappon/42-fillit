/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:23 by lchappon          #+#    #+#             */
/*   Updated: 2017/12/12 12:40:30 by mjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_width(char *s)
{
	int		i;
	int		width;
	int		line_void;

	i = 0;
	width = 0;
	line_void = 0;
	while (i < 4)
	{
		if (s[i] == '#' || s[i + 5] == '#' || s[i + 10] == '#'
				|| s[i + 15] == '#')
		{
			width++;
			if (line_void > 0)
				return (0);
		}
		else if (width > 0)
			line_void++;
		i++;
	}
	return (width);
}

int			get_height(char *s)
{
	int		i;
	int		height;
	int		line_void;

	i = 0;
	height = 0;
	line_void = 0;
	while (i < 19)
	{
		if (s[i] == '#' || s[i + 1] == '#' || s[i + 2] == '#'
				|| s[i + 3] == '#')
		{
			height++;
			if (line_void > 0)
				return (0);
		}
		else if (height > 0)
			line_void++;
		i = i + 5;
	}
	return (height);
}

int			check_void(char *s)
{
	int		i;
	int		valid;

	i = 0;
	valid = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#' || s[i - 1] == '#' || s[i + 5] == '#'
					|| s[i - 5] == '#')
				valid++;
			if (valid == 4)
				return (1);
		}
		i++;
	}
	return (0);
}
