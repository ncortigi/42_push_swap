/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:07:04 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/08 14:30:17 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_abs(int num)
{
    if (num < 0)
        num *= -1;
    return (num);
}

void	make_clever_push_b(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	int i;
	int j;

	j = size;
	while (j && size > 5)
	{
		if ((*stack_a)->i > size / 2)
			push(stack_a, stack_b, 'b');
		else
			rotate(stack_a, 'a');
		j--;
	}
	i = 0;
	size = calc_size(*stack_a);
	if (size <= 3)
		return ;
	while (i < (size - 3))
	{
		push(stack_a, stack_b, 'b');
		i++;
	}
	ft_tree_elem(stack_a);
}
