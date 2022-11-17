/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:20 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:21 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	made_swap(t_list **list)
{
	t_list	*copy;
	t_list	*copy2;

	if (ft_lstsize(*list) < 2 || !*list)
		return ;
	copy = *list;
	copy2 = copy->next;
	copy->next = copy2->next;
	copy2->next = copy;
	*list = copy2;
}

void	made_rotate(t_list **list)
{
	t_list	*temp;
	t_list	*last;

	if (ft_lstsize(*list) < 2 || !*list)
		return ;
	last = *list;
	temp = *list;
	temp = temp->next;
	*list = temp;
	last->next = 0;
	ft_lstadd_back(list, last);
}

void	rotate_el(char type, t_list **first, t_list **second)
{
	if (type == 'a')
	{
		made_rotate(first);
		ft_putstr("ra\n");
	}
	else if (type == 'b')
	{
		made_rotate(second);
		ft_putstr("rb\n");
	}
	else if (type == 'r')
	{
		made_rotate(first);
		made_rotate(second);
		ft_putstr("rr\n");
	}
}

void	rev_rotate(char type, t_list **first, t_list **second)
{
	if (type == 'a')
	{
		made_rev_rotate(first);
		ft_putstr("rra\n");
	}
	else if (type == 'b')
	{
		made_rev_rotate(second);
		ft_putstr("rrb\n");
	}
	else if (type == 'r')
	{
		made_rev_rotate(first);
		made_rev_rotate(second);
		ft_putstr("rrr\n");
	}
}

void	made_rev_rotate(t_list **list)
{
	t_list	*copy;
	t_list	*copy2;

	if (ft_lstsize(*list) < 2 || !*list)
		return ;
	copy = *list;
	copy2 = NULL;
	while (copy->next)
	{
		copy2 = copy;
		copy = copy->next;
	}
	copy2->next = NULL;
	copy->next = *list;
	*list = copy;
}
