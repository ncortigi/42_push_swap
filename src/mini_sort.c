/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:29:33 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/22 17:09:45 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stacks *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	search_max_i(t_stacks *stack)
{
	int	i;

	i = stack->i;
	while (stack)
	{
		if (stack->i > i)
			i = stack->i;
		stack = stack->next;
	}
	return (i);
}

void	ft_tree_elem(t_stacks **stack_a)
{
	int	max;

	if (check_sort(*stack_a))
		return ;
	max = search_max_i(*stack_a);
	if ((*stack_a)->i == max)
		rotate(stack_a, 'a');
	else if ((*stack_a)->next->i == max)
		r_rotate(stack_a, 'a');
	if ((*stack_a)->i > (*stack_a)->next->i)
		swap(*stack_a, 'a');
}

void	ft_two_elem(t_stacks **stack_a)
{
	int sorted;

	sorted = 1;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sorted = 0;
		*stack_a = (*stack_a)->next;
	}
	if (sorted == 0)
		rotate(stack_a, 'a');
	else
		return ;
}