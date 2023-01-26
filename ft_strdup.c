/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:47:00 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/08 14:47:03 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen((char *)s);
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicate)
		return (NULL);
	while (s[i] != '\0')
	{
		duplicate[i] = (char)s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
