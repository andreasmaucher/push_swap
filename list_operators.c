/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:10:19 by amaucher          #+#    #+#             */
/*   Updated: 2023/02/21 12:10:21 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node_t	*create_new_node(int value)
{
	node_t *newnode = malloc(sizeof(node_t));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}

node_t *new_list_insert_at_head(node_t **head, node_t *node_to_insert) //we use a double pointer because we want to change the value of a pointer
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return (node_to_insert);
}

node_t	*insert_at_head(node_t *head, int new_value) //we use a double pointer because we want to change the value of a pointer
{
	node_t *new_head;

	new_head = create_new_node(new_value);
	if (head == NULL)
		return (new_head);
	else
	{
		new_head->next = head;
		return (new_head);
	}
}

node_t *delete_at_head(node_t *old_head)
{
	node_t *new_head = old_head->next;
	free(old_head);
	return (new_head);
}

node_t *insert_at_tail(node_t *head, int new_value)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	new_node->value = new_value;
	node_t *current;
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	return (head);
}
