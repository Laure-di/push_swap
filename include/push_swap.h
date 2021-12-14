/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:16:57 by lmasson           #+#    #+#             */
/*   Updated: 2021/12/14 17:40:59 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

enum e_move
{
	N,
	PA,
	PB,
	SA,
	SB,
	R,
	RR,
	RRR,
};

typedef struct s_element
{
	int					index;
	int					nbr;
	int					keep_in_stack;
	struct s_element	*next;
	struct s_element	*previous;
}	t_element;

typedef struct s_stack
{
	t_element			*front;
	t_element			*back;
	t_element			*markup;
}	t_stack;

typedef struct s_data
{
	int					length;
	t_stack				*stack_a;
	t_stack				*stack_b;
}	t_data;

typedef struct s_move_info
{
	t_element	*a;
	t_element	*b;
	enum e_move	move_a;
	enum e_move	move_b;
	int			move;

}	t_move_info;

void		print_data(t_data data);
			/* push_swap.c */
int			main(int argc, char **argv);
void		push_swap(t_data *data);
int			init(t_data *data, int argc, char **argv);
/* parsing.c */
t_stack		*parse_stack(char **argv, int argc);
void		get_index(t_element **stack, t_element **current);
int			is_duplicate(t_stack *stack, int nbr);
int			is_num(char *str);
	/* sort_utils.c */
int			is_sorted(t_stack *stack, int length);
void		ps_putstr(char *str);
char		*ft_strjoin(char *s1, char stack_name);
int			ft_strlen(char *str);
/*lst_utils.c*/
int			delete_back_element(t_stack *stack);
int			delete_front_element(t_stack *stack);
int			lst_length(t_stack *stack);
int			add_element_front(t_stack *stack, int nbr);
int			add_element_back(t_stack *stack, int nbr);
/* element.c */
t_element	*find_element_index(t_element *element, int index);
t_stack		*create_stack(void);
t_element	*create_element(int nbr);
int			is_index_in_stack(t_element *element, int index);
/* markup */
int			count_keep_in_stack(t_element *markup,
				t_element *element, int index_markup);
void		keep_in_stack(t_element *markup,
				t_element *element, int index_markup);
t_element	*find_markup(t_element *element);
/* sort.c */
void		sort(t_data *data);
void		different_move(t_data *data, t_move_info *info, int a, int b);
/* sort_a.c */
void		sort_a(t_data *data);
int			should_swap(t_stack *stack);
void		presort_a(t_data *data);
/*sort_b.c*/
void		find_next_move(t_data *data, t_move_info *info);
void		find_compare_move(t_stack *stack_a,
				t_element *b_element, t_stack *stack_b, t_move_info *info);
t_element	*find_a(t_stack *stack_a, int index_b);
enum e_move	find_move(t_stack *stack, int index);
/* info_move.c*/
t_move_info	*init_info(void);
	/* move.c */
void		swap(t_element **front);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
void		push(t_stack **from, t_stack **to);
/* ft_atoi.c */
int			ft_atoi(char *str);
t_element	*create_element(int nbr);
t_stack		*create_stack(void);
/* exit.c */
void		manage_error(t_stack **stack_a);
void		destroy_data(t_data *stacks);
void		destroy_stack(t_stack *stack);
void		destroy_info(t_move_info *info);
void		execute_move(t_data *data, t_move_info *info);
void		one_move(t_stack *stack, char c, enum e_move move_stack);
void		equal_move(t_data *data, t_move_info *info, int a, int b);
int			count_move(t_stack *stack_a, int index_a,
				t_stack *stack_b, int index_b);

#endif
