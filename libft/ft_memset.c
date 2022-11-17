/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:28:32 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:28:33 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	symbol;
	char			*str;

	str = (char *)b;
	symbol = c;
	while (len)
	{
		*str = symbol;
		str++;
		len--;
	}
	return (b);
}
