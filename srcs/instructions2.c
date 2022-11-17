/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:23 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:24 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_el(char type, t_list **a, t_list **b)
{
	if (type == 'a')
	{
		made_swap(a);
		ft_putstr("sa\n");
	}
	else if (type == 'b')
	{
		made_swap(b);
		ft_putstr("sb\n");
	}
	else if (type == 's')
	{
		made_swap(a);
		made_swap(b);
		ft_putstr("ss\n");
	}
}

void	push_el(t_list **first, t_list **second, char *ms)
{
	t_list	*copy;

	if (!*second)
		return ;
	copy = *second;
	*second = copy->next;
	copy->next = NULL;
	ft_lstadd_front(first, copy);
	if (*ms != 'n')
		ft_putstr(ms);
}
