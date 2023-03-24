/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:41:26 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/24 15:44:36 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*find_big(t_stacks *stack)
{
	t_stacks	*max;

	max = stack;
	while (stack)
	{
		if (max->i < stack->i)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stacks	*find_little(t_stacks *stack)
{
	t_stacks	*min;

	min = stack;
	while (stack)
	{
		if (min->i > stack->i)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	calc_size(t_stacks *stack)
{
	int	size;

	if (stack == NULL)
		return (0);
	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
