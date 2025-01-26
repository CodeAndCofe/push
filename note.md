################################

			Push Swap

#################################

- i will re build same project []
- will copy same project []
- i will test difrent two algorithm []
- if its works 100% push and difence tommorow[]


#include "push_swap.h"

static int	pos_down(s_list *list, int size)
{
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	while (size > list->index && list)
	{
		i++;
		list = list->next;
	}
	while (size > i)
	{
		i++;
		pos++;
	}
	return (pos);
}
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
	s_list	*stack;
	int		size;
	int		posUp;
	int		posDown;

	esy_sort(&stack_b);
	size = linked_list_size(stack_b);
	while (size)
	{
		
		stack = stack_b;
		posUp = pos_up(stack_b, size);
		posDown = pos_down(stack_a, size);
		if (stack_b->index == size)
			push(&stack_b, &stack_a, "pa\n");
		else if (posDown == size)
		{
			reverse_rotate(&stack_b, "rrb\n");
			push(&stack_b, &stack_a, "pb\n");
		}
		else if (posUp == 1)
		{
			rotate(&stack_b, "rb\n");
			push(&stack_b, &stack_a, "pb\n");
		}
		else if (posUp < posDown)
		{
			while (stack_b->index != size)
				rotate(&stack_b, "rb\n");
			push(&stack_b, &stack_a, "pb\n");
		}
		else
		{	
			while (stack_b->index != size)
				reverse_rotate(&stack_b, "rrb\n");
			push(&stack_b, &stack_a, "pb\n");
		}
		size--;
	}
}