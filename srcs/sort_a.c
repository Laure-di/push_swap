/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:49:07 by lmasson           #+#    #+#             */
/*   Updated: 2021/12/14 17:20:36 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	should_reverse(t_stack *stack)
{
	t_element	*markup;
	t_stack		*front;
	int			previous_kis;
	int			current_kis;

	front = stack;
	current_kis = 0;
	markup = find_markup(front->front);
	previous_kis = count_keep_in_stack(markup, stack->front, markup->index);
	if (stack && lst_length(stack) >= 2
		&& stack->back->keep_in_stack == 0)
	{
		reverse_rotate(&front);
		markup = find_markup(front->front);
		current_kis = count_keep_in_stack(markup, stack->front,
				markup->index);
		if (previous_kis < current_kis)
		{
			stack->markup = markup;
			keep_in_stack(stack->markup, stack->front, stack->markup->index);
			return (1);
		}
		rotate(&front);
	}
	return (0);
}

int	should_swap(t_stack *stack)
{
	t_element	*front;
	t_element	*new_markup;
	int			previous_kis;
	int			current_kis;

	front = stack->front;
	current_kis = 0;
	new_markup = find_markup(front);
	previous_kis = count_keep_in_stack(new_markup, front, new_markup->index);
	if (stack && lst_length(stack) >= 2)
	{
		swap(&front);
		new_markup = find_markup(front);
		current_kis = count_keep_in_stack(new_markup, front, new_markup->index);
		if (previous_kis < current_kis)
		{
			stack->markup = new_markup;
			keep_in_stack(stack->markup, front, stack->markup->index);
			return (1);
		}
		swap(&front);
	}
	return (0);
}

int	need_move(t_stack *stack)
{
	t_element	*front;
	t_element	*markup;
	int			i;
	int			length;

	front = stack->front;
	markup = find_markup(front);
	i = count_keep_in_stack(markup, front, markup->index);
	length = lst_length(stack);
	if (i == length)
		return (0);
	else
		return (1);
}

void	presort_a(t_data *data)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = data->stack_a;
	stack_b = data->stack_b;
	while (need_move(stack_a))
	{
		if (should_swap(stack_a) == 1)
			ps_putstr("sa");
		else if (should_reverse(stack_a) == 1)
			ps_putstr("rra");
		else if (stack_a->front->keep_in_stack == 0)
		{
			push(&stack_a, &stack_b);
			ps_putstr("pb");
		}
		else
		{
			rotate(&stack_a);
			ps_putstr("ra");
		}
	}
}
