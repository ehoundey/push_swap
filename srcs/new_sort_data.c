/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:32 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:33 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_a(t_list **a, int size)
{
	t_list	*copy;

	copy = *a;
	while (copy)
	{
		if (copy->num < size / 4)
			copy->mark = 1;
		else if (copy->num < size / 2)
			copy->mark = 2;
		else if (copy->num >= size - size / 4)
			copy->mark = 4;
		else
			copy->mark = 3;
		copy->done = 0;
		copy = copy->next;
	}
	a = &copy;
}

void	push_data_b(t_list **a, t_list **b)
{
	while ((*a)->done != 1)
	{
		if ((*a)->mark == 3)
			push_el(b, a, "pb\n");
		else if ((*a)->mark == 2)
		{
			push_el(b, a, "pb\n");
			rotate_el('b', a, b);
		}
		else
		{
			(*a)->done = 1;
			rotate_el('a', a, b);
		}
	}
}

void	flag_to_zero(t_list **a)
{
	t_list	*copy;

	copy = *a;
	while (copy)
	{
		copy->done = 0;
		copy = copy->next;
	}
	a = &copy;
}

void	push_data_b2(t_list **a, t_list **b, int size)
{
	while ((*a)->done != 1)
	{
		if ((*a)->mark == 1)
		{
			push_el(b, a, "pb\n");
			rotate_el('b', a, b);
		}
		else if ((*a)->mark == 4)
		{
			if ((*a)->num == size - 1 || (*a)->num == size - 2
				|| (*a)->num == size - 3)
			{
				(*a)->done = 1;
				rotate_el('a', a, b);
			}
			else
				push_el(b, a, "pb\n");
		}
	}
}

void	new_sort_data(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size < 6)
		sort_small(a, b, size);
	else
	{
		mark_a(a, size);
		push_data_b(a, b);
		flag_to_zero(a);
		push_data_b2(a, b, size);
		if (if_sorted(*a))
		{
			if (ft_lstsize(*a) == 3)
				sort_three(a, b);
			else
				swap_el('a', a, b);
		}
		num_to_move_back(a, b);
	}
}
