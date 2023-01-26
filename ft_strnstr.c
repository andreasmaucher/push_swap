/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:56:08 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/03 17:56:10 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (little[a] == '\0')
		return ((char *) big);
	while (big[a] != '\0' && a < len)
	{
		while (big[a + b] == little[b] && big[a + b] != '\0' && a + b < len)
		{
			b++;
		}
		if (little[b] == '\0')
			return ((char *) big + a);
		a++;
		b = 0;
	}
	return (0);
}
/*
int	main()
{
	char	big[] = "hello who are you?";
	char	little[] = "you";
	size_t	len = 30;
	
	printf("%s", ft_strnstr(big, little, len));
}
*/
