/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:18:06 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:18:13 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_line(char *line)
{
	if (!(ft_strncmp(line, "sa", 3) && ft_strncmp(line, "sb", 3)
			&& ft_strncmp(line, "ss", 3) && ft_strncmp(line, "pb", 3)
			&& ft_strncmp(line, "pa", 3) && ft_strncmp(line, "ra", 3)
			&& ft_strncmp(line, "rb", 3) && ft_strncmp(line, "rr", 3)
			&& ft_strncmp(line, "rra", 4) && ft_strncmp(line, "rrb", 4)
			&& ft_strncmp(line, "rrr", 4)))
		return (0);
	else
		return (1);
}

int	do_command(char *line, t_list **a, t_list **b)
{
	if (check_line(line))
		return (1);
	if (*line == 's')
		to_swap(a, b, line);
	else if (*line == 'p')
	{
		line++;
		if (*line == 'a')
			push_el(a, b, "n");
		if (*line == 'b')
			push_el(b, a, "n");
	}
	else if (*line == 'r')
		to_rotate(a, b, line);
	return (0);
}

void	get_data(t_list **a, t_list **b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (do_command(line, a, b))
		{
			free(line);
			write(1, "Error\n", 6);
			return ;
		}
	}
	free(line);
	if (if_sorted(*a) || *b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	ft_prov_args(argc, argv);
	a = add_to_struct(argv);
	check_duplicates(a);
	fill_order(a);
	get_data(&a, &b);
	ft_free_list(a);
}
