/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_num_correct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:31:10 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:31:11 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_correct(char *argv)
{
	long long int	num;
	int				i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] == '-') || (argv[i] == '+'))
			i++;
		if (!ft_isdigit(argv[i]) && !(argv[i] == ' '))
			return (1);
		i++;
	}
	if (ft_strlen(argv) > 11)
		return (1);
	num = ft_atoi(argv);
	if (-2147483648 > num || num > 2147483647)
		return (1);
	return (0);
}

void	ft_prov_args(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit (1);
	i = 1;
	while (argv[i])
	{
		if (!ft_strchr(argv[i], ' '))
		{
			if (ft_if_correct(argv[i]) == 1)
				ft_error();
		}
		i++;
	}
}

t_list	*split_to_nums(char *argv, t_list *a)
{
	char	**numbers;
	char	**pointer;
	int		num;
	t_list	*copy;

	copy = a;
	numbers = ft_split(argv, ' ');
	pointer = numbers;
	while (*numbers)
	{
		if (ft_if_correct(*numbers) == 1)
		{
			ft_free_list(copy);
			ft_error();
		}
		num = ft_atoi(*numbers);
		ft_lstadd_back(&a, ft_lstnew(num));
		free(*numbers);
		numbers++;
	}
	free(pointer);
	return (a);
}

t_list	*add_to_struct(char **argv)
{
	t_list	*a;
	int		num;
	int		i;

	i = 1;
	a = NULL;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			a = split_to_nums(argv[i], a);
		else
		{
			num = ft_atoi(argv[i]);
			ft_lstadd_back(&a, ft_lstnew(num));
		}
		i++;
	}
	return (a);
}
