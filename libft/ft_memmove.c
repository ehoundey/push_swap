/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:28:29 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:28:30 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (src > dst)
	{
		while (len)
		{	
			*dest = *source;
			dest++;
			source++;
			len--;
		}
	}
	if (src < dst)
	{
		while (len)
		{
			*(dest + len - 1) = *(source + len - 1);
			len--;
		}
	}
	return (dst);
}
