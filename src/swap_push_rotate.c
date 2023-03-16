/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:35:02 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/15 15:21:35 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stacks **stack, int which)
{
	int	app;

	if (!stack)
		return ;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	app = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = app;
	app = (*stack)->i;
	(*stack)->i = (*stack)->next->i;
	(*stack)->next->i = app;
	if (which == 97)
		ft_printf("sa\n");
	else if (which == 98)
		ft_printf("sb\n");
	else
		return ;
}

void	ss(t_stacks **stack_a, t_stacks **stack_b)
{
	swap(stack_a, 'h');
	swap(stack_b, 'h');
	ft_printf("ss\n");
}

void	push(t_stacks **src, t_stacks **dst, int which)
{
	t_stacks *app;

	if (*src == NULL)
		return ;
	app = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = app;
	if (which == 97)
		ft_printf("pa\n");
	else if (which == 98)
		ft_printf("pb\n");
	else
		return ;
}

void	rotate(t_stacks **stack, int which)
{
	t_stacks	*app;
	t_stacks	*last;

	if (*stack == NULL || stack == NULL)
		return ;
	app = *stack;
	*stack = (*stack)->next;
	last = take_last(*stack);
	app->next = NULL;
	last->next = app;
	if (which == 97)
		ft_printf("ra\n");
	else if (which == 98)
		ft_printf("rb\n");
	else
		return ;
}

void	rr(t_stacks **stack_a, t_stacks **stack_b)
{
	rotate(stack_a, 'h');
	rotate(stack_b, 'h');
	ft_printf("rr\n");
}
