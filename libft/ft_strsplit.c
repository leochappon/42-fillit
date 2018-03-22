/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 13:33:10 by lchappon          #+#    #+#             */
/*   Updated: 2017/11/20 17:15:41 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = ft_prtcount(s, c);
	tab = (char **)malloc(sizeof(*tab) * count + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (count--)
	{
		while (*s && *s == c)
			s++;
		tab[i] = ft_strsub(s, 0, ft_prtlength(s, c));
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_prtlength(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
