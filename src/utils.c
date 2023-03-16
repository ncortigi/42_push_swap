/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:07:04 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/15 12:39:13 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_abs(int num)
{
    if (num < 0)
        return (num * -1);
    return (num);
}

void	put_first(t_stacks **stack, t_stacks *new)
{
	new->next = *stack;
	(*stack) = new;
}

void	free_(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*save;

	while (*stack_a)
	{
		save = (*stack_a)->next;
		free(*stack_a);
		*stack_a = save;
	}
	*stack_a = NULL;
	if (*stack_b)
		free_(stack_b, NULL);
}
