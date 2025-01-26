/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 03:10:44 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/26 12:23:02 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int pos_up(s_list *list, int size)
{
	int	pos;

	pos = 0;
	while (size > list->index && list)
	{
		pos++;
		list = list->next;
	}
	return (pos);
}

static void	algo_process(s_list *stack_a, s_list *stack_b)
{
	//s_list	*stack;
	int		size;
	int		pos;
	
	esy_sort(&stack_b);
	while (stack_b != NULL) {
    size = linked_list_size(stack_b);
    pos = pos_up(stack_b, size);
    
    // Rotate if pos is closer to the start of stack_b
    if (pos <= size / 2 && pos != 0) {
        while (pos_up(stack_b, size) != 0)
            rotate(&stack_b, "rb\n");
    }
    // Reverse-rotate if pos is closer to the end of stack_b
    else if (pos > size / 2) {
        while (pos_up(stack_b, size) != 0)
            reverse_rotate(&stack_b, "rrb\n");
    }
    
    push(&stack_b, &stack_a, "pa\n");
}
}

void algo(s_list *stack_a, s_list *stack_b)
{
	int	size;
	int	range;
	int	i;

	size = linked_list_size(stack_a);
	if (size <= 100)
		range = size / 14;
	else
		range = size / 18;
	i = 0;
	esy_sort(&stack_a);
	while (stack_a)
	{
		if (stack_a->index <= i)
		{
			push(&stack_a, &stack_b, "pb\n");
			i++;
		}
		else if (stack_a->index < (i + range))
		{
			push(&stack_a, &stack_b, "pb\n");
			rotate(&stack_b, "rb\n");
			i++;
		}
		else
			rotate(&stack_a, "ra\n");
	}
	algo_process(stack_a, stack_b);
}