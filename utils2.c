/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:09:48 by amaucher          #+#    #+#             */
/*   Updated: 2023/04/04 12:09:49 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	loop_for_duplicates(long int *array, long int c, int ac)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		if (array[i] == c)
			return (false);
		i++;
	}
	return (true);
}

int	return_middle_value(t_node *head, int lsize)
{
	t_node	*tmp;
	int		counter;

	tmp = head;
	counter = 0;
	while (counter < lsize / 2)
	{
		tmp = tmp->next;
		counter++;
	}
	return (tmp->value);
}

/* first time creating list b */
t_node	*creating_list_b(t_node *head_a)
{
	t_node	*tmp;
	t_node	*head_b;

	head_b = NULL;
	tmp = head_a;
	tmp = create_new_node(tmp->value);
	tmp->next = head_b;
	free(tmp);
	return (head_b);
}
