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
t_node	*swap_a(t_node *head)
{
	t_node	*old_head;
	t_node	*new_second_node;

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
t_node	*swap_b(t_node *head)
{
	t_node	*old_head;
	t_node	*new_second_node;

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
t_node	*rotate_a(t_node *head)
{
	t_node	*temp_head;

	temp_head = head;
	head = insert_at_tail(head, temp_head->value);
	head = delete_at_head(head);
	write(1, "ra\n", 3);
	return (head);
}

/* RULE rb rotate so that the first element becomes the last one */
t_node	*rotate_b(t_node *head)
{
	t_node	*temp_head;

	temp_head = head;
	head = insert_at_tail(head, temp_head->value);
	head = delete_at_head(head);
	write(1, "rb\n", 3);
	return (head);
}
