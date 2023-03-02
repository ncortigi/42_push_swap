/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:21:32 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/02 17:54:36 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stacks **stack_a, t_stacks **stack_b, int size)
{
	int	key;
	int	chunks;

	if (size <= 100)
		chunks = 4;
	else
		chunks = 8;
	key = size / chunks;
	while (!check_sort(*stack_a))
	{
		while ((chunks - 1) != 0)
		{
			while (calc_size(*stack_b) < key)
			{
				make_clever_push_b(stack_a, stack_b, size);
				size = calc_size(*stack_a);
			}
			size = calc_size(*stack_a);
			chunks--;
			key = size / chunks;
		}
	}
}
