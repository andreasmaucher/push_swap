/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:57:38 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/27 09:57:40 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr);

struct node 
{
	int value;
	struct node* next; //this is pointing to the next node in the list
};
typedef struct node node_t; //so we don't have to type struct all the time

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
/* 
node_t	*switch_head_with_2nd(node_t **head, node_t *node_to_insert) //we use a double pointer because we want to change the value of a pointer
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
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

int	ft_lstsize(node_t *lst) //length of list
{
	int	ret;

	ret = 0;
	while (lst && ++ret)
		lst = lst->next;
	return (ret);
}
//! funktioniert nicht
void	ft_swap_a(node_t *temp_head_a, node_t *head_a)
{
	//temp_head_a = head_a; // to temporary store the value of head a
	//printf("%i", (head_a->value));
	head_a = head_a->next; //head_a now points to the second value
	//printf("%i", (head_a->value));
	printlist(head_a);
	insert_after_node(head_a, create_new_node(temp_head_a->value)); //create_new_node(temp_head_a->value)
	//printf("%i", (head_a->value));
}

int main(int ac, char **av)
{
	node_t	*head_a = NULL;
	node_t	*tmp_a;
	node_t	*head_b = NULL;
	node_t	*tmp_b;
	node_t	*secondpos;
	node_t	*temp_head_a;
	int	input;
	int i;
	int	digits;

	i = ac-1; //if I have 3 input digits ac is 4 because of the a.out
	// ac -1 because av index starts at 0
	while (i >= 1)
	{	
		input = ft_atoi(av[i]);
		tmp_a = create_new_node(input);
		tmp_a->next = head_a;
		insert_at_head(&head_a, tmp_a);
		i--;
	}
	printlist(head_a);
	temp_head_a = head_a;
	ft_swap_a(temp_head_a, head_a);
	//! swap funktioniert hier
	/* temp_head_a = head_a; // to temporary store the value of head a
	head_a = head_a->next; //head_a now points to the second value
	insert_after_node(head_a, create_new_node(temp_head_a->value));
	printlist(head_a); */
	/* digits = ft_lstsize(head_a); //can't work with ac because length of list varies
	secondpos = head_a;
	secondpos = secondpos->next;
	printf("%i", (secondpos->value));
	head_a = head_a->next;
	printf("%i", (head_a->value));
 */
	/* second_pos = 
	node_t *tmp = head; //we set a temporary pointer to the head
	while(tmp != NULL) //as long as we did not reach the last node that points to NULL
	{
		if (tmp->value == value) 
			return tmp; // -> for member access by pointer operator
		tmp = tmp->next; // if no match, move on to the next value
	}
	return NULL; */


	/* switch_head_with_2nd(&head_a, tmp_a); */
	//printf("Head stack a: %i\n", (head_a->value)); //CHECK print head
	printf("Stack a: ");
	printlist(head_a);
	i = ac-1;
	while (i >= 1)
	{	
		input = ft_atoi(av[i]);
		tmp_b = create_new_node(input);
		tmp_b->next = head_b;
		insert_at_head(&head_b, tmp_b);
		i--;
	}
	//printf("Head stack b: %i\n", (head_b->value)); //CHECK print head
	printf("Stack b: ");
	printlist(head_b); //CHECK print list
	return(0);
}
