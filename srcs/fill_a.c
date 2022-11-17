/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:30:54 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:30:55 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prov_direction_a(t_list *a, int num, t_prov *move_am)
{
	int	to_a;
	int	past_a;
	int	max;
	int	min;

	to_a = 0;
	past_a = 0;
	move_am->a = 0;
	max = find_max(a);
	min = find_min(a);
	if (num > max || num < min)
		fill_for_utmost(move_am, a, min);
	else
		ft_fill(move_am, a, num);
}

void	fill_for_utmost(t_prov *move_am, t_list *a, int min)
{
	int	past_a;

	past_a = 1;
	while (a->num != min)
	{
		move_am->a++;
		a = a->next;
	}
	a = a->next;
	while (a)
	{
		past_a++;
		a = a->next;
	}
	if (past_a < move_am->a)
	{
		move_am->a = past_a;
		move_am->dir_a = 0;
	}
	else
		move_am->dir_a = 1;
}

void	ft_fill(t_prov *move_am, t_list *a, int num)
{
	int	f_num;
	int	past_a;

	f_num = find_difference(a, num);
	past_a = 1;
	while (a && a->num != f_num)
	{
		move_am->a++;
		a = a->next;
	}
	a = a->next;
	while (a)
	{
		past_a++;
		a = a->next;
	}
	if (past_a < move_am->a)
	{
		move_am->a = past_a;
		move_am->dir_a = 0;
	}
	else
		move_am->dir_a = 1;
}

int	find_difference(t_list *a, int num)
{
	int	f_num;
	int	diff;

	while (a->num - num < 0)
		a = a->next;
	diff = a->num - num;
	f_num = a->num;
	a = a->next;
	while (a)
	{
		if (a->num - num > 0 && a->num - num < diff)
		{
			diff = a->num - num;
			f_num = a->num;
		}
		a = a->next;
	}
	return (f_num);
}

void	fill_struct(t_prov *move_am, t_list *a, int max, int min)
{
	int	past_a;

	past_a = 0;
	move_am->a = 0;
	if (a->num == min)
		return ;
	while (a->num != max)
	{
		move_am->a++;
		a = a->next;
	}
	a = a->next;
	while (a)
	{
		past_a++;
		a = a->next;
	}
	if (past_a < move_am->a)
	{
		move_am->a = past_a;
		move_am->dir_a = 0;
	}
	else
		move_am->dir_a = 1;
}
