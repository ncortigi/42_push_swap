/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:58:47 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/27 19:34:28 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_cmp(char *s1, char *s2)
{
	if (ft_atoi(s1) == ft_atoi(s2))
		return (1);
	return (0);
}

int	limits(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi_long(str[i]) > 2147483647 || \
			ft_atoi_long(str[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int	flag_return(int to_return, char **to_free, int flag)
{
	int	i;

	i = 0;
	if (!flag)
	{
		while (to_free[i])
		{
			free(to_free[i]);
			i++;
		}
		free(to_free);
	}
	if (flag == 0 && to_return == 1)
		return (2);
	return (to_return);
}

void	put_index(t_stacks *stack, int size)
{
	int			nb;
	t_stacks	*app;
	t_stacks	*high;

	while (--size > 0)
	{
		nb = -2147483648;
		app = stack;
		high = NULL;
		while (app)
		{
			if (app->value == -2147483648 && app->i == 0)
				app->i = 1;
			if (app->value > nb && app->i == 0)
			{
				nb = app->value;
				high = app;
			}
			app = app->next;
		}
		if (high)
			high->i = size;
	}
}
