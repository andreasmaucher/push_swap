/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:07:12 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/31 15:07:15 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* last case is optimized for 500 values; to get better results for stacks
in the range of 100+ to 400 the ratio should be lowered */
int	calculate_ratio(int n)
{
	if (n < 10)
	{
		return (1);
	}
	else if (n < 100)
	{
		return (14);
	}
	else
		return (22);
}

/* the size of chunks is determined by ratio * 2 / listsize */
int	calculate_limit(int limit, t_node *head_a)
{
	int	ratio;

	ratio = calculate_ratio(lst_size(head_a));
	limit += (ratio * 2);
	if (limit > find_third_highest_value(head_a))
		limit = find_third_highest_value(head_a);
	return (limit);
}

t_index	find_smallest_from_top_without(t_node *head, int limit)
{
	t_index	first;
	int		middle;
	int		lsize;
	t_node	*tmp_head;

	first.value = 0;
	tmp_head = head;
	lsize = lst_size(head);
	middle = return_middle_value(head, lsize);
	first.index = -1;
	while (tmp_head->value != middle)
	{
		if (tmp_head->value < limit)
		{
			first.index = 1;
			first.value = tmp_head->value;
			return (first);
		}
		tmp_head = tmp_head->next;
	}
	return (first);
}

t_index	find_smallest_from_bottom_without(t_node *head, int limit)
{
	t_index	last;
	int		middle;
	int		lsize;
	t_node	*tmp_head;

	tmp_head = head;
	lsize = lst_size(head);
	middle = return_middle_value(head, lsize);
	last.index = -1;
	last.value = tmp_head->value;
	while (tmp_head->value != middle)
		tmp_head = tmp_head->next;
	while (tmp_head != NULL)
	{
		if (tmp_head->value < limit)
		{
			last.index = 1;
			last.value = tmp_head->value;
			return (last);
		}
		tmp_head = tmp_head->next;
	}
	return (last);
}
