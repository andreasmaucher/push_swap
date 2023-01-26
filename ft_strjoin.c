/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:56:58 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/07 11:57:00 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	b;
	size_t	new_len;
	char	*new;

	i = 0;
	b = 0;
	new_len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (new_len + 1));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[b] != '\0')
	{
		new[i] = s2[b];
		i++;
		b++;
	}
	new[i] = '\0';
	return (new);
}
/*
int	main()
{
	char	s1[] = "hello ";
	char	s2[] = "byebye";

	printf("%s", ft_strjoin(s1, s2));
}
*/
