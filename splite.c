/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:57:11 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/24 22:12:18 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char	*str)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] != ' ' && str[i])
			i++;
		while (str[i] == ' ' && str[i])
			i++;
		word++;
	}
	return (word);
}

char	**ft_splite(char *str)
{
	char	**new;
	int		i;
	int		j;
	int		count;
	int		current;
	
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	current = 0;
	count = count_word(str);
	new = malloc(sizeof(char *) * (count + 1));
	if (new == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ' && str[i] !='\0')
			i++;
		if (str[i])
		{
			current = i;
			while (str[current] != ' ' && str[current])
				current++;
			new[j] = ft_strdup(str, current, i);
			if (new == NULL)
			{
				while (j > 0)
				{
					free (new[j]);
					j--;
				}
				free(new);
				return (NULL);
			}
			j++;
		}
		while (str[i] != ' ' && str[i] != '\0')
			i++;
	}
	i = 0;
	new[j] = NULL;
	return new;
}
