/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:15:01 by ncortigi          #+#    #+#             */
/*   Updated: 2023/03/16 17:09:04 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_list(t_stacks **stack_a, int size)
{
	int i;
	int *arr;
	int size;

	i = 0;
	arr = (int *)malloc(sizeof(int) * size + 1);
	if (!arr)
		return (0);
	while (stack_a)
	{
		arr[i++] = (*stack_a)->i;
		*stack_a = (*stack_a)->next;
	}
	return (arr);
}

int	*find_lis(int *copy, int size, int i, int lis_lenght)
{
	int	new_lenght;
	int	*lis;
	int k;

	k = i;
	new_lenght = 1;
	lis = (int *)malloc(sizeof(int) * size + 1);
	lis[0] = copy[k];
	while (k < size)
	{
		if (copy[k] > lis[new_lenght])
		{
			lis[new_lenght] = copy[k];
			new_lenght++;
		}
		k++;
	}
	if (new_lenght != lis_lenght)
	{
		free(lis);
		find_sequence(copy, size, k + 1, lis_lenght);
	}
	return (lis);
}

//copy la lista di index, size la lunghezza della lista, 
//i il numero della lista da cui partire, lis_lenght la lunghezza 
//della lis piu grande trovata.
int	*find_sequence(int *copy, int size, int i, int lis_lenght)
{
	int	new_lenght;
	int	*lis;
	int k;

	k = i;
	new_lenght = 1;
	lis = (int *)malloc(sizeof(int) * size + 1);
	lis[0] = copy[k];
	while (k < size)
	{
		if (copy[k] > lis[new_lenght])
		{
			lis[new_lenght] = copy[k];
			new_lenght++;
		}
		k++;
	}
	free(lis);
	if (new_lenght > lis_lenght && i != size)
		find_sequence(copy, size, k + 1, new_lenght);
	return (find_lis(copy, size, 0, lis_lenght));
}
