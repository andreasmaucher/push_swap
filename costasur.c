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

//TODO implement other operations, mainly swap first two nodes
/* then open up stack b
once all operators are done think about how to start algorithm logic 
try it out for 3 digits, where I can basically hardcode the solution
structure my code */

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

node_t *return_tail_value(node_t *head)
{
	node_t *current_node_pos;
	//node_t *temp_tail;
	int lsize;

	current_node_pos = head;
	lsize = lst_size(head);
	while (lsize > 1)
	{
		current_node_pos = current_node_pos->next;
		lsize--;
	}
	//temp_tail = current_node_pos;
	//printf("%d", current_node_pos->value);
	return (current_node_pos);
}

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
node_t *value_of_second_node(node_t *head)
{
	node_t *
} */

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
	return (head);
}

//! RULE ra / rb rotate so that the first element becomes the last one
node_t *rotate(node_t *head)
{
	node_t *temp_head;
	
	temp_head = head;
	head = insert_at_tail(head, temp_head->value);
	head = delete_at_head(head);
	//write(1, "sa", 2); //to display message on screen */
	return (head);
}

//! RULE rra / rrb reverse rotate so that the last element becomes the first one
node_t *reverse_rotate(node_t *head)
{
	node_t *temp_tail;
	
	temp_tail = return_tail_value(head);
	head = insert_at_head(head, temp_tail->value);
	head = delete_at_tail(head);
	//write(1, "sa", 2); //to display message on screen */
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
		new_list_insert_at_head(&head_a, tmp_a);
		i--; //last input number is first added as head
	}
	printlist(head_a);
	/* head_a = swap(head_a);
	printlist(head_a); */
	/* head_a = swap_a(head_a);
	printlist(head_a); */
	/* head_a = rotate(head_a);
	printlist(head_a); */
	head_a = reverse_rotate(head_a);
	printlist(head_a);
	}


