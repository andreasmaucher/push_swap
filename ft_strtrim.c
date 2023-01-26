/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:43:30 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/07 14:43:32 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_start(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	start = i;
	return (start);
}

static int	find_end(char const *s1, char const *set)
{
	int	i;
	int	end;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	end = i;
	return (len - end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;
	int		trim_len;

	start = find_start(s1, set);
	end = find_end (s1, set);
	trim_len = end - start;
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	if (start >= end)
		return (ft_strdup(""));
	trim = (char *)malloc(sizeof(char) * (trim_len + 1));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, (s1 + start), (end - start + 1));
	return (trim);
}
/*
int main()
{
	char s1[] = "hhhhello my friendhhh";
	char s2[] = "h";

	printf("%s", ft_strtrim(s1, s2));
}
*/
