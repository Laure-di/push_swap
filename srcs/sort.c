/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:14:49 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/20 15:27:34 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_a(t_data *data)
{
	t_element	*front_a;

	front_a = data->stack_a->front;
	data->stack_a->markup = find_markup(front_a);
	keep_in_stack(data->stack_a->markup, front_a, data->stack_a->markup->index);
	presort_a(data);
}

void	sort_b(t_data *data, t_move_info *info)
{
	int	i;

	i = 0;
	while (lst_length(data->stack_b) != 0)
	{
		info = init_info();
		find_next_move(data, info);
		execute_move(data, info);
		push(&data->stack_b, &data->stack_a);
		ps_putstr("pa");
		free(info->a);
		free(info->b);
		free(info);
		i++;
	}
}

void	align_a(t_stack *stack_a, int length)
{
	enum e_move	move;

	move = find_move(stack_a, 0);
	while (!(is_sorted(stack_a, length)))
	{
		if (move == R)
		{
			rotate(&stack_a);
			ps_putstr("ra");
		}
		else if (move == RR)
		{
			reverse_rotate(&stack_a);
			ps_putstr("rra");
		}
	}
}

void	sort(t_data *data)
{
	t_stack		*stack_a;
	t_move_info	*info;

	info = NULL;
	stack_a = data->stack_a;
	sort_a(data);
	if (lst_length(data->stack_a) != data->length)
		sort_b(data, info);
	align_a(data->stack_a, data->length);
}
