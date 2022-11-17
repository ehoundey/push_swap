/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:28:11 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:28:12 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	symbol;

	symbol = c;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n)
	{
		if (*source == symbol)
		{
			*dest = *source;
			dest++;
			return (dest);
		}
		*dest = *source;
		source++;
		dest++;
		n--;
	}
	return (NULL);
}
