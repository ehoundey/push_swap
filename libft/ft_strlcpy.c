/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:29:17 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:29:18 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	actsize;
	size_t	length;

	length = ft_strlen(src);
	if (dstsize == 0)
		return (length);
	actsize = dstsize - 1;
	while (actsize && *src)
	{
		*dst = *src;
		dst++;
		src++;
		actsize--;
	}
	*dst = '\0';
	return (length);
}
