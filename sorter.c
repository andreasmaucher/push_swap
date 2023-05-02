/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:36:49 by amaucher          #+#    #+#             */
/*   Updated: 2023/02/21 15:36:52 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*two_sorter(t_node *head)
{
	t_node	*s;

	s = head->next;
	if (head->value > s->value)
		head = rotate_a(head);
	return (head);
}

/* h = head, t = tail node, s = second node */
t_node	*three_sorter(t_node *h)
{
	t_node	*s;
	t_node	*t;

	while (check_if_sorted(h) == false)
	{
		t = return_tail_value(h);
		s = h->next;
		if (h->value < t->value && h->value > s->value && s->value < t->value)
			h = swap_a(h);
		else if (h->value > t->value && h->value > s->value && s->value > t->value)
		{
			h = swap_a(h);
			h = reverse_rotate_a(h);
		}
		//t = return_tail_value(h);
		else if (h->value > t->value && h->value > s->value && s->value < t->value)
			h = rotate_a(h);
		else if (h->value < t->value && h->value < s->value && s->value > t->value)
		{
			h = swap_a(h);
			h = rotate_a(h);
		}
		else if (h->value > t->value && h->value < s->value && s->value > t->value)
			h = reverse_rotate_a(h);
	}
	return (h);
}
