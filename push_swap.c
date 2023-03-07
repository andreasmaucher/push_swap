/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costasur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:25:07 by amaucher          #+#    #+#             */
/*   Updated: 2023/02/17 15:25:09 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int	check_valid_input

int	main(int ac, char **av)
{
	node_t	*head_a;

	/* if no parameters specified give control back to the user */
	if (ac == 1)
		return (0);
	/* also need to account for other arguments */
	if (ac >= 2)
	{
		head_a = NULL;
		head_a = create_new_list(head_a, av);
	}
	printlist(head_a);
	//TODO: in case of error display "Error\n"
	//TODO: each value is only allowed once
	if (check_if_sorted(head_a) == false)
	{
		if (lst_size(head_a) <= 4)
			head_a = three_sorter(head_a);
		if (lst_size(head_a) <= 6 && lst_size(head_a) > 4)
			head_a = five_sorter(head_a);
		if (lst_size(head_a) > 6)
			head_a = insertion(head_a);
		printlist(head_a);
	}
	freememory(head_a);
}