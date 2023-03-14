/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:13:40 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/14 16:56:30 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose_rotate(t_stacks	**stack, int *cost, char which)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			if (which == 'a')
				rotate(stack, 'a');
			else if (which == 'b')
				rotate(stack, 'b');
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (which == 'a')
				r_rotate(stack, 'a');
			else if (which == 'b')
				r_rotate(stack, 'b');
			(*cost)++;
		}
	}
}

void	choose_best_move(t_stacks **stack_a, t_stacks **stack_b, \
	int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		while (cost_a > 0 && cost_b > 0)
		{
			cost_a--;
			cost_b--;
			rr(stack_a, stack_b);
		}
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		while (cost_a < 0 && cost_b < 0)
		{
			cost_a++;
			cost_b++;
			rrr(stack_a, stack_b);
		}
	}
	ft_choose_rotate(stack_a, &cost_a, 'a');
	ft_choose_rotate(stack_b, &cost_b, 'b');
	push(stack_a, stack_b, 'a');
}
