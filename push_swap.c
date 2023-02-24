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

//TODO implement other operations, mainly swap first two nodes
/* then open up stack b
once all operators are done think about how to start algorithm logic 
try it out for 3 digits, where I can basically hardcode the solution
structure my code */
/* if 3 values check the sorting in the list which one is bigger etc*/
/* then do a bunch of if conditions*/
/* if more than x values open up stack B*/

int	main(int ac, char **av)
{
	node_t	*head_a;
	int	i;

	/* if no parameters specified give control back to the user */
	if (ac == 1)
		return (0);
	//TODO: in case of error display "Error\n"
	//TODO: each value is only allowed once
	head_a = NULL; // important, head must always point to NULL
	i = ac-1; // ac -1 because av index starts at 0
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