/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prov_markup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:41 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:42 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_mark(t_list *a)
{
	int	n;

	n = 0;
	while (a)
	{
		if (a->markup == 1)
			n++;
		a = a->next;
	}
	return (n);
}

void	prov_markup(t_list **a, char type)
{
	t_list	*copy;
	int		amount;
	int		ord_amount;
	int		head;

	copy = *a;
	head = copy->num;
	amount = 0;
	while (copy)
	{
		if (type == 'i')
			ord_amount = prov_head_index(copy->num, copy);
		else
			ord_amount = prov_head_greater(copy->num, copy);
		if (ord_amount >= amount)
		{
			head = copy->num;
			amount = ord_amount;
		}
		copy = copy->next;
	}
	if (type == 'i')
		ft_markup_index(a, head);
	else
		ft_markup_greater(a, head);
}
