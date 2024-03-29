/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:20:33 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/31 15:20:35 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* count rotations */
int	rotate_counter(t_node *head, t_index min_max)
{
	t_node	*temp_head;
	int		counter;

	counter = 0;
	temp_head = head;
	while (temp_head != NULL)
	{
		if (temp_head->value == min_max.value)
			break ;
		temp_head = temp_head->next;
		counter++;
	}
	return (counter);
}

/* count reverse rotations */
int	reverse_rotate_counter(t_node *head, t_index target)
{
	t_node	*temp_head;
	int		counter;
	int		lsize;
	int		res;

	lsize = lst_size(head);
	counter = 0;
	temp_head = head;
	while (temp_head != NULL)
	{
		if (temp_head->value == target.value)
			break ;
		temp_head = temp_head->next;
		counter++;
	}
	res = lsize - counter;
	return (res);
}
