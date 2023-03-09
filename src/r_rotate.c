/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:52:51 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/09 15:57:57 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stacks **stack, int which)
{
	t_stacks	*app;

	if (*stack == NULL || stack == NULL)
		return ;
	app = *stack;
	if (app->next == NULL)
		return ;
	while (app->next->next != NULL)
		app = app->next;
	put_first(stack, app->next);
	app->next = NULL;
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