/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:30:51 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:30:52 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_list *a)
{
	t_list	*copy;
	int		c;
	int		b;

	copy = a;
	if (ft_lstsize(a) < 2)
	{
		ft_free_list(a);
		exit (0);
	}
	while (a)
	{
		b = a->content;
		a = a->next;
		if (a)
			c = a->content;
		if (b > c)
			return ;
	}
	ft_free_list(copy);
	exit (0);
}

void	ft_check_dup(t_list *list, int num, int counter)
{
	t_list	*copy;
	int		count;

	count = 0;
	copy = list;
	while (list)
	{
		if (list->content == num && count != counter)
		{
			ft_free_list(copy);
			ft_error();
		}
		list = list->next;
		count++;
	}
}

void	check_duplicates(t_list *a)
{
	t_list	*copy;
	int		counter;

	copy = a;
	counter = 0;
	while (a)
	{
		ft_check_dup(copy, a->content, counter);
		a = a->next;
		counter++;
	}
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
