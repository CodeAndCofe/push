/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:53:00 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/25 03:09:03 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static s_list	*fill_stack(char **arr)
{
	s_list	*list;
	s_list	*wlk;
	int		i;

	i = 0;
	list = malloc(sizeof(*list));
	if (list == NULL)
		return (NULL);
	wlk = list;
	while (arr[i])
	{
		wlk->val = ft_atoi(arr[i]);
		if (arr[i + 1] != NULL)
			wlk->next = malloc(sizeof(s_list));
		else
			wlk->next = NULL;
		wlk = wlk->next;
		i++;
	}
	wlk = list;
	return (wlk);
}

static s_list	*empty_stack(s_list *a)
{
	s_list	*b;
	
	b = malloc(sizeof (*b));
	if (b == NULL)
		return (NULL);
	while (a->next != NULL)
	{
		b->next = malloc(sizeof (s_list));
		a = a->next;
		b = b->next;
	}
	b->next = NULL;
	return (b);
}

void	manager(char *str)
{
	char	**new;
	s_list	*stack_a;
	s_list	*stack_b;
	
	if (str == NULL)
		return ;
	new = ft_splite(str);
	if (new == NULL)
		return ;
	stack_a = fill_stack(new);
	stack_b = empty_stack(stack_a);
	if (stack_a == NULL || stack_b == NULL)
	{
		// free stack a and b and free splite
		return ;
	}
	start_sort(stack_a, stack_b);
	// free stack a and b
}
