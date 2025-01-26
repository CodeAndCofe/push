/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:27:19 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/24 22:14:12 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(char *str)
{
	int	res;
	int sign;
	int i;

	i = 0;
	sign = 1;
	res = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *=-1;
		i++;
	}
	while (str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

char	*ft_strdup(char *str, int max, int start)
{
	char	*new;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	new = malloc(max - start + 1);
	if (new == NULL)
		return (NULL);
	while (str[start + i] && start + i != max)
	{
		new[i] = str[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}