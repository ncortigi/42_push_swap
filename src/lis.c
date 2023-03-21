/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:15:01 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/20 15:26:52 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_list(t_stacks *stack_a, int size)
{
	int i;
	int *arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size + 1);
	if (!arr)
		return (0);
	while (stack_a != NULL)
	{
		arr[i++] = (stack_a)->i;
		stack_a = (stack_a)->next;
	}
	return (arr);
}

int	*find_lis(int *copy, int size, int i, int lis_lenght)
{
	int	new_lenght;
	int	*lis;
	int k;

	k = i;
	new_lenght = 0;
	lis = (int *)malloc(sizeof(int) * lis_lenght + 1);
	lis[0] = copy[k];
	while (k < size)
	{
		//ft_printf("ff\n");
		if (copy[k] > lis[new_lenght])
		{
			new_lenght++;
			lis[new_lenght] = copy[k];
		}
		k++;
	}
	if (new_lenght != lis_lenght)
	{
		free(lis);
		return (find_lis(copy, size, i + 1, lis_lenght));
	}
	return (lis);
}

//copy la lista di index, size la lunghezza della lista, 
//i il numero della lista da cui partire, lis_lenght la lunghezza 
//della lis piu grande trovata.
int	find_sequence(int *copy, int size, int i, int lis_lenght)
{
	int	new_lenght;
	int	*lis;
	int k;

	k = i;
	new_lenght = 0;
	lis = (int *)malloc(sizeof(int) * size + 1);
	lis[0] = copy[k];
	while (k < size)
	{
		if (copy[k] > lis[new_lenght])
		{
			new_lenght++;
			lis[new_lenght] = copy[k];
		}
		k++;
	}
	free(lis);
	if (i < size)
	{
		if (new_lenght > lis_lenght)
			lis_lenght = new_lenght;
		return (find_sequence(copy, size, i + 1, lis_lenght));
	}
	return (lis_lenght);
}
