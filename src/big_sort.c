/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/03 18:05:59 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*find_key(t_stacks *stack, int key)
{
	t_stacks	*found;

	found = stack;
	while (stack)
	{
		if (found->i <= key)
			break ;
		stack = stack->next;
		found = stack;
	}
	return (found);
}

void	make_clever_push_b(t_stacks **stack_a, t_stacks **stack_b, int size, t_stacks *num)
{
	ft_printf("%d", num->i);
	if (find_position(*stack_a, num) < (size / 2))
	{
		while ((*stack_a)->i != num->i)
			rotate(stack_a, 'a');
	}
	else if (find_position(*stack_a, num) == 1)
		swap(*stack_a, 'a');
	else
	{
		while ((*stack_a)->i != num->i)
			r_rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'b');
}

void	big_sort(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	int	key;
	int	chunks;

	if (size <= 100)
		chunks = 4;
	else
		chunks = 8;
	key = size / chunks;
	//ft_printf("%d", key);
	while (!check_sort(*stack_a))
	{
		while ((chunks) != 1)
		{
			while (calc_size(*stack_b) < key)
			{
				make_clever_push_b(stack_a, stack_b, size, find_key(*stack_a, key));
				size = calc_size(*stack_a);
			}
			size = calc_size(*stack_a);
			chunks--;
			key = size / chunks;
		}
	}
}
