/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:18:06 by ehoundey          #+#    #+#             */
/*   Updated: 2022/02/28 22:26:21 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_prov
{
	int	dir_b;
	int	dir_a;
	int	b;
	int	a;
}				t_prov;

// functions for lists//

t_list		*delete_head(t_list *root);
void		ft_free_list(t_list *list);
t_list		*ft_lstnewfornum(int content);

// utilis //

void		print_list(t_list *a, t_list *b);

//*************************//

void		num_to_move_back(t_list **a, t_list **b);
void		check_if_sorted(t_list *a);
void		sort_data(t_list **a, t_list **b);
void		check_duplicates(t_list *a);
void		ft_check_dup(t_list *list, int num, int counter);
void		ft_error(void);
void		made_swap(t_list **list);
void		swap_el(char type, t_list **a, t_list **b);
void		push_el(t_list **first, t_list **second, char *ms);
void		made_rotate(t_list **list);
void		rotate_el(char type, t_list **first, t_list **second);
void		made_rev_rotate(t_list **list);
void		rev_rotate(char type, t_list **first, t_list **second);
void		fill_order(t_list *a);
void		sort_data(t_list **a, t_list **b);
void		prov_markup(t_list **a, char type);
int			prov_head_greater(int num, t_list *copy);
int			prov_head_index(int num, t_list *copy);
void		ft_markup_greater(t_list **a, int head);
void		ft_markup_index(t_list **a, int head);
int			ft_finish(t_list *a);
int			if_sorted(t_list *a);
int			count_mark(t_list *a);
void		ft_push_to_b(t_list **a, t_list **b);
int			if_sorted(t_list *a);
int			ft_finish(t_list *a);
int			find_min(t_list *list);
void		move_back(t_list **a, t_list **b);
int			ft_prov_num(t_list **a, t_list **b);
void		print_a_b(t_list *a, t_list *b);
int			ft_prov_b(t_list *a, t_list *b, int num);
void		prov_direction_b(t_list *b, int num, t_prov *move_am);
void		prov_direction_a(t_list *a, int num, t_prov *move_am);
int			ft_go_to_a(t_list *a, int num);
void		new_sort_data(t_list **a, t_list **b);
int			ft_go_b(t_list *b, int num);
void		ft_last_prov(t_list **a, t_list **b);
void		from_b_to_a(t_list **a, t_list **b, int num);
void		prov_direction_a(t_list *a, int num, t_prov *move_am);
void		fill_for_utmost(t_prov *move_am, t_list *a, int min);
void		ft_fill(t_prov *move_am, t_list *a, int num);
int			find_difference(t_list *a, int num);
void		fill_struct(t_prov *move_am, t_list *a, int max, int min);
int			find_max(t_list *a);
void		rotate_to_choose(t_list **a, t_list **b,
				t_prov *move_am, char type);
void		sort_small(t_list **a, t_list **b, int size);
void		sort_three(t_list **a, t_list **b);
void		sort_four(t_list **a, t_list **b);
void		sort_five(t_list **a, t_list **b);
void		ft_prov_args(int argc, char **argv);
int			ft_if_correct(char *argv);
t_list		*add_to_struct(char **argv);
t_list		*split_to_nums(char *argv, t_list *a);
void		get_data(t_list **a, t_list **b);
int			do_command(char *line, t_list **a, t_list **b);
void		to_rotate(t_list **a, t_list **b, char *line);
void		to_swap(t_list **a, t_list **b, char *line);

#endif
