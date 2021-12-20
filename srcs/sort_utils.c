/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:28:28 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/20 16:04:34 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	equal_move(t_data *data, t_move_info *info, int a, int b)
{
	if (a != data->stack_a->front->index && b != data->stack_b->front->index)
	{
		if (info->move_a == R)
		{
			rotate(&data->stack_a);
			rotate(&data->stack_b);
			ps_putstr("rr");
		}
		else if (info->move_a == RR)
		{
			reverse_rotate(&data->stack_a);
			reverse_rotate(&data->stack_b);
			ps_putstr("rrr");
		}
	}
	else
		different_move(data, info, a, b);
}

void	one_move(t_stack *stack, char c, enum e_move move_stack)
{
	char	*str;

	if (move_stack == R)
	{
		str = ft_strjoin("r", c);
		rotate(&stack);
		ps_putstr(str);
	}
	else
	{
		str = ft_strjoin("rr", c);
		reverse_rotate(&stack);
		ps_putstr(str);
	}
	free(str);
}

void	different_move(t_data *data, t_move_info *info, int a, int b)
{
	if (a != data->stack_a->front->index)
		one_move(data->stack_a, 'a', info->move_a);
	if (b != data->stack_b->front->index)
		one_move(data->stack_b, 'b', info->move_b);
}

void	execute_move(t_data *data, t_move_info *info)
{
	int	a;
	int	b;

	a = info->a->index;
	b = info->b->index;
	while (!(a == data->stack_a->front->index
			&& b == data->stack_b->front->index))
	{
		if (info->move_a == info->move_b && a != data->stack_a->front->index
			&& data->stack_b->front->index != b)
			equal_move(data, info, a, b);
		else
			different_move(data, info, a, b);
	}
}

void	find_compare_move(t_stack *stack_a, t_element *b_element,
		t_stack *stack_b, t_move_info *info)
{
	t_move_info	*new;

	new = init_info();
	new->b = b_element;
	new->a = find_a(stack_a, b_element->index);
	new->move_a = find_move(stack_a, new->a->index);
	new->move_b = find_move(stack_b, new->b->index);
	new->move = count_move(stack_a, new->a->index, stack_b, new->b->index);
	if (info->a == NULL || new->move < info->move)
	{
		if (info->a != NULL)
			free(info->a);
		info->a = create_element(new->a->nbr);
		info->a->index = new->a->index;
		if (info->b)
			free(info->b);
		info->b = create_element(new->b->nbr);
		info->b->index = new->b->index;
		info->move_a = new->move_a;
		info->move_b = new->move_b;
		info->move = new->move;
	}
	free(new);
}
