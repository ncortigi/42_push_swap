/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/24 17:32:46 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best(int *move_a, int *move_b, int size_b)
{
	int	best;
	int	i;
	int	pos;

	i = 0;
	best = 2147483647;
	while (i < size_b)
	{
		if (best > calculate(move_a[i], move_b[i]))
		{
			best = calculate(move_a[i], move_b[i]);
			pos = i;
		}
		i++;
	}
	if (pos == 0)
		return (0);
	return (pos);
}

void	clever_push_a(t_stacks **stack_a, t_stacks **stack_b, \
	int *move_b, int *move_a)
{
	int	best_pos;
	int	size_b;
	int	best_move_a;
	int	best_move_b;

	size_b = calc_size(*stack_b);
	best_pos = find_best(move_a, move_b, size_b);
	best_move_a = move_a[best_pos];
	best_move_b = move_b[best_pos];
	free(move_a);
	free(move_b);
	choose_best_move(stack_a, stack_b, best_move_a, best_move_b);
}

int	*calc_cost_to_top(t_stacks *stack)
{
	int			*costs;
	int			size;
	int			i;

	size = calc_size(stack);
	costs = malloc(sizeof(int) * size + 1);
	if (!costs)
		return (0);
	i = 0;
	while (stack)
	{
		if ((stack)->pos <= size / 2)
			costs[i] = (stack)->pos;
		else if ((stack)->pos > size / 2)
			costs[i] = ((stack)->pos - size);
		stack = (stack)->next;
		i++;
	}
	return (costs);
}

void	make_clever_push_b(t_stacks **stack_a, t_stacks **stack_b, \
	int *lis, int lis_lenght)
{
	int			i;
	t_stacks	*last;

	i = 0;
	last = take_last(*stack_a);
	while (*stack_a != last)
	{
		if ((*stack_a)->i == lis[i])
		{
			rotate(stack_a, 'a');
			if (i < lis_lenght)
				i++;
		}
		else if ((*stack_a)->i >= calc_size(*stack_a))
			rotate(stack_a, 'a');
		else
			push(stack_a, stack_b, 'b');
	}
	second_push_b(stack_a, stack_b, lis, lis_lenght);
}

void	big_sort(t_stacks **stack_a, t_stacks **stack_b)
{
	int	*arr_seq;
	int	*copy;
	int	size;
	int	lis_lenght;

	size = calc_size(*stack_a);
	copy = copy_list(*stack_a, size);
	lis_lenght = find_sequence(copy, size, 0, 0);
	arr_seq = find_lis(copy, size, 0, lis_lenght);
	make_clever_push_b(stack_a, stack_b, arr_seq, lis_lenght);
	while (*stack_b)
	{
		put_pos(stack_b);
		put_pos(stack_a);
		prepare_push_a(stack_a, stack_b);
		if (*stack_b == NULL)
		{
			free(arr_seq);
			free(copy);
			last_sort(stack_a, calc_size(*stack_a));
		}
	}
}
