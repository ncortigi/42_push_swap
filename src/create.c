/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:29:23 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/21 17:11:01 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*take_last(t_stacks *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_to_stack_bot(t_stacks **stack, t_stacks *new)
{
	t_stacks	*last;

	if (!new)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
	{
		last = take_last(*stack);
		last->next = new;
	}
}

t_stacks	*new_stack(int num)
{
	t_stacks	*stack;

	stack = (t_stacks *)malloc(sizeof(t_stacks) * num);
	if (!stack)
		return (NULL);
	stack->value = num;
	stack->i = 0;
	stack->next = NULL;
	return (stack);
}

t_stacks	*create(int ac, char **av)
{
    t_stacks	*stack_a;
	int		 num;
	int		 i;

	stack_a = NULL;
	num = 0;
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if (i = 1)
			stack_a = new_stack(num);
		else
			add_to_stack_bot(&stack_a, new_stack(num));
		i++;
	}
	return (stack_a);
}
