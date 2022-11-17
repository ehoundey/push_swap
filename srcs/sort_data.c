/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:59 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:32:00 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a, t_list **b)
{
	int	num2;
	int	num3;

	num2 = (*a)->next->num;
	num3 = (*a)->next->next->num;
	if ((*a)->num < num2 && num2 > num3 && (*a)->num < num3)
	{
		rev_rotate('a', a, b);
		swap_el('a', a, b);
	}
	if ((*a)->num < num2 && num2 > num3 && (*a)->num > num3)
		rev_rotate('a', a, b);
	if ((*a)->num > num2 && (*a)->num > num3 && num2 > num3)
	{
		swap_el('a', a, b);
		rev_rotate('a', a, b);
	}
	if ((*a)->num > num2 && (*a)->num > num3 && num2 < num3)
		rotate_el('a', a, b);
	if ((*a)->num > num2 && (*a)->num < num3 && num2 < num3)
		swap_el('a', a, b);
}

void	sort_four(t_list **a, t_list **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->num != min)
		rev_rotate('a', a, b);
	push_el(b, a, "pb\n");
	sort_three(a, b);
	push_el(a, b, "pa\n");
}

void	sort_five(t_list **a, t_list **b)
{
	while ((*a)->num != 0)
		rev_rotate('a', a, b);
	push_el(b, a, "pb\n");
	sort_four(a, b);
	push_el(a, b, "pa\n");
}

void	sort_small(t_list **a, t_list **b, int size)
{
	if (size == 2)
	{
		swap_el('a', a, b);
		return ;
	}
	if (size == 3)
		sort_three(a, b);
	if (size == 4)
		sort_four(a, b);
	if (size == 5)
		sort_five(a, b);
}

void	sort_data(t_list **a, t_list **b)
{
	int	size;
	int	mark_index;
	int	mark_greater;

	size = ft_lstsize(*a);
	if (size < 6)
		sort_small(a, b, size);
	else
	{
		prov_markup(a, 'i');
		mark_index = count_mark(*a);
		prov_markup(a, 'g');
		mark_greater = count_mark(*a);
		if (mark_index >= mark_greater)
			prov_markup(a, 'i');
		else
			prov_markup(a, 'g');
		ft_push_to_b(a, b);
		num_to_move_back(a, b);
	}
}
