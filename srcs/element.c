/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:46:45 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/06 10:28:37 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_element	*find_element_index(t_element *element, int index)
{
	t_element	*markup;

	markup = element;
	while (markup)
	{
		if (markup->index == index)
			return (markup);
		markup = markup->next;
	}
	return (markup);
}

int	count_keep(t_stack *stack)
{
	t_element	*front;
	int			i;
	int			len;

	front = stack->front;
	i = 0;
	len = lst_length(stack);
	while (front)
	{
		if (front->keep_in_stack == 1)
			i++;
		front = front->next;
	}
	return (i);
}

int	is_index_in_stack(t_element *element, int index)
{
	while (element)
	{
		if (element->index == index)
			return (1);
		element = element->next;
	}
	return (0);
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->front = NULL;
	stack->back = NULL;
	stack->markup = NULL;
	return (stack);
}

t_element	*create_element(int nbr)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->index = 0;
	element->nbr = nbr;
	element->keep_in_stack = 0;
	element->next = NULL;
	element->previous = NULL;
	return (element);
}
