/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:24:18 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/24 21:36:13 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check(char *str)
{
	int	i;
	
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i] < '0' || str[i] > '9')
				return (-1);
		}
		i++;
	}
	return (1);
}

static int	arg_filter(char **arv)
{
	int	i;

	i = 1;
	while (arv[i])
	{
		if (check(arv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

int	main(int arc, char **arv)
{
	char	*str;
	int		res;
	
	if (arc <= 1)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	res = arg_filter(arv);
	if (res == -1)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	str = ft_string(arv);
	if (str == NULL)
		return (-1);
	manager(str);
	return (0);
}
