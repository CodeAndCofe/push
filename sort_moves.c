/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:21:47 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/26 21:15:39 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(s_list **list)
{
	int		rate;
	int		temp;
    s_list	*current;

	current = *list;
    temp = current->val;
    rate = current->index;
    current->val = current->next->val;
    current->index = current->next->index;
    current->next->val = temp;
    current->next->index = rate;
}

void	swap_a(s_list **list, char *s)
{
	swap_two(&(*list));
	ft_putstr(s);
}

void	rotate(s_list **list, char *s)
{
	s_list	*temp;

	temp = *list;
	while (temp->next != NULL)
	{
		swap_two(&temp);
		temp = temp->next;
	}
	ft_putstr(s);
}

void	reverse_rotate(s_list **list, char *s)
{
	s_list	*temp;
	s_list	*pre;

	temp = *list;
	while (temp->next != NULL)
	{
		pre = temp;
		temp = temp->next;
	}
	pre->next = NULL;
	temp->next = *list;
	(*list) = temp;
	ft_putstr(s);
}

void	push(s_list **src, s_list **dst, char *s)
{
	s_list	*temp;
	s_list	*temp2;

	if (dst == NULL)
	{
		temp = (*src)->next;
		(*dst) = (*src);
		(*dst)->next = NULL;
		(*src) = temp;
	}
	else
	{
		temp2 = *dst;
		temp = (*src)->next;
		(*dst) = (*src);
		(*dst)->next = temp2;
		(*src) = temp;
	}
	ft_putstr(s);
}