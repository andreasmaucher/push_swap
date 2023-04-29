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

bool	check_int_range(int ac, char **av)
{
	int			i;
	long int	x;
	long int	*arr;

	arr = (long int *)malloc(sizeof(long int) * ac);
	if (!arr)
		return (false);
	i = 0;
	while (i < ac)
	{
		x = ft_atoi(av[i + 1]);
		if (x > INT_MAX || x < INT_MIN)
		{
			free (arr);
			return (false);
		}
		i++;
	}
	free (arr);
	return (true);
}

/* without long int check would not work! */
bool	check_duplicates(int ac, char **av)
{
	int			i;
	long int	x;
	long int	*arr;

	arr = (long int *)malloc(sizeof(long int) * ac);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		x = ft_atoi(av[i + 1]);
		arr[i] = x;
		if (loop_for_duplicates(arr, arr[i], i) == false)
		{
			free (arr);
			return (false);
		}
		i++;
	}
	free (arr);
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
	if (check_int_range(ac, av) == false)
		return (false);
	if (check_duplicates(ac, av) == false)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_node	*head_a;
	int		i;

	if (ac == 1)
		return (0);
	if (check_valid_input(ac - 1, av) == false)
		return (write(1, "Error\n", 6));
	head_a = NULL;
	i = ac - 1;
	head_a = create_new_list(head_a, i, av);
	if (check_if_sorted(head_a) == false)
	{
		if (lst_size(head_a) == 2)
			head_a = two_sorter(head_a);
		else if (lst_size(head_a) >= 3)
			head_a = three_sorter(head_a);
		else if (lst_size(head_a) > 4)
			head_a = insertion(head_a);
	}
	freememory(head_a);
}
