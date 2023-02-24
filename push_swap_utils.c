/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:53:55 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/25 11:54:01 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_largest_number(node_t *head)
{
	int	max;
	node_t	*tmp;
	
	/* does it work for exactly INT_MIN/MAX???*/
	max = INT_MIN;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value < max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	find_smallest_number(node_t *head)
{
	int min;
	//int	max;
	node_t	*tmp;
	
	/* does it work for exactly INT_MIN/MAX???*/
	min = INT_MAX;
	//max = INT_MIN;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

//! ALGORITHM
node_t	*insertion(node_t *head_a)
{
	node_t	*head_b;
	node_t	*tmp;
	int	min;

	head_b = NULL;
	tmp = head_a;
	tmp = create_new_node(tmp->value);
	tmp->next = head_a;
	//create b
	while (check_if_sorted(head_a) == false)
	{	
		min = find_smallest_number(head_a);
		while (head_a->value != min)
			head_a = rotate_a(head_a);
		head_b = push_to_b(head_b, head_a);
		head_a = delete_at_head(head_a); //! this needs to be part of rule!
		if (head_a == NULL)
			break;
	}
	while (head_b != NULL)
	{
		head_a = push_to_a(head_a, head_b);
		head_b = delete_at_head(head_b); //! this needs to be part of rule!
	}
	printlist(head_a);
	printlist(head_b);
	return (head_a);
}

/* check whether the next node is always greater than the previous node */
bool	check_if_sorted(node_t *head)
{
	node_t *current;
	node_t *prev;

	current = head;
	prev = NULL;

	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
		if (prev->value > current->value)
			return (false);
	}
	return (true);
}

/* to free up all memory in the end; it is not possible to go from tail to head*/
void	freememory(node_t *head)
{
	node_t *node_to_delete;

	while (head != NULL)
	{
		node_to_delete = head;
		head = head->next; //move the head one to the right
		free(node_to_delete);
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = nptr[i] - 48 + res;
		i++;
	}
	return (res * sign);
}