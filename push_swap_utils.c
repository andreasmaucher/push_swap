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
	
	/* does it work for exactly INT_MIN/MAX???*/
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

int	find_smallest_number(node_t *head)
{
	int min;
	//int	max;
	node_t	*tmp;
	
	/* does it work for exactly INT_MIN/MAX???*/
	min = INT_MAX;
	//max = INT_MIN;

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

//! ALGORITHM
node_t	*insertion(node_t *head_a)
{
	node_t	*head_b;
	node_t	*tmp;
	node_t	*second;
	node_t	*tail;
	node_t	*second_last;
	int	min;
	int	two_min;
	int	lsize;
	int	chunk_n;
	int counter;
	int	ra_count_min;
	int	ra_count_two_min;
	int	lsize_b;

	head_b = NULL;
	tmp = head_a;
	tmp = create_new_node(tmp->value);
	tmp->next = head_a;
	//create b
	while (check_if_sorted(head_a) == false) //! need another condition because I want to have a completely empty!
	{	
		lsize = lst_size(head_a);
		//!!!! chunk logic still mising!
		chunk_n = 5; //! implement separate function to adjust chunks based on n=100 4 chunks, for n=500 11 chunks etc.
		counter = lsize/chunk_n; //amount of digits in each chunk
		min = find_smallest_number(head_a);
		two_min = find_second_smallest_number(head_a, min);
		/* optimization: find shortest path for rotate vs. reverse_rotate*/
		ra_count_min = rotate_counter(head_a, min);
		ra_count_two_min = rotate_counter(head_a, two_min);
		if (ra_count_min < ra_count_two_min)
			head_a = find_shortest_rotation_path(head_a, min, ra_count_min);
		else if (ra_count_min > ra_count_two_min)
			head_a = find_shortest_rotation_path(head_a, two_min, ra_count_two_min);
		head_b = push_to_b(head_b, head_a);
		lsize_b = lst_size(head_b);
		if (lsize_b > 1)
		{
			second = head_b->next;
			tail = return_tail_value(head_b);
			second_last = return_second_last_value(head_b);
			if (head_b->value > second->value && head_b->value > tail->value)
				head_b = rotate_b(head_b);
			if (head_b->value > second->value && head_b->value < tail->value && head_b->value > second_last->value)
			{
				head_b = reverse_rotate_b(head_b);
				head_b = swap_b(head_b);
				head_b = rotate_b(head_b);
				head_b = rotate_b(head_b);
			}
			if (head_b->value > second->value && head_b->value < tail->value)
				head_b = swap_b(head_b);
		}
			//head_b = rotate_b(head_b);
		//! extra logic to sort B or at least decide if we want to swap or rotate)
		//! rotate b
			/* if (head_b->value > second->value)
				rotate */
		head_a = delete_at_head(head_a);
		//lsize = lst_size(head_a);
		/* if (lsize == 5)
			head_a = five_sorter(head_a); */
		if (head_a == NULL)
			break;
	}
	head_b = push_to_b(head_b, head_a);
	/* to get all numbers back in stack a */
	while (head_b != NULL)
	{
		head_a = push_to_a(head_a, head_b);
		head_b = delete_at_head(head_b);
	}
	printlist(head_a);
	printlist(head_b);
	free(tmp);
	return (head_a);
}

node_t	*find_shortest_rotation_path(node_t *head_a, int	min, int	ra_count)
{
	int	lsize;

	lsize = lst_size(head_a);
		if (ra_count <= lsize/2)
		{
			while (head_a->value != min)
				head_a = rotate_a(head_a);
		}
		if (ra_count > lsize/2)
		{
			while (head_a->value != min)
				head_a = reverse_rotate_a(head_a);
		}
	return (head_a);
}

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
int rotate_counter(node_t *head, int min_max) //! until chunk value found
{
	node_t *temp_head;
	int	counter;
	
	counter = 0;
	temp_head = head;
	while (temp_head->value != min_max)
	{
		temp_head = temp_head->next;
		counter++;
	}
	return (counter);
}

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