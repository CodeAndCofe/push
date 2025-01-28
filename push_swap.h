/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aferryat <aferryat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:15:35 by aferryat          #+#    #+#             */
/*   Updated: 2025/01/27 11:52:27 by aferryat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

 typedef struct s_list{
	int		index;
	int		val;
	int		pos;
	struct s_list *next;
 } s_list;
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 void	ft_putstr(char *s);
 char	*ft_string(char **arr_str);
 int	ft_strlen(char *str);
 long	ft_atoi(char *str);
 char	*ft_strdup(char *str, int max, int start);
 int	linked_list_size(s_list	*list);
 void	esy_sort(s_list **list);
void    start_sort(s_list **stack_a, s_list **stack_b);
 void	push(s_list **src, s_list **dst, char *s);
 void	reverse_rotate(s_list **list, char *s);
 void	rotate(s_list **list, char *s);
 void	swap_a(s_list **list, char *s);
 void	manager(char *str);
 char	**ft_splite(char *str);
 void	swap_two(s_list **list);
 void	swap_3(s_list **list);
 void algo(s_list **stack_a, s_list **stack_b);
#endif
