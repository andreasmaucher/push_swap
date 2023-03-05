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

int	find_smallest_from_top(node_t *head, int ceiling)
{
	node_t	*tmp;
	int	first_min;
	int	counter;
	int	lsize;

	first_min = ceiling; // in case we don't find a value lower we can use this to notify
	counter = 0;
	tmp = head;
	lsize = lst_size(head);
	while (tmp != NULL)
	{
		if (tmp->value <= ceiling)
		{
			first_min = tmp->value;
			/* we stop as soon as we find one value that is lower than the ceiling */
			break;
		}
		tmp = tmp->next;
		counter++;
		/* we do not want to find the lowest value in all of the stack but only in the first half */
		if (counter >= lsize/2)
			break;
	}
	/* if (first_min == ceiling)
		return (false); */
	return (first_min);
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

int	find_smallest_from_bottom(node_t *head, int ceiling)
{
	int min_value;
    node_t *current;
	int	middle;
	int	counter;
	int	lsize;
	int index;

	lsize = lst_size(head);
	counter = 0;
	min_value = ceiling;
	current = head;
    while (current != NULL) 
	{
        if (current->value <= min_value) 
		{
            min_value = current->value;
			index = counter;
			printf("success");
        }
        current = current->next;
		counter++;
		if (counter > lsize / 2) //! maybe leave out see if it causes problems
			break;
    }
	/* in case that there is no min in the 2nd half of the list */
	printf("lsize: %d\n", lsize);
		return (printf("Error\n"));
	else return(min_value);
}

	/* node_t	*tmp;
	node_t	*last_node;
	int	last_min;
	int	lsize;
	int	counter;

	lsize = lst_size(head);
	tmp = head;
	while (counter > lsize / 2)
	{
		last_node = return_tail_value(tmp);
		if (last_node->value < ceiling)
		{
			last_min = last_node->value;
			break;
			//return (last_min);
		}
		tmp = delete_at_tail(tmp);
		counter--;
	}
	printf("\n%d\n", last_min); */
	//return (last_min); //maybe I could increase the ceiling here if I dont find anything

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

int	find_shortest_path(node_t *head, int ceiling)
{
	int	middle;
	int	first;
	int	middle;

	first = find_smallest_from_top(head, ceiling);
	
}

//! ALGORITHM
node_t	*insertion(node_t *head_a)
{
	int	ceiling;
	int	ratio;
	int	lsize;
	int	instructions;

	lsize = lst_size(head_a);
	ratio = calculate_ratio(lsize);
	ceiling = find_smallest_number(head_a);
	while (lst_size(head_a) > 3)
	{
		ceiling += (ratio * 2);
		if (ceiling > third_max_value(head_a))
			ceiling = third_max_value(head_a);
		instructions = find_shortest_path(head_a, ceiling);
		while (instructions.index >= 0 && lst_size(head_a) > 3)
		{
			send_to_b(a, b, instructions, ceiling - ratio);
			instructions = get_optimal_move(*a, ceiling);
		}
	}
}

/* node_t	*insertion(node_t *head_a)
{
	node_t	*head_b;
	node_t	*tmp;
	int	min;
	int	lsize;
	int ratio;
	int	ceiling;
	int	ra_count_top;
	int	rra_count_bottom;
	int top_min;
	int	bottom_min;
	int test1;
	int test2;

	// first time creating list b!
	head_b = NULL;
	tmp = head_a;
	tmp = create_new_node(tmp->value);
	tmp->next = head_b;
	ceiling = min;
	while (check_if_sorted(head_a) == false && lsize < 4 || lsize > 3) //! need another condition because I want to have a completely empty!
	{	
		lsize = lst_size(head_a);
		ratio = calculate_ratio(lsize);
		min = find_smallest_number(head_a);
		// printf("%d\n", min);
		ceiling += (ratio * 2);
		printf("Ceiling: %d\n", ceiling);
		top_min = find_smallest_from_top(head_a, ceiling);
		printf("Top min: %d\n", top_min);
		bottom_min = find_smallest_from_bottom(head_a, ceiling);
		printf("Bottom min: %d\n", bottom_min);
		//! Case if ceiling not old enough, maybe if min still the old one
		// how many rotations to bring min value in the first half of the stack to the top
		ra_count_top = rotate_counter(head_a, top_min);
		printf("ra count top: %d\n", ra_count_top);
		rra_count_bottom = reverse_rotate_counter(head_a, bottom_min);
		printf("rra count bottom: %d\n", rra_count_bottom);
		// find shortest path, at the end target value is on top !!! could be restructured
		//if (ra_count_top <= (lsize / 2) || rra_count_bottom <= (lsize / 2))
			if (ra_count_top <= rra_count_bottom && ra_count_top <= (lsize / 2))
				head_a = rotate_until_head(head_a, ra_count_top);
			else if (ra_count_top > rra_count_bottom && rra_count_bottom <= (lsize / 2))
				head_a = reverse_rotate_until_head(head_a, rra_count_bottom);
			head_b = push_to_b(head_b, head_a);
			head_a = delete_at_head(head_a);
			if (head_b->value < ceiling - ratio)
				head_b = rotate_b(head_b);                                                                                                                                                                                                                                                                                                                                                                                             
		// in case we did find a reasonably short path
		// meaning in case we did not find a value shorter than the ceiling
		if (ra_count_top > lsize / 2 && rra_count_bottom > lsize / 2)
			ceiling += ratio * 2;
		printlist(head_a);
		printlist(head_b);
		lsize = lst_size(head_a);
		if (lsize == 3)
			head_a = three_sorter(head_a);
	}
	//to get all numbers back in stack a
	while (head_b != NULL)
	{
		head_a = push_to_a(head_a, head_b);
		head_b = delete_at_head(head_b);
	}
	free(tmp);
	return (head_a);
} */

node_t	*rotate_until_head(node_t *head_a, int	ra_count)
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
int rotate_counter(node_t *head, int min_max)
{
	node_t *temp_head;
	int	counter;
	
	counter = 0;
	temp_head = head;
	while (temp_head != NULL)
	{
		if (temp_head->value == min_max)
			break;
		temp_head = temp_head->next;
		counter++;
	}
	//printlist(head);
	//printf("%d\n", counter);
	return (counter);
}

int	reverse_rotate_counter(node_t *head, int target)
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
		if (temp_head->value == target)
			break;
		temp_head = temp_head->next;
		counter++;
	}
	res = lsize - counter;
	return (res);
}
/* 
	while (tmp != NULL)
	{
		 printf("%d\n", tmp->value);
		printf("%d\n", target); 
		if (tmp->value == target)
			break; 
		 temp_tail = return_tail_value(tmp);
		tmp = insert_at_head(tmp, temp_tail->value);
		tmp = delete_at_tail(tmp); 
		reverse_rotate_a_without_command(tmp);
		counter++;
	}
	return (counter); */

node_t	*reverse_rotate_until_head(node_t *head, int rra_counter)
{
	while (rra_counter > 0)
	{
		head = reverse_rotate_a(head);
		rra_counter--;
	}
	return (head);
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