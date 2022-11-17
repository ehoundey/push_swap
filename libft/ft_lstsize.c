/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:28:08 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:28:09 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	amount;

	amount = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		amount++;
	}
	return (amount);
}
