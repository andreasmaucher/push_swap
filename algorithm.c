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
node_t	*ra_vs_rra(node_t *head, t_sort_params first, t_sort_params last)
{
	int				ra_count_top;
	int				rra_count_bottom;

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
node_t	*find_shortest_path(node_t *head, int ceiling)
{
	t_sort_params	first;
	t_sort_params	last;

	first = find_smallest_from_top(head, ceiling);
	last = find_smallest_from_bottom(head, ceiling);
	if (first.index != -1 || last.index != -1)
		head = ra_vs_rra(head, first, last);
	return (head);
}

/* first time creating list b */
node_t	*creating_list_b(node_t *head_a)
{
	node_t	*tmp;
	node_t	*head_b;

	head_b = NULL;
	tmp = head_a;
	tmp = create_new_node(tmp->value);
	tmp->next = head_b;
	free(tmp);
	return (head_b);
}

node_t	*list_b_condition(node_t *head_b, node_t *head_a, int ceiling)
{
	int	ratio;

	ratio = calculate_ratio(lst_size(head_a));
	head_b = push_to_b(head_b, head_a);
	if (head_b->value < (ceiling - ratio) && lst_size(head_b) > 1)
		head_b = rotate_b(head_b);
	return (head_b);
}

node_t	*move_to_a(node_t *head_a, node_t *head_b)
{
	t_sort_params	max;
	int				ra_count_top;
	int				rra_count_bottom;

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

/* ceiling > find_third_highest_value only relevant in the end*/
/* we want the last 3 values to remain in the head */
node_t	*insertion(node_t *head_a)
{
	int				ceiling;
	node_t			*head_b;
	t_sort_params	first;
	t_sort_params	last;

	head_b = creating_list_b(head_a);
	ceiling = find_smallest_number(head_a);
	while (lst_size(head_a) > 3)
	{
		ceiling = calculate_ceiling(ceiling, head_a);
		first = find_smallest_from_top(head_a, ceiling);
		last = find_smallest_from_bottom(head_a, ceiling);
		while ((lst_size(head_a) > 3 && first.index != -1)
			|| (lst_size(head_a) > 3 && last.index != -1))
		{
			head_a = find_shortest_path(head_a, ceiling);
			head_b = list_b_condition(head_b, head_a, ceiling);
			head_a = delete_at_head(head_a);
			first = find_smallest_from_top(head_a, ceiling);
			last = find_smallest_from_bottom(head_a, ceiling);
		}
	}
	head_a = move_to_a(head_a, head_b);
	return (head_a);
}
