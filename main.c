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

#include "push_swap.h"

//TODO implement other operations, mainly swap first two nodes
/* then open up stack b
once all operators are done think about how to start algorithm logic 
try it out for 3 digits, where I can basically hardcode the solution
structure my code */

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
	int	i;
	int input;

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


