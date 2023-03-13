/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/13 16:25:38 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (my_abs(best) > my_abs(num->costa) + my_abs(num->costb))
		{
			best = my_abs(num->costa) + my_abs(num->costb);
			cost_a_min = num->costa;
			cost_b_min = num->costb;
			//ft_printf("hhhh\n");
		}
		num = num->next;
	}
	//ft_printf("%d...%d\n", cost_a_min, cost_b_min);
	choose_best_move(stack_a, stack_b, cost_a_min, cost_b_min);
}

static void	make_clever_push_b(t_stacks **stack_a, t_stacks **stack_b)
{
	int i;
	int	size;
	int	count;

	count = 0;
	size = calc_size(*stack_a);
	i = 0;
	while (size > 6 && i < size && count < size / 2)
	{
		if ((*stack_a)->i <= size / 2)
		{
			push(stack_a, stack_b, 'b');
			count++;
		}
		else
			rotate(stack_a, 'a');
		i++;
	}
	while (calc_size(*stack_a) != 3)
		push(stack_a, stack_b, 'b');
}

void	calc_cost(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks		*app_a;
	t_stacks		*app_b;
	int				size_a;
	int				size_b;

	app_a = *stack_a;
	app_b = *stack_b;
	size_a = calc_size(app_a);
	size_b = calc_size(app_b);
	while (app_b)
	{
		app_b->costb = app_b->pos;
		if (app_b->pos > (size_b / 2))
			app_b->costb = -(size_b - app_b->pos);
		app_b->costa = app_b->target_pos;
		if (app_b->target_pos > (size_a / 2))
			app_b->costa = -(size_a - app_b->target_pos);
		app_b = app_b->next;
	}
}

void	big_sort(t_stacks **stack_a, t_stacks **stack_b)
{
	int	c;
	
	c = 10;
	make_clever_push_b(stack_a, stack_b);
	ft_tree_elem(stack_a);
	while (c > 0)
	{
		put_target_pos(stack_a, stack_b);
		//ft_printf("gg\n");
		calc_cost(stack_a, stack_b);
		clever_push_a(stack_a, stack_b);
		//if (*stack_b == NULL)
		//	last_sort(stack_a);
		c--;
	}
}
