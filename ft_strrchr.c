/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:46:22 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/03 12:46:24 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*newstr;

	newstr = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			newstr = (char *)s;
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (newstr);
}
