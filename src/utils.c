/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:07:04 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/10 17:19:13 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_abs(int num)
{
    if (num < 0)
        num = -num;
    return (num);
}

void	make_clever_push_b(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	int i;
	int j;

	j = size;
	while (j && size > 5)
	{
		if ((*stack_a)->i < size / 2)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		j--;
	}
	i = 0;
	size = calc_size(*stack_a);
	if (size <= 3)
		return ;
	while (i < (size - 4))
	{
		push(stack_a, stack_b, 'b');
		i++;
	}
	ft_tree_elem(stack_a);
}

void	put_first(t_stacks **stack, t_stacks *new)
{
	new->next = *stack;
	(*stack) = new;
}