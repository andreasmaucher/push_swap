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
		if (h->value > t->value && h->value > s->value && s->value > t->value)
		{
			h = swap_a(h);
			h = reverse_rotate_a(h);
		}
		if (h->value > t->value && h->value > s->value && s->value < t->value)
			h = rotate_a(h);
		if (h->value < t->value && h->value < s->value && s->value > t->value)
		{
			h = swap_a(h);
			h = rotate_a(h);
		}
		if (h->value > t->value && h->value < s->value && s->value > t->value)
			h = reverse_rotate_a(h);
	}
	return (h);
}