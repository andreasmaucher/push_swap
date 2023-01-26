/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:10:12 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/12 15:10:13 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	unsigned int		len;
	char				*newstr;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	newstr = malloc(sizeof(char) * (len + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
/*
char	my_function(unsigned int i, char s)
{
	return(s -= 32);
}

int	main()
{
	char	s[] = "original.string";
	char	*result = ft_strmapi(s, my_function);
	printf("%s", result);
}
*/		
