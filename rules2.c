/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:09:57 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/31 15:10:00 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* RULE pb take first node of a and push it at top of b */
node_t	*push_to_b(node_t *head_b, node_t *head_a)
{
	node_t	*tmp;

	tmp = head_a;
	head_b = insert_at_head(head_b, tmp->value);
	write(1, "pb\n", 3);
	return (head_b);
}

/* RULE pa take first node of b and push it at top of a */
node_t	*push_to_a(node_t *head_a, node_t *head_b)
{
	node_t	*tmp;

	tmp = head_b;
	head_a = insert_at_head(head_a, tmp->value);
	write(1, "pa\n", 3);
	return (head_a);
}


/* RULE rra reverse rotate so that the last element becomes the first one */
node_t	*reverse_rotate_a(node_t *head)
{
	node_t	*temp_tail;

	temp_tail = return_tail_value(head);
	head = insert_at_head(head, temp_tail->value);
	head = delete_at_tail(head);
	write(1, "rra\n", 4);
	return (head);
}

/* RULE rrb reverse rotate */
node_t	*reverse_rotate_b(node_t *head)
{
	node_t	*temp_tail;

	temp_tail = return_tail_value(head);
	head = insert_at_head(head, temp_tail->value);
	head = delete_at_tail(head);
	write(1, "rrb\n", 4);
	return (head);
}