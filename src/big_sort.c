/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/21 12:50:29 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Da cambiare
void	clever_push_a(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*num;
	int			cost_a_min;
	int			cost_b_min;
	int			best;

	num = *stack_b;
	best = 2147483647;
	while (num)
	{
		//ft_printf("ca%d...", num->costa);
		//ft_printf("cb%d\n", num->costb);
		if (my_abs(num->costa) + my_abs(num->costb) < my_abs(best))
		{
			best = my_abs(num->costa) + my_abs(num->costb);
			cost_a_min = num->costa;
			cost_b_min = num->costb;
		}
		num = num->next;
	}
	//ft_printf("%d...%d\n", cost_a_min, cost_b_min);
	choose_best_move(stack_a, stack_b, cost_a_min, cost_b_min);
}
//Cambiando, da testare
void	calc_cost_to_top(t_stacks **stack)
{
	t_stacks	*app;
	int			*costs;
	int			size;
	int			i;

	app = *stack;
	size = calc_size(app);
	costs = malloc(sizeof(int) * size + 1);
	i = 0;
	while (app)
	{
		if (app->pos <= size / 2)
			costs[i] = app->pos;
		else if (app->pos > size / 2)
			costs[i] = -(app->pos - size);
		app = app->next;
		i++;
	}
}

void	make_clever_push_b(t_stacks **stack_a, t_stacks **stack_b, int *lis)
{
	int			i;
	t_stacks	*last;

	i = 0;
	last = take_last(*stack_a);
	while (*stack_a != last)
	{
		ft_printf("%d...%d\n", (*stack_a)->i, lis[i]);
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
		calc_cost_to_top(stack_b);
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
