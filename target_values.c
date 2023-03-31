/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:56:04 by amaucher          #+#    #+#             */
/*   Updated: 2023/03/31 14:56:05 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort_params	find_largest_value(node_t *head)
{
	t_sort_params	max;
	node_t			*tmp;

	max.value = INT_MIN;
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value > max.value)
			max.value = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	find_smallest_number(node_t *head)
{
	int		min;
	node_t	*tmp;

	min = INT_MAX;
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

t_sort_params	find_smallest_from_top(node_t *head, int ceiling)
{
	t_sort_params	first;
	int				middle;
	int				lsize;
	node_t			*tmp_head;

	tmp_head = head;
	lsize = lst_size(head);
	middle = return_middle_value(head, lsize);
	first.index = -1;
	while (tmp_head->value != middle)
	{
		if (tmp_head->value < ceiling)
		{
			first.index = 1;
			first.value = tmp_head->value;
			return (first);
		}
		tmp_head = tmp_head->next;
	}
	return (first);
}

int	return_middle_value(node_t *head, int lsize)
{
	node_t	*tmp;
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

t_sort_params	find_smallest_from_bottom(node_t *head, int ceiling)
{
	t_sort_params	last;
	int				middle;
	int				lsize;
	node_t			*tmp_head;

	tmp_head = head;
	lsize = lst_size(head);
	middle = return_middle_value(head, lsize);
	last.index = -1;
	while (tmp_head->value != middle)
		tmp_head = tmp_head->next;
	while (tmp_head != NULL)
	{
		if (tmp_head->value < ceiling)
		{
			last.index = 1;
			last.value = tmp_head->value;
		}
		tmp_head = tmp_head->next;
	}
	return (last);
}

int	find_third_highest_value(node_t *head)
{
	int	first;
	int	second;
	int	third;

	first = INT_MIN;
	second = INT_MIN;
	third = INT_MIN;
	while (head != NULL)
	{
		if (head->value > first)
		{
			third = second;
			second = first;
			first = head->value;
		}
		else if (head->value > second)
		{
			third = second;
			second = head->value;
		}
		else if (head->value > third)
			third = head->value;
		head = head->next;
	}
	return (third);
}