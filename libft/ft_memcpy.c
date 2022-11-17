/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:28:25 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:28:26 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*temp;
	char	*source;

	temp = (char *) dst;
	source = (char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n)
	{
		*temp = *source;
		source++;
		temp++;
		n--;
	}
	return (dst);
}
