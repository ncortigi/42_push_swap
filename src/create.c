/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:29:23 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/20 18:01:43 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	create(int ac, char **av)
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
			stack_a = funzione(num);
		else
			add_to_stack(&stack_a, funzione(num));
		i++;
	}
}
