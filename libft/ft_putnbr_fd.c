/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:28:41 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:28:42 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_writenum(unsigned int num, int fd)
{
	int		i;
	char	c[10];

	i = 0;
	while (num)
	{
		c[i] = num % 10 + '0';
		i++;
		num /= 10;
	}
	while (i > 0)
	{
		write(fd, &c[i - 1], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			num = -n;
		}
		else
			num = n;
		ft_writenum(num, fd);
	}
}
