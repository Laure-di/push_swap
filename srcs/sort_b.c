/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:44:57 by lmasson           #+#    #+#             */
/*   Updated: 2021/12/20 15:28:00 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_element	*find_min(t_element *element)
{
	int			index;
	t_element	*front;

	index = element->index;
	front = element;
	while (front)
	{
		if (front->index < index)
			index = front->index;
		front = front->next;
	}
	return (find_element_index(element, index));
}

t_element	*find_a(t_stack *stack_a, int index_b)
{
	t_element	*element_a;
	t_element	*front;

	element_a = find_min(stack_a->front);
	front = stack_a->front;
	if (index_b < element_a->index)
		return (element_a);
	else
	{
		while (element_a->next && element_a->index < index_b
			&& element_a->index < element_a->next->index)
			element_a = element_a->next;
		if (element_a->index < index_b && element_a->next == NULL)
		{
			while (front->next && front->index < index_b
				&& front->index < front->next->index)
				front = front->next;
			return (front);
		}
	}
	return (element_a);
}

enum e_move	find_move(t_stack *stack, int index)
{
	int			length;
	t_element	*front;
	int			i;

	length = lst_length(stack) / 2;
	front = stack->front;
	i = 0;
	while (front && front->index != index)
	{
		front = front->next;
		i++;
	}
	if (i < length)
		return (R);
	else
		return (RR);
}

int	count_move(t_stack *stack_a, int index_a, t_stack *stack_b, int index_b)
{
	t_element	*front_a;
	t_element	*front_b;
	int			i;

	front_a = stack_a->front;
	front_b = stack_b->front;
	i = 0;
	while (front_a && front_a->index != index_a)
	{
		front_a = front_a->next;
		i++;
	}
	while (front_b && front_b->index != index_b)
	{
		front_b = front_b->next;
		i++;
	}
	return (i);
}

void	find_next_move(t_data *data, t_move_info *info)
{
	t_element	*element_b;

	element_b = data->stack_b->front;
	while (element_b)
	{
		find_compare_move(data->stack_a, element_b, data->stack_b, info);
		element_b = element_b->next;
	}
}
