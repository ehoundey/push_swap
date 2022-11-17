/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:52 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:53 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prov_head_greater(int num, t_list *copy)
{
	int	n;

	n = 0;
	while (copy->next)
	{
		if (copy->next->num > num)
		{
			num = copy->next->num;
			n++;
		}
		copy = copy->next;
	}
	return (n);
}

int	prov_head_index(int num, t_list *copy)
{
	int	n;

	n = 0;
	while (copy->next)
	{
		if (copy->next->num == num + 1)
		{
			n++;
			num++;
		}
		copy = copy->next;
	}
	return (n);
}

void	ft_markup_greater(t_list **a, int head)
{
	t_list	*copy;
	t_list	*pointer;

	copy = *a;
	pointer = copy;
	while (copy->num != head)
	{
		copy->markup = 0;
		copy = copy->next;
	}
	copy->markup = 1;
	copy = copy->next;
	while (copy)
	{
		if (head < copy->num)
		{
			copy->markup = 1;
			head = copy->num;
		}
		else
			copy->markup = 0;
		copy = copy->next;
	}
	*a = pointer;
}

void	ft_markup_index(t_list **a, int head)
{
	t_list	*copy;
	t_list	*pointer;

	copy = *a;
	pointer = copy;
	while (copy)
	{
		if (copy->num != head)
			copy->markup = 0;
		else
		{
			copy->markup = 1;
			head++;
		}
		copy = copy->next;
	}
	*a = pointer;
}
