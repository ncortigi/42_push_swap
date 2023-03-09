/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:29:33 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/09 15:25:16 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stacks *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

unsigned int	search_max_i(t_stacks *stack)
{
	unsigned int	i;

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
	unsigned int	max;

	if (check_sort(*stack_a))
		return ;
	max = search_max_i(*stack_a);
	if ((*stack_a)->i == max)
		rotate(stack_a, 'a');
	else if ((*stack_a)->next->i == max)
		r_rotate(stack_a, 'a');
	if ((*stack_a)->i > (*stack_a)->next->i)
		swap(stack_a, 'a');
}

void	ft_two_elem(t_stacks **stack_a)
{
	if (!check_sort(*stack_a))
		rotate(stack_a, 'a');
	else
		return ;
}