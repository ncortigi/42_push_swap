/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/21 17:52:25 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*Da cambiare
void	clever_push_a(t_stacks **stack_a, t_stacks **stack_b, \
	int *move_b, int *move_a)
{
	t_stacks	*num;
	int			cost_a_min;
	int			cost_b_min;
	int			best;

	num = *stack_b;
	best = 2147483647;
	while (num)
	{
		if (my_abs(num->costa) + my_abs(num->costb) < my_abs(best))
		{
			best = my_abs(num->costa) + my_abs(num->costb);
			cost_a_min = num->costa;
			cost_b_min = num->costb;
		}
		num = num->next;
	}
	//ft_printf("%d...%d\n", cost_a_min, cost_b_min);
	//choose_best_move(stack_a, stack_b, cost_a_min, cost_b_min);
}*/
//Ritorna un array dei costi per mettere ogni elemento come primo
int	*calc_cost_to_top(t_stacks **stack)
{
	int			*costs;
	int			size;
	int			i;

	size = calc_size(*stack);
	costs = malloc(sizeof(int) * size + 1);
	if (!costs)
		return (0);
	i = 0;
	while (*stack)
	{
		if ((*stack)->pos <= size / 2)
			costs[i] = (*stack)->pos;
		else if ((*stack)->pos > size / 2)
			costs[i] = ((*stack)->pos - size);
		*stack = (*stack)->next;
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
	int *costs;
	int	i;

	size = calc_size(*stack_a);
	copy = copy_list(*stack_a, size);
	lis_lenght = find_sequence(copy, size, 0, 0);
	arr_seq = find_lis(copy, size, 0, lis_lenght);
	make_clever_push_b(stack_a, stack_b, arr_seq);
	//while (*stack_b)
	//{
		put_pos(stack_b);
		put_pos(stack_a);
		costs = calc_cost_to_a(stack_a, stack_b, calc_size(*stack_b), calc_size(*stack_a));
		/*clever_push_a(stack_a, stack_b, calc_cost_to_top(stack_b), \
			calc_cost_to_a(stack_a, stack_b, calc_size(*stack_b), \
			calc_size(*stack_a)));*/
	//}
	while (*stack_a)
	{
		ft_printf("%d\n", (*stack_a)->pos);
		*stack_a = (*stack_a)->next;
	}
	i = 0;
	while (i <= 91)
	{
		ft_printf("%d\n", costs[i]);
		i++;
	}
	/*cambiato fino qui
	while (*stack_b)
	{
		put_target_pos(stack_a, stack_b);
		//ft_printf("gg\n");
		calc_cost(stack_a, stack_b);
		clever_push_a(stack_a, stack_b);
		//if (*stack_b == NULL)
		//	last_sort(stack_a);
	}*/
}
