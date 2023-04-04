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
#include <aio.h>

typedef struct s_sort_params 
{
	int		value;
	int		index;
}	t_sort_params;

/* a node is a structure (data & link part) so this must be a pointer to a struct */
struct	node
{
	int	value;
	int	index;
	struct node *next;
};
typedef struct node node_t;

/*sorter*/
node_t	*three_sorter(node_t *h);
node_t	*five_sorter_add_two(node_t *head);
node_t	*five_sorter(node_t *head_a);

/*utils*/
size_t	ft_strlen(const char *s);
int	lst_size(node_t *head);
bool	check_if_sorted(node_t *head);
void	freememory(node_t *head);
int	ft_atoi(const char *nptr);
bool	ft_isdigit(int c);

/*target values*/
t_sort_params	find_largest_value(node_t *head);
int	find_smallest_number(node_t *head);
t_sort_params	find_smallest_from_top(node_t *head, int ceiling);
int	return_middle_value(node_t *head, int lsize);
t_sort_params	find_smallest_from_bottom(node_t *head, int ceiling);
int	find_third_highest_value(node_t *head);

/*rules*/
node_t	*swap_a(node_t *head);
node_t	*swap_b(node_t *head);
node_t	*rotate_a(node_t *head);
node_t	*rotate_b(node_t *head);

/*rules2*/
node_t	*push_to_b(node_t *head_b, node_t *head_a);
node_t	*push_to_a(node_t *head_a, node_t *head_b);
node_t	*reverse_rotate_a(node_t *head);
node_t	*reverse_rotate_b(node_t *head);

/*move counter*/
int	rotate_counter(node_t *head, t_sort_params min_max);
int	reverse_rotate_counter(node_t *head, t_sort_params target);

/*list operators*/
node_t	*create_new_node(int value);
node_t *new_list_insert_at_head(node_t **head, node_t *node_to_insert);
node_t	*insert_at_head(node_t *head, int new_value);
node_t *delete_at_head(node_t *old_head);
node_t *insert_at_tail(node_t *head, int new_value);

/*list operators2*/
void	printlist(node_t *head);
node_t *delete_at_tail(node_t *head);
node_t *return_tail_value(node_t *head);
node_t *delete_second_node(node_t *head);
node_t	*create_new_list(node_t *head, int i, char **av);

/*ft_split*/
char	**ft_split(char const *s, char c);

/*calculations*/
int	calculate_ratio(int length);
int	calculate_ceiling(int ceiling, node_t *head_a);

/*algorithm*/
node_t	*ra_vs_rra(node_t *head, t_sort_params first, t_sort_params last);
node_t	*find_shortest_path(node_t *head, int ceiling);
node_t	*creating_list_b(node_t *head_a);
node_t	*list_b_condition(node_t *head_b, node_t *head_a, int ceiling);
node_t	*move_to_a(node_t *head_a, node_t *head_b);
node_t	*insertion(node_t *head_a);

#endif
