/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:40:36 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/24 17:26:49 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	control_lis(t_stacks *first, int *lis)
{
	int	i;

	i = 0;
	while (first->next)
	{
		if (first->i != lis[i])
			return (0);
		first = first->next;
		i++;
	}
	if (first->i != lis[i])
		return (0);
	return (1);
}

void	second_push_b(t_stacks **stack_a, t_stacks **stack_b, \
	int *lis, int lis_lenght)
{
	int			i;

	i = 0;
	while (!control_lis(*stack_a, lis))
	{
		if ((*stack_a)->i == lis[i])
		{
			rotate(stack_a, 'a');
			if (i < lis_lenght)
				i++;
		}
		else
			push(stack_a, stack_b, 'b');
	}
}

void	prepare_push_a(t_stacks **stack_a, t_stacks **stack_b)
{
	int	*move_a;
	int	*move_b;
	int	size_a;
	int	size_b;

	move_b = calc_cost_to_top(*stack_b);
	size_b = calc_size(*stack_b);
	size_a = calc_size(*stack_a);
	move_a = calc_cost_to_a(*stack_a, *stack_b, size_b, size_a);
	clever_push_a(stack_a, stack_b, move_b, move_a);
}
