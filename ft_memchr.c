/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:33:14 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/03 14:33:16 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (void *)s;
	while (i < n)
	{
		if (s2[i] == (char)c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
