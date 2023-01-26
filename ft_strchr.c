/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:09:37 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/02 18:09:39 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s);
	return (0);
}

/*
int main()
{
	char s[] = "Please find";
	int c = 'n';

	printf("%s", ft_strchr(s, c));
}
*/
