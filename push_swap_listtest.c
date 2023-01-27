/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_listtest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:50:56 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/25 14:50:57 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

struct node 
{
	int value;
	struct node* next; //this is pointing to the next node in the list
};
typedef struct node node_t; //so we don't have to type struct all the time

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

node_t	*create_new_node(int value)
{
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

node_t	*insert_at_head(node_t **head, node_t *node_to_insert) //we use a double pointer because we want to change the value of a pointer
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

void	*insert_after_node(node_t *node_to_insert_after, node_t* newnode)
{
	newnode->next = node_to_insert_after->next;
	node_to_insert_after->next = newnode;
}

node_t	*find_node(node_t *head, int value)
{
	node_t *tmp = head; //we set a temporary pointer to the head
	while(tmp != NULL) //as long as we did not reach the last node that points to NULL
	{
		if (tmp->value == value) 
			return tmp; // -> for member access by pointer operator
		tmp = tmp->next; // if no match, move on to the next value
	}
	return NULL; //if it does not find the value
}

int main()
{
	node_t	*head = NULL;
	node_t	*tmp;

	for (int i=0; i < 25; i++) //I could say while i smaller than the number of digits given
	{
		tmp = create_new_node(i);
		tmp->next = head;
		insert_at_head(&head, tmp);
	}

	tmp = find_node(head, 13); //find number 13
	printf("found %d\n", tmp->value);
	insert_after_node(tmp, create_new_node(75));//insert 75

	printlist(head);

	return(0);
}
