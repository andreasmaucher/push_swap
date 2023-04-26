/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:07:12 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/31 15:07:15 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* last case is optimized for 500 values; to get better results for stacks
in the range of 100+ to 400 the ratio should be lowered */
int	calculate_ratio(int n)
{
	if (n < 10)
	{
		return (1);
	}
	else if (n < 100)
	{
		return (14);
	}
	else
		return (22);
}

/* the size of chunks is determined by ratio * 2 / listsize */
int	calculate_limit(int limit, t_node *head_a)
{
	int	ratio;

	ratio = calculate_ratio(lst_size(head_a));
	limit += (ratio * 2);
	if (limit > find_third_highest_value(head_a))
		limit = find_third_highest_value(head_a);
	return (limit);
}
