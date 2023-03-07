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

//! Not more than 6 functions?

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

node_t *delete_at_tail(node_t *head)
{
	node_t *current;
	node_t *prev;

	current = head;
	prev = NULL;

	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
	return (head);
}

// determine size of list
int	lst_size(node_t *head)
{
	int lsize;
	node_t *current_node_pos;

	lsize = 0;
	current_node_pos = head;
	while (current_node_pos != NULL)
	{
		current_node_pos = current_node_pos->next;
		lsize++;
	}
	return (lsize);
}

node_t *return_tail_value(node_t *head)
{
	node_t *current_node_pos;

	int lsize;

	current_node_pos = head;
	lsize = lst_size(head);
	while (lsize > 1)
	{
		current_node_pos = current_node_pos->next;
		lsize--;
	}
	return (current_node_pos);
}

node_t *return_second_last_value(node_t *head)
{
	node_t *current_node_pos;

	int lsize;

	current_node_pos = head;
	lsize = lst_size(head);
	/* lsize >2 to avoid the last node*/
	while (lsize > 2)
	{
		current_node_pos = current_node_pos->next;
		lsize--;
	}
	return (current_node_pos);
}

node_t *return_next_chunk_value(node_t *head)
{
	node_t *current_node_pos;
	int	upper_limit;
	int	lower_limit;

	int lsize;

	upper_limit = 20;
	lower_limit = 0;
	current_node_pos = head;
	lsize = lst_size(head);
	while (current_node_pos != NULL && current_node_pos->value >= upper_limit && current_node_pos->value < lower_limit)
	{
		current_node_pos = current_node_pos->next;
		// if head = Null increase bounds until found? or do formula right away
	}
	return (current_node_pos);
}

//! this is only for testing, comment out before submitting!
void	printlist(node_t *head) //we pass the head so we know when to start
{
	node_t *temporary = head; //this is a temporary pointer set to the start of the head pointer

	while (temporary != NULL) //meaning as long as we did not hit the end yet
	{
		printf("%d - ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}

node_t *delete_second_node(node_t *head)
{
	node_t *current;
	node_t *prev;

	current = malloc(sizeof(node_t));
	if (current == NULL)
		return (NULL);
	current = head;
	prev = malloc(sizeof(node_t));
	if (prev == NULL)
		return (NULL);
	prev = NULL;

	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	free(current);
	return (head);
}

/* to create the new list from scratch*/
node_t	*create_new_list(node_t *head, char **av)
{
	node_t	*tmp;
	char	**arr;
	int	input;
	int	i;

	i = 0;
	arr = ft_split(av[1], ' ');
	while (arr[i] != NULL)
		i++;
	i -= 1;
	while (i >= 0)
	{	
		input = ft_atoi(arr[i]);
		tmp = create_new_node(input);
		tmp->next = head;
		new_list_insert_at_head(&head, tmp);
		i--; //last input number is first added as head
	}
	return (head);
}