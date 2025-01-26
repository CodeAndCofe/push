/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:56:26 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/25 01:14:55 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_index(s_list **list, int *p, int size)
{
	int		i;
	s_list	*wlk;

	wlk = *list;
	i = 0;
	while (i < size)
	{
		while (wlk != NULL)
		{
			if (wlk->val == p[i])
				wlk->index = i;
			wlk = wlk->next;
		}
		wlk = *list;
		i++;
	}
}

static void	switcher(int **p, int pos)
{
	int	i;

	i = (*p)[pos];
	(*p)[pos] = (*p)[pos + 1];
	(*p)[pos + 1] = i;
}

static void	sort(int **p, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = 0;
	while (size > j)
	{
		while (min < size - j)
		{
			if (((*p)[min] > (*p)[min + 1]) && ( min + 1 != size - j))
				switcher(&(*p), min);
			min++;
		}
		min = 0;
		j++;
	}
}
void	esy_sort(s_list **list)
{
	int		size;
	int		*p;
	s_list	*wlk;
	int		i;
	
	wlk = *list;
	size = linked_list_size((*list));
	i = 0;
	p = malloc(sizeof(int) * size);
	while (wlk != NULL)
	{
		p[i] = wlk->val;
		wlk = wlk->next;
		i++;
	}
	sort(&p, i);
	set_index(&(*list), p, i);
	free(p);
}