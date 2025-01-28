/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 00:56:26 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/27 11:23:47 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index(s_list *elm,s_list *top)
{
	
	while (top)
	{
		if(elm->val > top->val)
			elm->index++;
		top = top->next;
	}
	
}
void    esy_sort(s_list **list)
{
    s_list *tmp;
	s_list *top;
	
	tmp = *list;
	top = *list;
	while (tmp)
	{
		tmp->index = 0;
		set_index(tmp,top);
		tmp = tmp->next;
	}
	
}