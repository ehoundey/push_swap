/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:56 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:57 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_finish(t_list *a)
{
	while (a)
	{
		if (a->markup == 0)
			return (1);
		a = a->next;
	}
	return (0);
}

int	if_sorted(t_list *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->num < a->next->num)
			a = a->next;
		else
			return (1);
	}
	return (0);
}

void	ft_push_to_b(t_list **a, t_list **b)
{
	while (ft_finish(*a))
	{
		if ((*a)->markup == 0)
			push_el(b, a, "pb\n");
		else
			rotate_el('a', a, b);
	}
	if (if_sorted(*a))
		rotate_el('a', a, b);
}
