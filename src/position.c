/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:09:09 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/10 17:26:00 by ncortigi         ###   ########.fr       */
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

void	put_pos(t_stacks **stack)
{
	t_stacks	*app;
	int 		i;

	i = 0;
	app = *stack;
	while (app)
	{
		app->pos = i;
		app = app->next;
		i++;
	}
}

int	targ_pos(t_stacks **stack_a, int b_i, int pos, int max)
{
	t_stacks	*app;

	app = *stack_a;
	while (app)
	{
		if (app->i < max && app->i > b_i)
		{
			max = app->i;
			pos = app->pos;
		}
		app = app->next;
	}
	if (max != 2147483647)
		return (pos);
	app = *stack_a;
	while (app)
	{
		if (app->i < max)
		{
			max = app->i;
			pos = app->pos;
		}
		app = app->next;
	}
	ft_printf("f:%d", pos);
	return (pos);
}

void	put_target_pos(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*app;
	int			i;

	app = *stack_b;
	put_pos(stack_a);
	put_pos(stack_b);
	i = 0;
	while (app)
	{
		i = targ_pos(stack_a, app->i, i, 2147483647);
		app->target_pos = i;
		app = app->next;
	}
}
































/*
static void	targ_pos_higher_i(t_stacks *stack_a, t_stacks *stack_b, unsigned int min_i)
{
	while (stack_a)
	{
		if (stack_a->i < min_i)
		{
			min_i = stack_a->i;
			stack_b->target_pos = stack_a->pos;
			ft_printf("tar_pos:%d\n", stack_b->target_pos);
		}
		stack_a = stack_a->next;
	}
}

static unsigned int	target_pos(t_stacks *stack_a, t_stacks *stack_b)
{
	unsigned int diff;

	diff = stack_a->i - stack_b->i;
	//ft_printf("diff:%d\n", diff);
	stack_b->target_pos = stack_a->pos;
	//ft_printf("tar_pos:%d\n", stack_b->target_pos);
	return (diff);
}

void	put_target_pos(t_stacks *stack_a, t_stacks *stack_b)
{
	t_stacks		*first_in_a;
	unsigned int	diff;
	unsigned int	max_i;

	first_in_a = stack_a;
	max_i = 0;
	while (stack_b)
	{
		stack_a = first_in_a;
		diff = 4294967295;
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
		//ft_printf("tar_pos:%d\n", stack_b->target_pos);
		stack_b = stack_b->next;
	}
}
*/