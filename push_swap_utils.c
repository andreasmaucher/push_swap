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

int	find_largest_number(node_t *head)
{
	int	max;
	node_t	*tmp;
	
	max = INT_MIN;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value < max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

t_sort_params	find_largest_value(node_t *head)
{
	t_sort_params	max;
	node_t	*tmp;
	
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
	int min;
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

int	find_second_smallest_number(node_t *head, int min)
{
	node_t	*tmp;
	int	second_min;

	second_min = INT_MAX;
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->value < second_min && tmp->value > min)
			second_min = tmp->value;
		tmp = tmp->next;
	}
	return (second_min);
}

t_sort_params	find_smallest_from_top(node_t *head, int ceiling)
{
	t_sort_params	first;
	int	middle;
	int	lsize;
	node_t	*tmp_head;

	tmp_head = head;
	lsize = lst_size(head);
	middle = return_middle_value(head, lsize);
	first.index = -1;
	while(tmp_head->value != middle)
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
	int	counter;

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
	int	middle;
	int	lsize;
	node_t	*tmp_head;

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
	return(last);
}

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

//! muss ich umschreiben!
int	third_max_value(node_t *stack)
{

	int	first;
	int	second;
	int	third;

	first = INT_MIN;
	second = INT_MIN;
	third = INT_MIN;
	while (stack)
	{
		if (stack->value > first)
		{
			third = second;
			second = first;
			first = stack->value;
		}
		else if (stack->value > second)
		{
			third = second;
			second = stack->value;
		}
		else if (stack->value > third)
			third = stack->value;
		stack = stack->next;
	}
	return (third);
}

/* optimal move */
node_t	*find_shortest_path(node_t *head, int ceiling)
{
	int	middle;
	t_sort_params	first;
	t_sort_params	last;
	int	ra_count_top;
	int	rra_count_bottom;
	int	lsize;

	lsize = lst_size(head);
	first = find_smallest_from_top(head, ceiling);
	//printf("first path: %d\n", first.value);
	last = find_smallest_from_bottom(head, ceiling);
	//printf("last path: %d\n", last.value);
	if (first.index != -1 || last.index != -1)
	{
		middle = return_middle_value(head, lsize); //! do I need this?!
		//printf("middle: %d\n", middle);
		ra_count_top = rotate_counter(head, first);
		//printf("ra_count_top: %d\n", ra_count_top);
		rra_count_bottom = reverse_rotate_counter(head, last);
		//printf("rra_count_bottom: %d\n", rra_count_bottom);
		//! do I need <= or is < sufficient
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
	}
	return(head);
}

//! ALGORITHM
node_t	*insertion(node_t *head_a)
{
	int	ceiling;
	int	ratio;
	int	lsize;
	int	instructions;
	node_t	*tmp;
	node_t	*head_b;
	t_sort_params	first;
	t_sort_params	last;

	/* creating b */
	head_b = NULL;
	tmp = head_a;
	tmp = create_new_node(tmp->value);
	tmp->next = head_b;

	lsize = lst_size(head_a);
	ratio = calculate_ratio(lsize);
	ceiling = find_smallest_number(head_a);
	while (lst_size(head_a) > 3)
	{
		ceiling += (ratio * 2);
		/* only relevant in the end I want the last 3 values to remain in the stack */
		if (ceiling > third_max_value(head_a))
			ceiling = third_max_value(head_a);
		first = find_smallest_from_top(head_a, ceiling);
		//printf("first index: %d\n", first.index);
		last = find_smallest_from_bottom(head_a, ceiling);
		//printf("\nlast index: %d\n", last.index);
		while (lst_size(head_a) > 3 && first.index != -1 || lst_size(head_a) > 3 && last.index != -1)
		{
			head_a = find_shortest_path(head_a, ceiling);
			head_b = push_to_b(head_b, head_a);
			head_a = delete_at_head(head_a);
			if (head_b->value < (ceiling - ratio) && lst_size(head_b) > 1)
				head_b = rotate_b(head_b);
			//printlist(head_a);
			//printlist(head_b);
			first = find_smallest_from_top(head_a, ceiling);
			//printf("first index2: %d\n", first.index);
			last = find_smallest_from_bottom(head_a, ceiling);
			//printf("last index2: %d\n", last.index);
		}
	}
	head_a = three_sorter(head_a);
	head_a = move_to_a(head_a, head_b);
	free(tmp);
	return (head_a);
}

node_t	*move_to_a(node_t *head_a, node_t *head_b)
{
	t_sort_params	max;
	int	ra_count_top;
	int	rra_count_bottom;

	while(lst_size(head_b) > 0)
	{	//printlist(head_b);
		max = find_largest_value(head_b);
		//printf("max: %d\n", max.value);
		ra_count_top = rotate_counter(head_b, max);
		//printf("ra_count_top %d\n", ra_count_top);
		rra_count_bottom = reverse_rotate_counter(head_b, max);
		//printf("rra_count_bottom %d\n", rra_count_bottom);
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
	return(head_a);
}

node_t	*rotate_until_head(node_t *head_a, int	ra_count)
{
	while (ra_count > 0)
	{
		head_a = rotate_a(head_a);
		ra_count--;
	}
	return (head_a);
}

//!
/* check whether the next node is always greater than the previous node */
bool	check_if_sorted(node_t *head)
{
	node_t *current;
	node_t *prev;

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
int rotate_counter(node_t *head, t_sort_params min_max)
{
	node_t *temp_head;
	int	counter;
	
	counter = 0;
	temp_head = head;
	while (temp_head != NULL)
	{
		if (temp_head->value == min_max.value)
			break;
		temp_head = temp_head->next;
		counter++;
	}
	//printlist(head);
	//printf("%d\n", counter);
	return (counter);
}

int	reverse_rotate_counter(node_t *head, t_sort_params target)
{
	node_t *temp_head;
	int	counter;
	int	lsize;
	int	res;
	
	lsize = lst_size(head);
	counter = 0;
	temp_head = head;
	while (temp_head != NULL)
	{
		if (temp_head->value == target.value)
			break;
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

//!
/* to free up all memory in the end; it is not possible to go from tail to head*/
void	freememory(node_t *head)
{
	node_t *node_to_delete;

	while (head != NULL)
	{
		node_to_delete = head;
		head = head->next; //move the head one to the right
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