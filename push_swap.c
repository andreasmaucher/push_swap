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
	int	i;

	/* if no parameters specified give control back to the user */
	if (ac == 1)
		return (0);
	if (ac == 2)
		check_single_string_input(av[2]);
	//TODO: in case of error display "Error\n"
	//TODO: each value is only allowed once
	head_a = NULL;
	i = ac-1;
	head_a = create_new_list(head_a, i, av);
	printlist(head_a);
	if (check_if_sorted(head_a) == false)
	{
		if (ac <= 4)
			head_a = three_sorter(head_a);
		if (ac <= 6 && ac > 4)
			head_a = five_sorter(head_a);
		if (ac > 6)
			head_a = insertion(head_a);
		printlist(head_a);
	}
	freememory(head_a);
}