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

/* below 100 always increasing by 0.6; division is getting smaller start with 1 and decrease each time by 0.1
	20 1.6 12.5(20/1.6)
	30 2.2 13.6
	40 2.8 14.2
	50 3.4 14,7
	60 4	15
	70 4.6  15.2
	80 5.2  15.38
	90 5.8  15.57

	!!how much difference would it make if I just go with 14 the middle value
	meaning ratio n < 100 = 14 does it really change that much?!!
*/

/* between 100 - 500 increase by 0.2; every 100 + 2
110 14.2 7.7
120 14.4 8.3
130 14.6 8.9
140
150
160
170
180
190 15.8
200 18
300 20
400 22
*/

int	calculate_ceiling(int ceiling, t_node *head_a)
{
	int	ratio;

	ratio = calculate_ratio(lst_size(head_a));
	ceiling += (ratio * 2);
	if (ceiling > find_third_highest_value(head_a))
		ceiling = find_third_highest_value(head_a);
	return (ceiling);
}
