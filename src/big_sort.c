/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/10 17:20:29 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	calc_steps(long int cost_a, long int cost_b)
{
	long int	steps;

	steps = 0;
	while (cost_a != 0 || cost_b != 0)
	{
		if (cost_a > 0 && cost_b > 0)
		{
			steps++;
			cost_a--;
			cost_b--;
		}
		else if (cost_a < 0 && cost_b < 0)
		{
			steps++;
			cost_a++;
			cost_b++;
		}
		else
		{
			steps += (my_abs(cost_a) + my_abs(cost_b));
			cost_a = 0;
			cost_b = 0;
		}
	}
	//ft_printf("gg:%d\n", steps);
	return (steps);
}
*/
static void	set_clever_push_a(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*num;
	long int	cost_a_min;
	long int	cost_b_min;
	long int	best;

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
			//ft_printf("%d...", steps);
		}
		num = num->next;
	}
	//ft_printf("%d...%d\n", cost_a_min, cost_b_min);
	choose_best_move(stack_a, stack_b, cost_a_min, cost_b_min);
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

/*
static void	calc_cost(t_stacks *stack_a, t_stacks *stack_b)
{
	size_t	maxpos_a;
	size_t	maxpos_b;

	maxpos_a = calc_size(stack_a);
	maxpos_b = calc_size(stack_b);
	while (stack_b)
	{
		if (maxpos_b - stack_b->pos < stack_b->pos)
		{
			stack_b->costb = maxpos_b - stack_b->pos;
			stack_b->costb *= -1;
		}
		else
			stack_b->costb = stack_b->pos;
		//ft_printf("%d", stack_b->pos);
		ft_printf("cost_b%d ", stack_b->costb);
		if (maxpos_a - stack_b->target_pos < stack_b->target_pos)
		{
			stack_b->costa = maxpos_a - stack_b->target_pos;
			stack_b->costa *= -1;
		}
		else
			stack_b->costa = stack_b->target_pos;
		//ft_printf("%d", stack_b->target_pos);
		ft_printf("cost_a%d\n", stack_b->costa);
		stack_b = stack_b->next;
	}
}

static void	last_sort(t_stacks **stack_a)
{
	t_stacks	*num;
	int			size;
	int			min_pos_i;

	put_pos(*stack_a, NULL);
	num = *stack_a;
	min_pos_i = 0;
	while (num)
	{
		if (num->i == 1)
		{
			min_pos_i = num->pos;
			break ;
		}
		num = num->next;
	}
	size = calc_size(*stack_a);
	if (size - min_pos_i < min_pos_i)
	{
		min_pos_i = size - min_pos_i;
		min_pos_i *= -1;
	}
	choose_best_move(stack_a, NULL, min_pos_i, 0);
}
*/
void	big_sort(t_stacks **stack_a, t_stacks **stack_b)
{
	int	size;
	
	size = calc_size(*stack_a);
	make_clever_push_b(stack_a, stack_b, size);
	while (*stack_b)
	{
		//put_pos(*stack_a, *stack_b);
		put_target_pos(stack_a, stack_b);
		calc_cost(stack_a, stack_b);
		set_clever_push_a(stack_a, stack_b);
		push(stack_b, stack_a, 'a');
		//if (*stack_b == NULL)
		//	last_sort(stack_a);
	}
}
