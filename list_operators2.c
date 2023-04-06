/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operators2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:27:29 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/31 15:27:31 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* only for testing purposes */
/* void	printlist(node_t *head)
{
	node_t *temporary = head;

	while (temporary != NULL)
	{
		printf("%d - ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
} */
node_t	*delete_at_tail(node_t *head)
{
	node_t	*current;
	node_t	*prev;

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

node_t	*return_tail_value(node_t *head)
{
	node_t	*current_node_pos;
	int		lsize;

	current_node_pos = head;
	lsize = lst_size(head);
	while (lsize > 1)
	{
		current_node_pos = current_node_pos->next;
		lsize--;
	}
	return (current_node_pos);
}

node_t	*delete_second_node(node_t *head)
{
	node_t	*current;
	node_t	*prev;

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

/* to create the new list from scratch; last input number is 
first added as head*/
node_t	*create_new_list(node_t *head, int i, char **av)
{
	node_t	*tmp;
	int		input;

	while (i >= 1)
	{	
		input = ft_atoi(av[i]);
		tmp = create_new_node(input);
		tmp->next = head;
		new_list_insert_at_head(&head, tmp);
		i--;
	}
	return (head);
}
