/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:53:36 by amaucher          #+#    #+#             */
/*   Updated: 2023/01/25 11:53:45 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

struct node 
{
	int value;
	struct node* next; //this is pointing to the next node in the list
};
typedef struct node node_t; //so we don't have to type struct all the time

node_t	*insert_at_head(node_t **head, node_t *node_to_insert) //we use a double pointer because we want to change the value of a pointer
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

node_t	*create_new_node(int value)
{
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

void	printlist(node_t *head) //we pass the head so we know when to start
{
	node_t *temporary = head; //this is a temporary pointer set to the start of the head pointer

	while (temporary != NULL) //meaning as long as we did not hit the end yet
	{
		printf("%d - ", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	char	**arr;
	char	splitterspace;
	int	i;
	node_t	*head = NULL;
	node_t	*tmp;

	//TODO: Implement logic if its not a string, meaning mulitple ac[1], ac[2], ...
	splitterspace = ' ';
	arr = ft_split(av[1], splitterspace);
	i = 0;
	if (ac = 2)
	{
		while (arr[i] != NULL)
		{
			printf("%s\n", arr[i]);
			i++;
		}
		//printf("%s", av[1]);
	}

	while (arr[i] != NULL)
	{
		int tmp = arr[i];
		i++;
	}
// i could work split into new node

	for (int i=0; i < 25; i++) //I could say while i smaller than the number of digits given
	{
		tmp = create_new_node(i);
		tmp->next = head;
		insert_at_head(&head, tmp);
	}

	//tmp = find_node(head, 13); //find number 13
	//printf("found %d\n", tmp->value);

	//insert_after_node(tmp, create_new_node(75));//insert 75

	printlist(head);

	return(0);
}