/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:18:06 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:26:59 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	void	*temp;

	pointer = malloc((count) * size);
	if (pointer == NULL)
		return (NULL);
	temp = pointer;
	ft_memset(pointer, 0, (size * count));
	return (temp);
}
