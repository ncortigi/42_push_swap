/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/07 18:03:52 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*find_big(t_stacks *stack)
{
	t_stacks	*max;

	max = stack;
	while (stack)
	{
		if (max->i < stack->i)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

static void	calc_cost(t_stacks *stack_a, t_stacks *stack_b)
{
	int	maxpos_a;
	int	maxpos_b;

	maxpos_a = calc_size(stack_a);
	maxpos_b = calc_size(stack_b);
	while (stack_b)
	{
		
	}
}

void	make_clever_push_b(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	int i;
	int j;

	j = size;
	while (j && size > 5)
	{
		if ((*stack_a)->i > size / 2)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		j--;
	}
	i = 0;
	size = calc_size(*stack_a);
	if (size <= 3)
		return ;
	while (i < (size - 3))
	{
		push(stack_a, stack_b, 'b');
		i++;
	}
	ft_tree_elem(stack_a);
}

void	clever_push_a(t_stacks **stack_a, t_stacks **stack_b, t_stacks *max, int size)
{
	if (find_position(*stack_b, max) < (size / 2))
	{
		while ((*stack_b)->i != max->i)
			rotate(stack_b, 'b');
	}
	else if (find_position(*stack_b, max) == 1)
		swap(*stack_b, 'b');
	else
	{
		while ((*stack_b)->i != max->i)
			r_rotate(stack_b, 'b');
	}
	push(stack_b, stack_a, 'a');
}

void	big_sort(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	make_clever_push_b(stack_a, stack_b, size);
	while (!check_sort(*stack_a))
	{
		put_pos(*stack_a, *stack_b);
		put_target_pos(*stack_a, *stack_b);
		calc_cost(*stack_a, *stack_b);
	}
	
	/*
	int	key;
	int	chunks;

	if (size <= 100)
		chunks = 4;
	else
		chunks = 12;
	key = size / chunks;
	while ((chunks) != 1)
	{
		while (calc_size(*stack_b) <= key)
		{
			make_clever_push_b(stack_a, stack_b, size, find_key(*stack_a, key));
			size = calc_size(*stack_a);
		}
		size = calc_size(*stack_a);
		chunks--;
		key = key + (size / chunks);
	}
	sort(stack_a, stack_b, size);
	while ((*stack_a)->i != 0)
		clever_push_a(stack_a, stack_b, find_big(*stack_b), calc_size(*stack_b));
	*/
}
