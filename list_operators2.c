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

//only for testing purposes
void	printlist(t_node *head)
{
	t_node	*temporary;

	temporary = head;
	while (temporary != NULL)
	{
		printf("%d - ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}

t_node	*delete_at_tail(t_node *head)
{
	t_node	*current;
	t_node	*prev;

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

t_node	*return_tail_value(t_node *head)
{
	t_node	*current_node_pos;
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

t_node	*delete_second_node(t_node *head)
{
	t_node	*current;
	t_node	*prev;

	current = head;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	return (head);
}

/* to create the new list from scratch; last input number is 
first added as head*/
t_node	*create_new_list(t_node *head, int i, char **av)
{
	t_node	*tmp;
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
