/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:29:35 by amaucher          #+#    #+#             */
/*   Updated: 2022/11/30 12:29:37 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	full_length;
	size_t	nbytes;

	nbytes = size;
	full_length = ft_strlen(dst) + ft_strlen((char *)src);
	while (*dst != '\0' && size > 0)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (ft_strlen((char *)src) + nbytes);
	while (*src != '\0' && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (full_length);
	return (0);
}
