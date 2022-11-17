/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_prov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:35 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:36 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prov_direction_b(t_list *b, int num, t_prov *move_am)
{
	int	past_b;

	move_am->b = 0;
	past_b = 1;
	while (b && b->num != num)
	{
		move_am->b++;
		b = b->next;
	}
	b = b->next;
	while (b)
	{
		past_b++;
		b = b->next;
	}
	if (past_b < move_am->b)
	{
		move_am->b = past_b;
		move_am->dir_b = 0;
	}
	else
		move_am->dir_b = 1;
}

int	ft_go_to_a(t_list *a, int num)
{
	int	to_a;
	int	past_a;

	to_a = 0;
	past_a = 0;
	while (a && a->num < num)
	{
		to_a++;
		a = a->next;
	}
	while (a)
	{
		past_a++;
		a = a->next;
	}
	if (past_a > to_a)
		return (to_a);
	else
		return (past_a);
}

int	ft_go_b(t_list *b, int num)
{
	int	to_b;
	int	past_b;

	to_b = 0;
	past_b = 1;
	while (b && b->num != num)
	{
		to_b++;
		b = b->next;
	}
	b = b->next;
	while (b)
	{
		past_b++;
		b = b->next;
	}
	if (past_b > to_b)
		return (to_b);
	else
		return (past_b);
}

int	ft_prov_b(t_list *a, t_list *b, int num)
{
	int	b_num;
	int	a_num;

	a_num = ft_go_to_a(a, num);
	b_num = ft_go_b(b, num);
	return (a_num + b_num);
}

int	ft_prov_num(t_list **a, t_list **b)
{
	int		amount;
	int		new_am;
	int		num_move;
	t_list	*copy;

	num_move = (*b)->num;
	copy = *b;
	amount = ft_prov_b(*a, *b, copy->num);
	copy = copy->next;
	while (copy)
	{
		new_am = ft_prov_b(*a, *b, copy->num);
		if (new_am < amount)
		{
			num_move = copy->num;
			amount = new_am;
		}
		copy = copy->next;
	}
	return (num_move);
}
