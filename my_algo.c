/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 03:10:44 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/27 12:46:15 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int max_val(s_list *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;	
	}
	return (max);
}
static int pos_up(int max,s_list *list)
{
	int	pos;

	pos = 0;
	if(list == NULL)
		return -1;
	while (list->index != max && list != NULL)
	{
		pos++;
		list = list->next;
		printf("index = %d max = %d\n",list->index,max);
	}
	
	return (pos);
}

void	algo_process(s_list *stack_a, s_list *stack_b, int size)
{
	int		max;
	int		pos;
	
	esy_sort(&stack_b);
	max = max_val(stack_b);
	while (stack_b)
	{
		pos = pos_up(max, stack_b);
		if (stack_b->index == max)
		{
			push(&stack_b, &stack_a, "pa\n");
			max--;
			size--;
		}
		else if (pos <= size / 2)
		{
			while (stack_b->index != max)
			{
				rotate(&stack_b, "rb\n");
			}
			push(&stack_b, &stack_a, "pa\n");
			max--;
			size--;
		}
		else if (pos > size / 2)
		{
			while (stack_b->index != max)
			{
				reverse_rotate(&stack_b, "rrb\n");
			}
			push(&stack_b, &stack_a, "pa\n");
			max--;
			size--;
		}
	}
}
void print_list(s_list *a)
{
	while (a)
	{
		printf("%d\n",a->val);
		a =a->next;
	}
	
}
s_list *bigesst(s_list *stack)
{
	int max;
	max = 0;
	
	s_list *big;
	s_list *top;
	if(stack == NULL)
		return (NULL);
	big = stack;
	top =  stack;
	while (top)
	{
		if((top)->val > max)
		{
			max = (top)->val;
			big = top;
		}
		top = (top)->next;
	}
	return(big);
}
void set_pos(s_list *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
	
}
void algo(s_list **stack_a, s_list **stack_b)
{
    int    size;
    int    range;
    int    i;
    int    pushed;

    size = linked_list_size((*stack_a));
    range = (size <= 100) ? 13 : 38;
    i = 0;
    pushed = 0;
    esy_sort(stack_a);

    while ((*stack_a))
    {
        if ((*stack_a)->index <= i)
        {
            push(stack_a, stack_b, "pb\n");
			rotate(stack_b, "rb\n");
            i++;
        }
        else if ((*stack_a)->index < i + range)
        {
            push(stack_a, stack_b, "pb\n");
			
			i++;
        }
        else
            rotate(stack_a, "ra\n");
    }
    
	
	s_list *big;
	big = NULL;
	int biggg;
	
    while (stack_b)
    {
		big = bigesst((*stack_b));
		if(big == NULL)
			break;
		biggg = big->val;
		if(big->pos <= size / 2)
		{
			while (biggg != (*stack_b)->val)
			{
				rotate(stack_b,"rb\n");
			}
		}
		else if (big->pos > size / 2) 
		{
			while (biggg != (*stack_b)->val)
			{
				reverse_rotate( stack_b,"rrb\n");
			}
		}
		push(stack_b, stack_a, "pa\n");
		set_pos(*stack_b);
		size--;
    }
}
