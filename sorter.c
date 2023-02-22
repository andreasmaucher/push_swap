/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:36:49 by amaucher          #+#    #+#             */
/*   Updated: 2023/02/21 15:36:52 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node_t *three_sorter(node_t *head)
{
	node_t	*second_node;
	node_t	*tail_node;
	
	while (check_if_sorted(head) == false)
	{
		second_node = head->next;
		if (second_node->value > tail_node->value)
			head = rotate(head);
		second_node = head->next;
		if (head->value > second_node->value)
			head = swap_a(head);
		tail_node = return_tail_value(head);
		if (head->value > tail_node->value)
			head = reverse_rotate(head);
	}
	return(head);
}