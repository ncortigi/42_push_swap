/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:58:47 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/14 17:05:14 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*take_last(t_stacks *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

int number_cmp(char *s1, char *s2)
{
	if (ft_atoi(s1) == ft_atoi(s2))
		return (1);
	return (0);
}

int limits(char *str)
{
	if (ft_atoi_long(str) > 2147483647 || ft_atoi_long(str) < -2147483648)
		return (1);
	return (0);
}

void	put_index(t_stacks *stack, int size)
{
	int		nb;
	t_stacks	*app;
	t_stacks	*high;

	while (size > 0)
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
		size--;
	}
}
