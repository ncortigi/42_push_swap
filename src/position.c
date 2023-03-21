/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:09:09 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/21 12:50:05 by ncortigi         ###   ########.fr       */
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
//Utilizzata
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

static int	targ_pos(t_stacks **stack_a, int b_i, int targ_i, int pos_targ)
{
	t_stacks	*app;

	app = *stack_a;
	while (app)
	{
		if (app->i < targ_i && app->i > b_i)
		{
			targ_i = app->i;
			pos_targ = app->pos;
		}
		app = app->next;
	}
	if (targ_i != 2147483647)
		return (pos_targ);
	app = *stack_a;
	while (app)
	{
		if (app->i < targ_i)
		{
			targ_i = app->i;
			pos_targ = app->pos;
		}
		app = app->next;
	}
	return (pos_targ);
}

void	put_target_pos(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*app;
	int			target_pos;

	app = *stack_b;
	put_pos(stack_a);
	put_pos(stack_b);
	target_pos = 0;
	while (app)
	{
		target_pos = targ_pos(stack_a, app->i, 2147483647, target_pos);
		app->target_pos = target_pos;
		app = app->next;
	}
}
