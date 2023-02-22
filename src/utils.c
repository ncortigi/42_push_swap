/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:58:47 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/22 17:03:23 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*take_bflast(t_stacks *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stacks	*take_last(t_stacks *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int number_cmp(char *s1, char *s2)
{
	if (ft_atoi(s1) == ft_atoi(s2))
		return (1);
	return (0);
}

int limits(char *str)
{
	if (ft_atoi_long(str) > 2147483647 || ft_atoi_long(str) < -2147483648)
		return (1);
	return (0);
}


void	put_index(t_stacks *stack, int size)
{
	t_stacks	*max_i;
	t_stacks	*pointer;
	int   num;

	while (--size > 0)
	{
		pointer = stack;
		num = -2147483648;
		max_i = NULL;
		while (pointer)
		{
			if (pointer->value == -2147483648 && pointer->i == 0)
				pointer->i = 1;
			if (pointer->value > num && pointer->i == 0)
			{
				num = pointer->value;
				max_i = pointer;
				pointer = stack;
			}
			else
				pointer = pointer->next;
		}
		if (max_i != NULL)
			max_i->i = size;
	}
}
