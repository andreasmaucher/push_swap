/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costasur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:25:07 by amaucher          #+#    #+#             */
/*   Updated: 2023/02/17 15:25:09 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//TODO implement swap sequence: Store last number in temp, delete last node
//! I could also just swap the data no need to change the links! (&free the temp storage variables again)
// Copy head to temp, add temp as last node, add last number as head and delete old head

/* 1. Copy head value to temp;
2. Copy tail value to temp;
3. Delete tail
4. Add head value as new tail node;
5. Add tail value as second node? and then in the next step delete & free old head and make 2nd new head OR
6.  */

int	ft_atoi(const char *nptr);

struct	node
{
	int	value;
	struct node *next; //a node is a structure (data & link parts) this must be a pointer to a struct
};
typedef struct node node_t;

node_t	*create_new_node(int value)
{
	node_t *newnode = malloc(sizeof(node_t));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}

node_t	*insert_at_head(node_t **head, node_t *node_to_insert) //we use a double pointer because we want to change the value of a pointer
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

node_t *delete_at_head(node_t *head)
{
	node_t *new_head = head->next;
	free(head);
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

	current = malloc(sizeof(node_t));
	current = head;
	prev = malloc(sizeof(node_t));
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

int return_tail_value(node_t *head)
{
	node_t *current_node_pos;
	//node_t *temp_tail;
	int lsize;

	current_node_pos = head;
	lsize = lst_size(head);
	while (lsize > 2) //?bin ich bei Ende des Loops bereits hinter dem letzten Node im Nirgendwo?
	{
		current_node_pos = current_node_pos->next;
		lsize--;
	}
	//temp_tail = current_node_pos;
	printf("%d", current_node_pos->value);
	return (current_node_pos->value);
}

//does go to last node make any sense? I need to combine it with an action step like delete, otherwise what am I returning without an index?
/* node_t *go_to_last_node(node_t *head)
{
	int lsize;
	node_t *current_node_pos;

	current_node_pos = head;
	lsize = lst_size(head);
	while (lsize >= 1)
	{
		current_node_pos = current_node_pos->next;
		lsize--;
	}
	return (current_node_pos->value)
} */
//!swap
/* node_t *swap(node_t **head)
{
	node_t *temp_head;
	node_t *temp_tail;
	
	temp_head = head;
	temp_tail = return_tail_value(head);
	head = delete_at_tail(head);
	head = insert_at_tail(head, temp_tail->value); //?does this work?!
	head = delete_at_head(head);
	head = insert_at_head(&head, temp_head);
	write(1, "sa", 2); //to display message on screen
} */

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
/* 
void	freememory(node_t *head)
{
	node_t *current = head;

	while (current != NULL)
	{
		free(current->next);
		//current = current->next;
	}
}
 */
int	main(int ac, char **av)
{
	node_t	*head_a;
	node_t	*tmp_a;
	node_t *test;
	int	i;
	int input;
	int lsize;
	node_t *temp_tail;
	int temp;

	head_a = malloc(sizeof(node_t));
	head_a = NULL;
	i = ac-1; // ac -1 because av index starts at 0
	while (i >= 1)
	{	
		input = ft_atoi(av[i]);
		tmp_a = create_new_node(input);
		tmp_a->next = head_a;
		insert_at_head(&head_a, tmp_a);
		i--; //last input number is first added as head
	}
	printlist(head_a);
	//head_a = delete_at_head(head_a);
	//insert_at_head(&head_a, test); //need to run it like the loop above, what is the trigger?
	/* printlist(head_a);
	head_a = delete_at_tail(head_a);
	printlist(head_a);
	head_a = insert_at_tail(head_a, 5);
	printlist(head_a); */
	//go_to_last_node(head_a);
	/* lsize = lst_size(head_a);
	printf("%d", lsize); */
	//temp_tail = malloc(sizeof(node_t));
	//temp_tail = return_tail_value(head_a);
	temp = return_tail_value(head_a);
	//printf("%d", temp_tail->value); //?does not work in this case because theres no head
	}


