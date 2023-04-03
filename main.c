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

bool	check_valid_input(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i >= 1)
	{
		if (ft_atoi(av[i]) <= INT_MAX && ft_atoi(av[i]) >= INT_MIN)
		i--;
		else
			return (false);
	}
	return (true);
}
/* 
bool	check_for_duplicates(int ac, char **av)
{
	int	i;
	int	a;
	int	b;
	int *arr;
	int c;

	i = ac - 1;
	a = 0;
	// fill the array
	while (i >= 1)
	{	
		c = ft_atoi(av[i]);
		arr[a] = c;
		a++;
		i--;
	}
	a = 0;
	b = 1;
	while (arr[a])
	{
		c = arr[a];
		b = a + 1;
		while (arr[b])
		{
			if (c == arr[b])
				return (false);
			b++;
		}
		a++;
	}
	return (true);
}
 */

/* if no parameters specified give control back to the user */

int	main(int ac, char **av)
{
	node_t	*head_a;
	int	i;

	if (ac == 1)
		return (0);
	if (check_valid_input(ac, av) == false)
		return(write(1, "Error\n", 6));
	/* if (check_for_duplicates(ac, av) == false)
		return(write(1, "Error\n", 6)); */ //! does not work yet!!
	head_a = NULL;
	i = ac - 1;
	head_a = create_new_list(head_a, i, av);
	if (check_if_sorted(head_a) == false)
	{
		if (ac <= 4)
			head_a = three_sorter(head_a);
		if (ac <= 6 && ac > 4)
			head_a = five_sorter(head_a);
		if (ac > 6)
			head_a = insertion(head_a);
	}
	//printlist(head_a); //!
	freememory(head_a);
}