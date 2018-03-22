/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchappon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:22:26 by lchappon          #+#    #+#             */
/*   Updated: 2017/11/16 12:41:33 by lchappon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		is_neg;

	i = 0;
	res = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\v' || str[i] == '\f' || str[i] == ' '
				|| ((str[i] == '+' || str[i] == '-')
					&& (str[i + 1] >= '0' && str[i + 1] <= '9'))))
		i++;
	is_neg = (str[i - 1] == '-' ? -1 : 1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res += str[i] - 48;
		if (str[i + 1] && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			res *= 10;
		i++;
	}
	return (res * is_neg);
}
