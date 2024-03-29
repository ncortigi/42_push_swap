/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:09:09 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/24 17:32:16 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_stacks *stack, t_stacks *to_find)
{
	int	i;

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
	int			i;

	i = 0;
	app = *stack;
	while (app)
	{
		app->pos = i;
		app = app->next;
		i++;
	}
}

int	pos_for_rotate(int pos, int next_pos, int size_a)
{
	if (pos <= size_a / 2)
		return (next_pos);
	else
		return (next_pos - size_a);
}
