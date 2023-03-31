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

//! from Luca
int	calculate_ratio(int length)
{
	if (length < 10)
	{
		return (1);
	}
	else if (length < 100)
	{
		return ((length - 10) * 0.04 + 1);
	}
	else if (length < 500)
	{
		return ((length - 100) * 0.02 + 14);
	}
	else
	{
		return ((length - 500) * 0.006 + 30);
	}
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
	int				middle;
	t_sort_params	first;
	t_sort_params	last;
	int				lsize;

	lsize = lst_size(head);
	first = find_smallest_from_top(head, ceiling);
	last = find_smallest_from_bottom(head, ceiling);
	if (first.index != -1 || last.index != -1)
	{
		middle = return_middle_value(head, lsize);
		head = ra_vs_rra(head, first, last);
	}
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

int	calculate_ceiling(int ceiling, node_t *head_a)
{
	int	ratio;

	ratio = calculate_ratio(lst_size(head_a));
	ceiling += (ratio * 2);
	if (ceiling > find_third_highest_value(head_a))
		ceiling = find_third_highest_value(head_a);
	return (ceiling);
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

node_t	*rotate_until_head(node_t *head_a, int ra_count)
{
	while (ra_count > 0)
	{
		head_a = rotate_a(head_a);
		ra_count--;
	}
	return (head_a);
}

/* check whether the next node is always greater than the previous node */
bool	check_if_sorted(node_t *head)
{
	node_t	*current;
	node_t	*prev;

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

/* count rotations */
int	rotate_counter(node_t *head, t_sort_params min_max)
{
	node_t	*temp_head;
	int		counter;

	counter = 0;
	temp_head = head;
	while (temp_head != NULL)
	{
		if (temp_head->value == min_max.value)
			break ;
		temp_head = temp_head->next;
		counter++;
	}
	return (counter);
}

int	reverse_rotate_counter(node_t *head, t_sort_params target)
{
	node_t	*temp_head;
	int		counter;
	int		lsize;
	int		res;

	lsize = lst_size(head);
	counter = 0;
	temp_head = head;
	while (temp_head != NULL)
	{
		if (temp_head->value == target.value)
			break ;
		temp_head = temp_head->next;
		counter++;
	}
	res = lsize - counter;
	return (res);
}

node_t	*reverse_rotate_until_head(node_t *head, int rra_counter)
{
	while (rra_counter > 0)
	{
		head = reverse_rotate_a(head);
		rra_counter--;
	}
	return (head);
}

/* to free up all memory in the end*/
void	freememory(node_t *head)
{
	node_t	*node_to_delete;

	while (head != NULL)
	{
		node_to_delete = head;
		head = head->next;
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
