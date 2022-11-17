/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:29:11 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:29:12 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlength;
	size_t	srclength;
	size_t	actsize;

	dstlength = ft_strlen(dst);
	srclength = ft_strlen(src);
	actsize = dstsize - dstlength - 1;
	if (dstsize == 0)
		return (srclength);
	if (dstlength >= dstsize)
		return (dstsize + srclength);
	dst = dst + dstlength;
	while (*src && actsize)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
		actsize--;
	}
	*dst = '\0';
	return (dstlength + srclength);
}
