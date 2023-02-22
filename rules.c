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

//! RULE sa / sb swap first two elements
node_t *swap_a(node_t *head)
{
	node_t *old_head;
	node_t *new_second_node;

	/* do nothing if there is only one or no elements*/
	if (head->next != NULL && head != NULL) //? does this work?
	{
		old_head = head; //to save the old head & be able to free it later
		head = head->next; //set 2nd node as new head
		new_second_node = create_new_node(old_head->value);
		new_second_node->next = head->next; //next pointer of new node points now to the old second node (head->next is still 2nd node until here!)
		head->next = new_second_node; //head now points to the new second node
		free(old_head);
	}
	write(1, "sa\n", 3);
	return (head);
}

//! RULE ra / rb rotate so that the first element becomes the last one
node_t *rotate(node_t *head)
{
	node_t *temp_head;
	
	temp_head = head;
	head = insert_at_tail(head, temp_head->value);
	head = delete_at_head(head);
	write(1, "ra\n", 3);
	return (head);
}

//! RULE rra / rrb reverse rotate so that the last element becomes the first one
node_t *reverse_rotate(node_t *head)
{
	node_t *temp_tail;
	
	temp_tail = return_tail_value(head);
	head = insert_at_head(head, temp_tail->value);
	head = delete_at_tail(head);
	write(1, "rra\n", 4);
	return (head);
}

node_t *swap(node_t *head)
{
	node_t *temp_head;
	node_t *temp_tail;
	int tail;
	
	temp_head = malloc(sizeof(node_t)); //! protect malloc!
	temp_tail = malloc(sizeof(node_t));
	temp_head = head;
	temp_tail = return_tail_value(head); //! this does not work last node changed already!
	tail = temp_tail->value;
	head = delete_at_tail(head);
	head = insert_at_tail(head, temp_head->value);
	head = delete_at_head(head);
	head = insert_at_head(head, tail);
	//write(1, "sa", 2); //to display message on screen */
	return (head);
}
