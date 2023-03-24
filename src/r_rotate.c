/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:52:51 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/24 17:35:37 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stacks **stack, int which)
{
	t_stacks	*app;
	t_stacks	*last;
	t_stacks	*bef_last;

	if (*stack == NULL || stack == NULL)
		return ;
	last = take_last(*stack);
	bef_last = take_before_last(*stack);
	app = *stack;
	*stack = last;
	(*stack)->next = app;
	bef_last->next = NULL;
	if (which == 97)
		ft_printf("rra\n");
	else if (which == 98)
		ft_printf("rrb\n");
	else
		return ;
}

void	rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	r_rotate(stack_a, 'h');
	r_rotate(stack_b, 'h');
	ft_printf("rrr\n");
}
