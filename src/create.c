/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:29:23 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/27 18:44:56 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack_bot(t_stacks **stack, t_stacks *new)
{
	t_stacks	*last;

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

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->value = num;
	stack->i = 0;
	stack->pos = -1;
	stack->next = NULL;
	return (stack);
}

void	free_matrix(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

int	count_ac(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

t_stacks	*create(int ac, char **av, int check)
{
	t_stacks	*stack_a;
	int			num;
	int			i;

	stack_a = NULL;
	num = 0;
	i = 1;
	if (check == 2)
	{
		i = 0;
		av = split_one_arg(av);
		ac = count_ac(av);
	}
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		if ((i == 1 && check != 2) || (check == 2 && i == 0))
			stack_a = new_stack(num);
		else
			add_to_stack_bot(&stack_a, new_stack(num));
		i++;
	}
	if (check == 2)
		free_matrix(av);
	return (stack_a);
}
