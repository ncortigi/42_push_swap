/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/23 18:46:12 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Seg fault
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
//Forse il problema sta nel passare tutte le robe a questa funzione
void	clever_push_a(t_stacks **stack_a, t_stacks **stack_b, \
	int *move_b, int *move_a)
{
	int	best_pos;
	int	size_b;
	int	best_move_a;
	int	best_move_b;

	size_b = calc_size(*stack_b);
	best_pos = find_best(move_a, move_b, size_b);
	//ft_printf("pos: %d\na: %d, b: %d\n", best_pos, move_a[best_pos], move_b[best_pos]);
	best_move_a = move_a[best_pos];
	best_move_b = move_b[best_pos];
	choose_best_move(stack_a, stack_b, best_move_a, best_move_b);
}
//Ritorna un array dei costi per mettere ogni elemento come primo
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

void	make_clever_push_b(t_stacks **stack_a, t_stacks **stack_b, int *lis)
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
			i++;
		}
		else
		{
			push(stack_a, stack_b, 'b');
		}
	}
	if (last->i != lis[i])
		push(stack_a, stack_b, 'b');
	else if (last->i == lis[i])
		rotate(stack_a, 'a');
}

void	big_sort(t_stacks **stack_a, t_stacks **stack_b)
{
	int	*arr_seq;
	int	*copy;
	int	size;
	int lis_lenght;

	size = calc_size(*stack_a);
	copy = copy_list(*stack_a, size);
	lis_lenght = find_sequence(copy, size, 0, 0);
	arr_seq = find_lis(copy, size, 0, lis_lenght);
	make_clever_push_b(stack_a, stack_b, arr_seq);
	while (*stack_b)
	{
		put_pos(stack_b);
		put_pos(stack_a);
		clever_push_a(stack_a, stack_b, calc_cost_to_top(*stack_b), \
			calc_cost_to_a(*stack_a, *stack_b, calc_size(*stack_b), \
			calc_size(*stack_a)));
		if (*stack_b == NULL)
			last_sort(stack_a);
	}
}

