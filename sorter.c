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
node_t	*three_sorter(node_t *h)
{
	node_t	*s;
	node_t	*t;

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

node_t	*five_sorter_add_two(node_t *head)
{
	node_t	*second;
	node_t	*third;
	node_t	*tail;

	second = head->next;
	third = second->next;
	if (head->value > second->value && head->value < third->value)
		head = swap_a(head);
	tail = return_tail_value(head);
	third = second->next;
	if (head->value < tail->value && head->value > third->value)
	{
		head = reverse_rotate_a(head);
		head = swap_a(head);
		head = rotate_a(head);
		head = rotate_a(head);
	}
	tail = return_tail_value(head);
	if (head->value > tail->value)
		head = rotate_a(head);
	return (head);
}

/* first time creating list b! */
/* push first two nodes of a to b to be able to apply three_sort logic */
node_t	*five_sorter(node_t *head_a)
{
	node_t	*head_b;
	node_t	*tmp;
	int		counter;

	counter = 2;
	head_b = NULL;
	tmp = head_a;
	tmp = create_new_node(tmp->value);
	tmp->next = head_b;
	while (counter-- > 0)
	{
		head_b = push_to_b(head_b, head_a);
		head_a = delete_at_head(head_a);
	}
	head_a = three_sorter(head_a);
	counter = 2;
	while (counter-- > 0)
	{
		head_a = push_to_a(head_a, head_b);
		head_b = delete_at_head(head_b);
		head_a = five_sorter_add_two(head_a);
	}
	free (tmp);
	return (head_a);
}
