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

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <aio.h>

typedef struct s_index
{
	int		value;
	int		index;
}	t_index;

/* a node is a structure (data & link part) so this must be a pointer
 to a struct */
struct	s_node
{
	int				value;
	int				index;
	struct s_node	*next;
};
typedef struct s_node	t_node;

/*utils*/
long int		ft_atoi(const char *nptr);
size_t			ft_strlen(const char *s);

void			freememory(t_node *head);
void			printlist(t_node *head);

bool			ft_isdigit(int c);
bool			loop_for_duplicates(long int *array, long int c, int ac);
bool			check_if_sorted(t_node *head);

int				return_middle_value(t_node *head, int lsize);
int				lst_size(t_node *head);
int				find_third_highest_value(t_node *head);
int				find_smallest_number(t_node *head);
/*calculations*/
int				calculate_ratio(int n);
int				calculate_ceiling(int limit, t_node *head_a);
/*move counter*/
int				rotate_counter(t_node *head, t_index min_max);
int				reverse_rotate_counter(t_node *head, t_index target);
int				find_smallest_number(t_node *head);
int				find_third_highest_value(t_node *head);

/*sorter*/
t_node			*three_sorter(t_node *h);
t_node			*creating_list_b(t_node *head_a);

/*rules*/
t_node			*swap_a(t_node *head);
t_node			*swap_b(t_node *head);
t_node			*rotate_a(t_node *head);
t_node			*rotate_b(t_node *head);

/*rules2*/
t_node			*push_to_b(t_node *head_b, t_node *head_a);
t_node			*push_to_a(t_node *head_a, t_node *head_b);
t_node			*reverse_rotate_a(t_node *head);
t_node			*reverse_rotate_b(t_node *head);

/*list operators*/
t_node			*create_new_node(int value);
t_node			*new_list_insert_at_head(t_node **head, t_node *t_nodeo_insert);
t_node			*insert_at_head(t_node *head, int new_value);
t_node			*delete_at_head(t_node *old_head);
t_node			*insert_at_tail(t_node *head, int new_value);

/*list operators2*/
t_node			*delete_at_tail(t_node *head);
t_node			*return_tail_value(t_node *head);
t_node			*delete_second_node(t_node *head);
t_node			*create_new_list(t_node *head, int i, char **av);

/*algorithm*/
t_node			*ra_vs_rra(t_node *head, t_index first,
					t_index last);
t_node			*find_shortest_path(t_node *head, int limit);
t_node			*list_b_condition(t_node *head_b, t_node *head_a, int limit);
t_node			*move_to_a(t_node *head_a, t_node *head_b);
t_node			*insertion(t_node *head_a);

/*ft_split*/
char			**ft_split(char const *s, char c);

t_index			find_largest_value(t_node *head);
t_index			find_smallest_from_top(t_node *head, int limit);
t_index			find_smallest_from_bottom(t_node *head, int limit);

#endif
