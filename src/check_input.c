/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:58:15 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/27 19:35:09 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	check_duplicates(char **av, int choice)
{
	int	i;
	int	j;

	i = 1;
	if (!choice)
		i = 0;
	while (av[i])
	{
		j = 1;
		if (!choice)
			j = 0;
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

char	**split_one_arg(char **av)
{
	char	**args;

	args = ft_split(av[1], ' ');
	return (args);
}

int	check_input(char **av, int ac)
{
	int	flag;
	int	i;
	int	zeros;

	zeros = 0;
	flag = 1;
	if (ac == 2)
	{
		av = split_one_arg(av);
		flag = 0;
	}
	i = 0;
	if (!flag)
		i = -1;
	while (av[++i])
	{
		if (!check_numbers(av[i]))
			return (flag_return(0, av, flag));
		zeros += count_zero(av[i]);
	}
	if (limits(av))
		return (flag_return(0, av, flag));
	if (check_duplicates(av, flag))
		return (flag_return(0, av, flag));
	return (flag_return(1, av, flag));
}
