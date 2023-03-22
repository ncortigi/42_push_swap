/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:13:40 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/22 17:28:27 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_stacks *stack_a, t_stacks *stack_b, int size_a, t_stacks *first)
{
	t_stacks	*last_a;

	last_a = take_last(stack_a);
	if (stack_b->i <= stack_a->i - 1 && stack_a->pos <= size_a / 2)
		return (stack_a->pos);
	else if (stack_b->i <= stack_a->i - 1 && stack_a->pos > size_a / 2)
		return (stack_a->pos - size_a);
	else if (stack_b->i > last_a->i && stack_b->i > first->i)
		return (-1);
	else
		return (0);
}
//Sembra funzionare
int	*calc_cost_to_a(t_stacks *stack_a, t_stacks *stack_b, \
	int size_b, int size_a)
{
	t_stacks	*app;
	t_stacks	*first;
	int			*costs;
	int			j;

	first = stack_a;
	costs = malloc(sizeof(int) * size_b + 1);
	if (!costs)
		return (0);
	j = 0;
	while (stack_b)
	{
		app = stack_a;
		costs[j] = 0;
		while (app)
		{
			if (costs[j] == 0 && stack_b->i > first->i)
				costs[j] = cost(app, stack_b, size_a, first);
			app = app->next;
		}
		stack_b = (stack_b)->next;
		j++;
	}
	return (costs);
}



static void	ft_choose_rotate(t_stacks	**stack, int *cost, char which)
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
//Sembra giusto
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
