/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:58:15 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/20 16:44:44 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_numbers(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '+' || av[i] == '-') && av[i + 1] != '\0')
		i++;
	while (av[i] && av[i] >= '0' && av[i] <= '9')
		i++;
	if (av[i] != '\0' && (av[i] < '0' || av[i] > '9'))
		return (0);
	return (1);
}

static int	count_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

static int	check_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && number_cmp(av[i], av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_input(char **av)
{
	int i;
	int zeros;

	zeros = 0;
	i = 1;
	while (av[i])
	{
		if (!check_numbers(av[i]))
			return (0);
		zeros += count_zero(av[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	i = 0;
	while (av[i])
	{
		if (limits(av[i]))
			return (0);
		i++;	
	}
	if (check_duplicates(av))
		return (0);
	return (1);
}
