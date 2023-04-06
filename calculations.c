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

int	calculate_ratio(int n)
{
	if (n < 10)
	{
		return (1);
	}
	else if (n < 100)
	{
		return ((n - 10) * 0.06 + 1);
	}
	else if (n < 500)
	{
		return ((n - 100) * 0.02 + 14);
	}
	else
	{
		return ((n - 500) * 0.006 + 30);
	}
}

int	calculate_ceiling(int ceiling, t_node *head_a)
{
	int	ratio;

	ratio = calculate_ratio(lst_size(head_a));
	ceiling += (ratio * 2);
	if (ceiling > find_third_highest_value(head_a))
		ceiling = find_third_highest_value(head_a);
	return (ceiling);
}
