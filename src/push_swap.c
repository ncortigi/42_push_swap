/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:13:25 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/03 18:00:40 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_size(t_stacks *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stacks	*find_little(t_stacks *stack)
{
	t_stacks	*min;

	min = stack;
	while (stack)
	{
		if (min->i > stack->i)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	choice(t_stacks *min, int size, t_stacks **stack_a, t_stacks **stack_b)
{
	if (find_position(*stack_a, min) < (size / 2))
	{
		while ((*stack_a)->i != min->i)
			rotate(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->i != min->i)
			r_rotate(stack_a, 'a');
	}
	push(stack_a, stack_b, 'b');
}

void	sort(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	int	flag;

	flag = 0;
	if (check_sort(*stack_a))
		return ;
	if (size < 51)
	{
		while (size > 3)
		{
			choice(find_little(*stack_a), size, stack_a, stack_b);
			flag++;
			size = calc_size(*stack_a);
		}
		if (!check_sort(*stack_a))
			ft_tree_elem(stack_a);
		while (flag--)
			push(stack_b, stack_a, 'a');
	}
	else
		big_sort(stack_a, stack_b, size);
}

int	main(int ac, char **av)
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;
	int			size;

	if (ac < 2)
		return (0);
	if (!check_input(av))
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_b = NULL;
	stack_a = create(ac, av);
	size = calc_size(stack_a);
	put_index(stack_a, size);
	if (size == 2)
		ft_two_elem(&stack_a);
	else if (size == 3)
		ft_tree_elem(&stack_a);
	else if (size > 3)
		sort(&stack_a, &stack_b, size);
	return (0);
}
