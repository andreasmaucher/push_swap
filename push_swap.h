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

struct	node
{
	int	value;
	struct node *next; //a node is a structure (data & link parts) this must be a pointer to a struct
};
typedef struct node node_t;

/*main*/
int	main(int ac, char **av);

/*utils*/
int	ft_atoi(const char *nptr);

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

/*rules*/
node_t *swap_a(node_t *head);
node_t *rotate(node_t *head);
node_t *reverse_rotate(node_t *head);
node_t *swap(node_t *head);

#endif
