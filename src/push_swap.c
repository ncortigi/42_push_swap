/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:13:25 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/22 17:56:29 by ncortigi         ###   ########.fr       */
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

void	sort(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	if (size < 6)
	{
		int	max_i;

		max_i = search_max_i(stack_a);
		if (size != 4)
			push(stack_a, stack_b, 'b');
		push(stack_a, stack_b, 'b');
		ft_tree_elem(stack_a);
	}
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
}
