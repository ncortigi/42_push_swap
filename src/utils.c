/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncortigi <ncortigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:58:47 by ncortigi          #+#    #+#             */
/*   Updated: 2023/02/20 16:44:37 by ncortigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
