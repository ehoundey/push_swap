/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_move_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:39 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:40 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_both(t_list **a, t_list **b, t_prov *move_am)
{
	while (move_am->a > 0 && move_am->b > 0)
	{
		if (move_am->dir_a == 0)
			rev_rotate('r', a, b);
		else
			rotate_el('r', a, b);
		move_am->a--;
		move_am->b--;
	}
}

void	from_b_to_a(t_list **a, t_list **b, int num)
{
	t_prov	*move_am;

	move_am = malloc(sizeof(t_prov));
	prov_direction_b(*b, num, move_am);
	prov_direction_a(*a, num, move_am);
	if (move_am->dir_a == move_am->dir_b)
		move_both(a, b, move_am);
	while (move_am->a > 0)
	{
		if (move_am->dir_a == 0)
			rev_rotate('a', a, b);
		else
			rotate_el('a', a, b);
		move_am->a--;
	}
	while (move_am->b > 0)
	{
		if (move_am->dir_b == 0)
			rev_rotate('b', a, b);
		else
			rotate_el('b', a, b);
		move_am->b--;
	}
	push_el(a, b, "pa\n");
	free (move_am);
}

void	ft_last_prov(t_list **a, t_list **b)
{
	int	size;
	int	direction;

	size = ft_lstsize(*a);
	if (size - (*a)->num > (*a)->num / 2)
		direction = 1;
	else
		direction = 0;
	while (if_sorted(*a))
	{
		if (direction)
			rev_rotate('a', a, b);
		else
			rotate_el('a', a, b);
	}
}

void	num_to_move_back(t_list **a, t_list **b)
{
	int	num_move;

	while (*b)
	{
		num_move = ft_prov_num(a, b);
		from_b_to_a(a, b, num_move);
	}
	ft_last_prov(a, b);
}
