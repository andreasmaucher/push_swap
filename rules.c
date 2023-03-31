/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:09:30 by amaucher          #+#    #+#             */
/*   Updated: 2023/02/21 12:09:32 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* RULE sa swap first two elements */
/* do nothing if there is only one or no elements*/
node_t	*swap_a(node_t *head)
{
	node_t	*old_head;
	node_t	*new_second_node;

	if (head->next != NULL && head != NULL)
	{
		old_head = head;
		head = head->next;
		new_second_node = create_new_node(old_head->value);
		new_second_node->next = head->next;
		head->next = new_second_node;
		free(old_head);
	}
	write(1, "sa\n", 3);
	return (head);
}

/* RULE sb swap first two elements */
node_t	*swap_b(node_t *head)
{
	node_t	*old_head;
	node_t	*new_second_node;

	if (head->next != NULL && head != NULL)
	{
		old_head = head;
		head = head->next;
		new_second_node = create_new_node(old_head->value);
		new_second_node->next = head->next;
		head->next = new_second_node;
		free(old_head);
	}
	write(1, "sb\n", 3);
	return (head);
}

/* RULE ra rotate so that the first element becomes the last one */
node_t	*rotate_a(node_t *head)
{
	node_t	*temp_head;

	temp_head = head;
	head = insert_at_tail(head, temp_head->value);
	head = delete_at_head(head);
	write(1, "ra\n", 3);
	return (head);
}

/* RULE rb rotate so that the first element becomes the last one */
node_t	*rotate_b(node_t *head)
{
	node_t	*temp_head;

	temp_head = head;
	head = insert_at_tail(head, temp_head->value);
	head = delete_at_head(head);
	write(1, "rb\n", 3);
	return (head);
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
