/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:18:06 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:25:18 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_swap(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "sa", 3))
		made_swap(a);
	else if (!ft_strncmp(line, "sb", 3))
		made_swap(a);
	else if (!ft_strncmp(line, "ss", 3))
	{
		made_swap(a);
		made_swap(b);
	}
}

void	to_rotate(t_list **a, t_list **b, char *line)
{
	if (!ft_strncmp(line, "ra", 3))
		made_rotate(a);
	else if (!ft_strncmp(line, "rb", 3))
		made_rotate(b);
	else if (!ft_strncmp(line, "rr", 3))
	{
		made_rotate(a);
		made_rotate(b);
	}
	else if (!ft_strncmp(line, "rra", 4))
		made_rev_rotate(a);
	else if (!ft_strncmp(line, "rrb", 4))
		made_rev_rotate(b);
	else if (!ft_strncmp(line, "rrr", 4))
	{
		made_rev_rotate(a);
		made_rev_rotate(b);
	}
}
