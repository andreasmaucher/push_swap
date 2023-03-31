/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:05:51 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/30 10:05:53 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* RULE pb take first node of a and push it at top of b */
node_t	*push_to_b(node_t *head_b, node_t *head_a)
{
	node_t	*tmp;

	tmp = head_a;
	head_b = insert_at_head(head_b, tmp->value);
	write(1, "pb\n", 3);
	return (head_b);
}

/* RULE pa take first node of b and push it at top of a */
node_t	*push_to_a(node_t *head_a, node_t *head_b)
{
	node_t	*tmp;

	tmp = head_b;
	head_a = insert_at_head(head_a, tmp->value);
	write(1, "pa\n", 3);
	return (head_a);
}