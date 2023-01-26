/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:32:31 by amaucher          #+#    #+#             */
/*   Updated: 2022/12/08 09:32:38 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*we want to move forward in the string until we reach the first 
non-splitting character */

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

/* for each string delimited by c an array gets filled 
 char *ft_substr(char const *s, unsigned int start, size_t len) */

static void	filling_array(char **arr, size_t len_arr, char const *s, char c)
{
	size_t	i;
	size_t	len_word;

	i = 0;
	while (i < len_arr)
	{
		len_word = 0;
		while (*s == c && *s != 0)
			s++;
		while (s[len_word] != c && s[len_word] != '\0')
			len_word++;
		arr[i] = ft_substr(s, 0, len_word);
		s += len_word;
		i++;
	}
	arr[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	wcount;
	char	**arr;

	if (!s)
		return (NULL);
	wcount = ft_wordcount(s, c);
	arr = malloc(sizeof(char *) * (wcount + 1));
	if (!arr)
		return (NULL);
	filling_array(arr, wcount, s, c);
	return (arr);
}
/*
int	main()
{
	char	**arr;
	int	i;
	char c = ' ';
	char	argv[] = "hello I whish you a merry christmas";
	
	i = 0;
	arr = ft_split(argv, c);
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}
*/
