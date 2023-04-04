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

bool	check_if_digit(char *avi)
{
	int	i;

	i = 0;
	if (avi[i] == '-' || avi[i] == '+')
		i++;
	while (avi[i] != '\0')
	{
		if (ft_isdigit(avi[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	check_for_duplicates(long int *array, long int c, int ac)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		if (array[i] == c)
			return (false);
		i++;
	}
	return (true);
}

bool	check_duplicates(int ac, char **av)
{
	int	i;
	long int x;
	long int *array;

	array = (long int *)malloc(sizeof(long int) * ac);
	if (!array)
		return (false);
	i = 0;
	while (i < ac)
	{
		x = ft_atoi(av[i + 1]);
		if (x > INT_MAX || x < INT_MIN)
		{
			free(array);
			return (false);
		}
		array[i] = x;
		if (check_for_duplicates(array, array[i], i) == false)
		{
			free(array);
			return (false);
		}
		i++;
	}
	free (array);
	return (true);
}

bool	check_valid_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (i <= ac)
	{
		if (check_if_digit(av[i]) == false)
			return (false);
		i++;
	}
	if (check_duplicates(ac, av) == false)
		return (false);
	/* if (!is_valid_integer(n, argv))
		return (false); */
	return (true);
}

/* if no parameters specified give control back to the user */
int	main(int ac, char **av)
{
	node_t	*head_a;
	int	i;

	if (ac == 1)
		return (0);
	if (check_valid_input(ac - 1, av) == false)
		return(write(1, "Error\n", 6));
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
	freememory(head_a);
}