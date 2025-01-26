/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:17:55 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/25 03:36:12 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_3(s_list **list)
{
	int	a;
	int b;
	int	c;
	
	a = (*list)->val;
	b = (*list)->next->val;
	c = (*list)->next->next->val;
	if (a > b && a > c && b < c)
		rotate(&(*list), "ra\n");
	else if (a > b && a < c)
		swap_a(&(*list), "sa\n");
	else if (a < b && b > c && a < c)
	{
		swap_a(&(*list), "sa\n");
		rotate(&(*list), "ra\n");
	}
	else if (a > b && a > c && b > c)
	{
		swap_a(&(*list), "sa\n");
		reverse_rotate(&(*list), "rra\n");
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(&(*list), "rra\n");
}

void	start_sort(s_list *stack_a, s_list *stack_b)
{
	int	len;

	len = linked_list_size(stack_a);
	if (len == 2)
		swap_two(&stack_a);
	else if (len == 3)
		swap_3(&stack_a);
	else
		algo(stack_a, stack_b);
}