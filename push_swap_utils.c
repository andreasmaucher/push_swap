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