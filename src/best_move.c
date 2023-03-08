/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:13:40 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/08 15:10:18 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	negative_a_and_b(t_stacks **stack_a, t_stacks **stack_b, int *cost_a, int *cost_b)
{
	rrr(*stack_a, *stack_b);
	(*cost_a)++;
	(*cost_b)++;
}

static void	positive_a_and_b(t_stacks **stack_a, t_stacks **stack_b, int *cost_a, int *cost_b)
{
	rr(stack_a, stack_b);
	(*cost_a)--;
	(*cost_b)--;
}

static void	ft_cost_a(t_stacks **stack_a, int *cost_a)
{
	if ((*cost_a) < 0)
	{
		r_rotate(stack_a, 'a');
		(*cost_a)++;
	}
	else if ((*cost_a) > 0)
	{
		rotate(stack_a, 'a');
		(*cost_a)--;
	}
}

void	choose_best_move(t_stacks **stack_a, t_stacks **stack_b, int cost_a, int cost_b)
{
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_a < 0 && cost_b < 0)
			negative_a_and_b(stack_a, stack_b, &cost_a, &cost_b);
		else if (cost_a > 0 && cost_b > 0)
			positive_a_and_b(stack_a, stack_b, &cost_a, &cost_b);
		else if (cost_a != 0)
			ft_cost_a(stack_a, &cost_a);
		else if (cost_b < 0)
		{
			r_rotate(stack_b, 'b');
			cost_b++;
		}
		else if (cost_b > 0)
		{
			rotate(stack_b, 'b');
			cost_b--;
		}
	}
}
