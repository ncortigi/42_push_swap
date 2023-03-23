/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:13:40 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/23 18:58:38 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Fare funzione per il return che decide il segno
int	cost(t_stacks *st_a, t_stacks *st_b, int size_a, t_stacks *frst)
{
	t_stacks	*last_a;
	t_stacks	*blast_a;
	t_stacks	*min;

	min = find_little(frst);
	blast_a = take_before_last(frst);
	last_a = take_last(frst);
	if (st_b->i >= st_a->i + 1 && st_b->i <= st_a->next->i - 1 && \
		st_a->pos <= size_a / 2)
		return (st_a->next->pos);
	else if (st_b->i >= st_a->i + 1 && st_b->i <= st_a->next->i - 1 && \
		st_a->pos > size_a / 2)
		return (st_a->next->pos - size_a);
	else if (st_a == last_a && st_b->i > last_a->i && st_b->i < frst->i)
		return (0);
	else if (st_a == frst && st_b->i > frst->i && st_b->i < frst->next->i)
		return (1);
	else if (st_b->i > blast_a->i && st_b->i < last_a->i)
		return (-1);
	else if (st_b->i <= min->i - 1)
		return (min->pos);
	else
		return (0);
}

int	control(t_stacks *st_a, int cost, t_stacks *st_b)
{
	t_stacks	*last_a;

	last_a = take_last(st_a);
	if (cost == 0 && (st_b->i > st_a->i || st_b->i < last_a->i))
		return (1);
	else
		return (0);
}
//Something wrong
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
	//ft_printf("size_a:%d\n", size_a);
	while (stack_b)
	{
		app = stack_a;
		costs[j] = 0;
		while (app)
		{
			if (control(first, costs[j], stack_b))
				costs[j] = cost(app, stack_b, size_a, first);
			app = app->next;
		}
		//ft_printf("cosf:%d\n", costs[j]);
		stack_b = (stack_b)->next;
		j++;
	}
	return (costs);
}



static void	ft_choose_rotate(t_stacks **stack, int *cost, char which)
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
	push(stack_b, stack_a, 'a');
}
