/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:20:50 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/03 16:20:51 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1char;
	unsigned char	*s2char;

	s1char = (unsigned char *) s1;
	s2char = (unsigned char *) s2;
	if (s1 == s2)
		return (0);
	while (n > 0)
	{
		if (*s1char != *s2char)
		{
			if (*s1char > *s2char)
				return (1);
			if (*s1char < *s2char)
				return (-1);
		}
		n--;
		s1char++;
		s2char++;
	}
	return (0);
}
