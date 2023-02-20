/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:24:24 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/20 16:37:51 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_converter_long(const char *str)
{
	long	sum;
	int		i;

	i = 0;
	sum = 0;
	while ((str[i] > 47 && str[i] < 58) && str[i])
	{
		sum = sum * 10 + (str[i] - 48);
		i++;
	}
	return (sum);
}

long	ft_atoi_long(const char *nptr)
{
	int	i;
	int	meno;

	i = 0;
	meno = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45)
	{
		meno *= -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	return (ft_converter_long(&nptr[i]) * meno);
}
