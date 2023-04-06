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

t_node	*create_new_node(int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (newnode == NULL)
		return (NULL);
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

/* we use a double pointer because we want to change the value of a pointer */
t_node	*new_list_insert_at_head(t_node **head, t_node *t_nodeo_insert)
{
	t_nodeo_insert->next = *head;
	*head = t_nodeo_insert;
	return (t_nodeo_insert);
}

t_node	*insert_at_head(t_node *head, int new_value)
{
	t_node	*new_head;

	new_head = create_new_node(new_value);
	if (head == NULL)
		return (new_head);
	else
	{
		new_head->next = head;
		return (new_head);
	}
}

t_node	*delete_at_head(t_node *old_head)
{
	t_node	*new_head;

	new_head = old_head->next;
	free(old_head);
	return (new_head);
}

t_node	*insert_at_tail(t_node *head, int new_value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = new_value;
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	return (head);
}
