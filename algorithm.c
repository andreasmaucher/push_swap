/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:50:20 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/30 15:50:22 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculate whether ra or rra is the shortest path */
t_node	*ra_vs_rra(t_node *head, t_index first, t_index last)
{
	int	ra_count_top;
	int	rra_count_bottom;

	ra_count_top = rotate_counter(head, first);
	rra_count_bottom = reverse_rotate_counter(head, last);
	if (ra_count_top <= rra_count_bottom)
	{
		while (head->value != first.value)
			head = rotate_a(head);
	}
	else if (ra_count_top > rra_count_bottom)
	{
		while (head->value != last.value)
			head = reverse_rotate_a(head);
	}
	return (head);
}

/* optimal move */
t_node	*find_shortest_path(t_node *head, int limit)
{
	t_index	first;
	t_index	last;

	first = find_smallest_from_top(head, limit);
	last = find_smallest_from_bottom(head, limit);
	if (first.index != -1 || last.index != -1)
		head = ra_vs_rra(head, first, last);
	return (head);
}

t_node	*list_b_condition(t_node *head_b, t_node *head_a, int limit)
{
	int	ratio;

	ratio = calculate_ratio(lst_size(head_a));
	head_b = push_to_b(head_b, head_a);
	if (head_b->value < (limit - ratio) && lst_size(head_b) > 1)
		head_b = rotate_b(head_b);
	return (head_b);
}

t_node	*move_to_a(t_node *head_a, t_node *head_b)
{
	t_index	max;
	int		ra_count_top;
	int		rra_count_bottom;

	head_a = three_sorter(head_a);
	while (lst_size(head_b) > 0)
	{
		max = find_largest_value(head_b);
		ra_count_top = rotate_counter(head_b, max);
		rra_count_bottom = reverse_rotate_counter(head_b, max);
		if (ra_count_top <= rra_count_bottom)
		{
			while (head_b->value != max.value)
				head_b = rotate_b(head_b);
		}
		else if (ra_count_top > rra_count_bottom)
		{
			while (head_b->value != max.value)
				head_b = reverse_rotate_b(head_b);
		}
		head_a = push_to_a(head_a, head_b);
		head_b = delete_at_head(head_b);
	}
	return (head_a);
}

/* limit > find_third_highest_value only relevant in the end*/
/* we want the last 3 values to remain in the head */
t_node	*insertion(t_node *head_a)
{
	int		limit;
	t_node	*head_b;
	t_index	first;
	t_index	last;

	head_b = creating_list_b(head_a);
	limit = find_smallest_number(head_a);
	while (lst_size(head_a) > 3)
	{
		limit = calculate_ceiling(limit, head_a);
		first = find_smallest_from_top(head_a, limit);
		last = find_smallest_from_bottom(head_a, limit);
		while ((lst_size(head_a) > 3 && first.index != -1)
			|| (lst_size(head_a) > 3 && last.index != -1))
		{
			head_a = find_shortest_path(head_a, limit);
			head_b = list_b_condition(head_b, head_a, limit);
			head_a = delete_at_head(head_a);
			first = find_smallest_from_top(head_a, limit);
			last = find_smallest_from_bottom(head_a, limit);
		}
	}
	head_a = move_to_a(head_a, head_b);
	return (head_a);
}
