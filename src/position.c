/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:09:09 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/07 17:46:07 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stacks *stack, t_stacks *to_find)
{
	int i;

	i = 0;
	while (stack->i != to_find->i)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	put_pos(t_stacks *stack_a, t_stacks *stack_b)
{
	int i;
	int	size;

	i = 0;
	size = calc_size(stack_a);
	while (i < size)
	{
		stack_a->pos = i;
		stack_a = stack_a->next;
		i++;
	}
	if (stack_b)
		put_positions(stack_b, NULL);
}

static void	targ_pos_higher_i(t_stacks *stack_a, t_stacks *stack_b, int min_i)
{
	while (stack_a)
	{
		if (stack_a->i < min_i)
		{
			min_i = stack_a->i;
			stack_b->target_pos = stack_a->pos;
		}
		stack_a = stack_a->next;
	}
}

static int	target_pos(t_stacks *stack_a, t_stacks *stack_b)
{
	int diff;

	diff = stack_a->i - stack_b->i;
	stack_b->target_pos = stack_a->pos;
	return (diff);
}

void	put_target_pos(t_stacks *stack_a, t_stacks *stack_b)
{
	t_stacks		*first_in_a;
	int				diff;
	int				max_i;

	first_in_a = stack_a;
	max_i = 0;
	while (stack_b)
	{
		stack_a = first_in_a;
		diff = 2147483647;
		while (stack_a)
		{
			if (stack_a->i > max_i)
				max_i = stack_a->i;
			if (diff > stack_a->i - stack_b->i && stack_a->i > stack_b->i)
				diff = target_pos(stack_a, stack_b);
			stack_a = stack_a->next;
		}
		if (stack_b->i > max_i)
			targ_pos_higher_i(stack_a, stack_b, max_i);
		stack_b = stack_b->next;
	}
}