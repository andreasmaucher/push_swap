/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:08:07 by amaucher          #+#    #+#             */
/*   Updated: 2023/02/21 12:08:09 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct	node
{
	int	value;
	struct node *next; //a node is a structure (data & link parts) this must be a pointer to a struct
};
typedef struct node node_t;

/*main*/
int	main(int ac, char **av);

/*utils*/
bool	check_if_sorted(node_t *head);
void	freememory(node_t *head);
int	ft_atoi(const char *nptr);
int rotate_counter(node_t *head, int min_max);

/*list operators*/
node_t	*create_new_node(int value);
node_t *new_list_insert_at_head(node_t **head, node_t *node_to_insert);
node_t	*insert_at_head(node_t *head, int new_value);
node_t *delete_at_head(node_t *old_head);
node_t *insert_at_tail(node_t *head, int new_value);
node_t *delete_at_tail(node_t *head);
int	lst_size(node_t *head);
node_t *return_tail_value(node_t *head);
void	printlist(node_t *head);
node_t *delete_second_node(node_t *head);
node_t	*create_new_list(node_t *head, int i, char **av);

/*rules*/
node_t *swap_a(node_t *head);
node_t *swap_b(node_t *head);
node_t *rotate_a(node_t *head);
node_t *rotate_b(node_t *head);
node_t *reverse_rotate_a(node_t *head);
node_t *reverse_rotate_b(node_t *head);
node_t *swap(node_t *head);
node_t *push_to_b(node_t *head_b, node_t *head_a);
node_t *push_to_a(node_t *head_b, node_t *head_a);

/*sorter*/
node_t *three_sorter(node_t *head);
node_t *five_sorter(node_t *head_a);
node_t	*five_sorter_add_two(node_t *head);

/*insertion*/
int	find_smallest_number(node_t *head);
int	find_largest_number(node_t *head);
node_t	*insertion(node_t *head_a);

#endif
