/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:17:55 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/27 11:52:48 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_sorted(s_list *list)
{
    while (list && list->next)
    {
        if (list->val > list->next->val)
            return (0);
        list = list->next;
    }
    return (1);
}

void    swap_3(s_list **list)
{
    int a;
    int b;
    int c;
    
    a = (*list)->val;
    b = (*list)->next->val;
    c = (*list)->next->next->val;
    
    if (a > b && b < c && a < c)
        swap_a(list, "sa\n");
    else if (a > b && b > c)
    {
        swap_a(list, "sa\n");
        reverse_rotate(list, "rra\n");
    }
    else if (a > b && b < c && a > c)
        rotate(list, "ra\n");
    else if (a < b && b > c && a < c)
    {
        swap_a(list, "sa\n");
        rotate(list, "ra\n");
    }
    else if (a < b && b > c && a > c)
        reverse_rotate(list, "rra\n");
}

void    sort_4_5(s_list **stack_a, s_list **stack_b)
{
    int size;
    int min;
    s_list *temp;

    size = linked_list_size(*stack_a);
    while (size > 3 && !is_sorted(*stack_a))
    {
        temp = *stack_a;
        min = temp->val;
        while (temp)
        {
            if (temp->val < min)
                min = temp->val;
            temp = temp->next;
        }
        while ((*stack_a)->val != min)
            rotate(stack_a, "ra\n");
        push(stack_a, stack_b, "pb\n");
        size--;
    }
    if (!is_sorted(*stack_a))
        swap_3(stack_a);
    while (*stack_b)
        push(stack_b, stack_a, "pa\n");
}

void    start_sort(s_list **stack_a, s_list **stack_b)
{
    int len;

    if (is_sorted(*stack_a))
        return;
        
    len = linked_list_size(*stack_a) - 1;
    if (len == 2)
    {
        if ((*stack_a)->val > (*stack_a)->next->val)
            swap_a(&(*stack_a), "sa\n");
    }
    else if (len == 3)
        swap_3(&(*stack_a));
    else if (len <= 5)
        sort_4_5(&(*stack_a), &(*stack_b));
    else
        algo(stack_a, stack_b);
}