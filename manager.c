/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:53:00 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/27 11:53:04 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static s_list    *empty_stack(void)
{
    return (NULL);
}

static s_list    *fill_stack(char **arr)
{
    s_list    *list;
    s_list    *new;
    s_list    *last;
    int        i;

    i = 0;
    list = NULL;
    while (arr[i])
    {
        new = malloc(sizeof(s_list));
        if (!new)
            return (NULL);
        new->val = ft_atoi(arr[i]);
        new->next = NULL;
        if (!list)
            list = new;
        else
            last->next = new;
        last = new;
        i++;
    }
    return (list);
}

void	 manager(char *str)
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
	stack_b = empty_stack();
	if (stack_a == NULL)
	{
		// free stack a and b and free splite
		return ;
	}
	start_sort(&stack_a, &stack_b);
	// free stack a and b
}
