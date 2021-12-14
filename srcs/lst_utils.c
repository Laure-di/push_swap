/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:09:48 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/06 10:30:13 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	add_element_back(t_stack *stack, int nbr)
{
	t_element	*element;

	element = create_element(nbr);
	if (!element)
		return (-1);
	element->previous = stack->back;
	stack->back = element;
	if (!element->previous)
	{
		if (stack->front != NULL)
			return (-1);
		stack->front = element;
	}
	else
		element->previous->next = element;
	return (0);
}

int	add_element_front(t_stack *stack, int nbr)
{
	t_element	*element;

	element = create_element(nbr);
	if (!element)
		return (-1);
	element->next = stack->front;
	stack->front = element;
	if (!element->next)
	{
		if (stack->back != NULL)
			return (-1);
		stack->back = element;
	}
	else
		element->next->previous = element;
	return (0);
}

int	lst_length(t_stack *stack)
{
	int			i;
	t_element	*temp;

	i = 0;
	temp = stack->front;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	delete_front_element(t_stack *stack)
{
	t_element	*temp;

	if (stack->front == NULL)
		return (1);
	if (stack->front->next == NULL && stack->front->previous == NULL)
	{
		temp = stack->front;
		stack->front = NULL;
		stack->back = NULL;
		free(temp);
		return (0);
	}
	temp = stack->front;
	stack->front = stack->front->next;
	stack->front->previous = NULL;
	free(temp);
	return (0);
}

int	delete_back_element(t_stack *stack)
{
	t_element	*temp;

	if (stack->back->previous == NULL && stack->back->next == NULL)
	{
		temp = stack->back;
		stack->front = NULL;
		stack->back = NULL;
		free(temp);
		return (0);
	}
	temp = stack->back;
	stack->back = stack->back->previous;
	stack->back->next = NULL;
	free(temp);
	return (0);
}
