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

int main(int ac, char **av)
{
	node_t	*head_a = NULL;
	node_t	*tmp_a;
	node_t	*head_b = NULL;
	node_t	*tmp_b;
	int	input;
	int i;

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
