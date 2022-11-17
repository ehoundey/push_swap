/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:32:02 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:32:03 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *a, t_list *b)
{
	while (a)
	{
		printf("content=%d   %d\n", a->content, a->num);
		a = a->next;
	}
	printf("---------\n");
	while (b)
	{
		printf("content=%d   %d\n", b->content, b->num);
		b = b->next;
	}
}
