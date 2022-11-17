/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:28:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:28:17 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*string;
	void		*new;
	char		d;

	d = c;
	string = (char *)s;
	while (n)
	{
		if (*string == d)
		{
			new = (void *)string;
			return (new);
		}
		string++;
		n--;
	}
	return (NULL);
}
