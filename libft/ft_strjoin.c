/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:29:08 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:29:09 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	char		*new;

	newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (NULL);
	new = newstr;
	while (s1 && *s1)
	{
		*newstr = *s1;
		newstr++;
		s1++;
	}
	while (*s2)
	{
		*newstr = *s2;
		newstr++;
		s2++;
	}
	*newstr = '\0';
	return (new);
}
