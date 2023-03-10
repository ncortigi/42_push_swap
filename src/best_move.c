/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:13:40 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/10 17:13:23 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_do_rotate(t_stacks	**stack, int *cost, char c)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			if (c == 'a')
				rotate(stack, 'a');
			else if (c == 'b')
				rotate(stack, 'b');
			(*cost)--;
		}
		else if (*cost < 0)
		{
			if (c == 'a')
				r_rotate(stack, 'a');
			else if (c == 'b')
				r_rotate(stack, 'b');
			(*cost)++;
		}
	}
}

void	choose_best_move(t_stacks **stack_a, t_stacks **stack_b, \
	int cost_a, int cost_b)
{
	ft_printf("c_a%d...c_b%d\n", cost_a, cost_b);
	while (cost_a > 0 && cost_b > 0)
	{
		ft_printf("pronti\n");
		cost_a--;
		cost_b--;
		rr(stack_a, stack_b);
	}
	while (cost_a < 0 && cost_b < 0)
	{
		cost_a++;
		cost_b++;
		rrr(stack_a, stack_b);
	}
	ft_do_rotate(stack_a, &cost_a, 'a');
	ft_do_rotate(stack_b, &cost_b, 'b');
	push(stack_a, stack_b, 'a');
}









































/*
static void	negative_a_and_b(t_stacks **stack_a, t_stacks **stack_b, \
	long int *cost_a, long int *cost_b)
{
	rrr(stack_a, stack_b);
	(*cost_a)++;
	(*cost_b)++;
}

static void	positive_a_and_b(t_stacks **stack_a, t_stacks **stack_b, \
	long int *cost_a, long int *cost_b)
{
	rr(stack_a, stack_b);
	(*cost_a)--;
	(*cost_b)--;
}

static void	ft_cost_a(t_stacks **stack_a, long int *cost_a)
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

void	choose_best_move(t_stacks **stack_a, t_stacks **stack_b, \
	long int cost_a, long int cost_b)
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
*/