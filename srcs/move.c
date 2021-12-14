/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:36:47 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/06 12:09:31 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_element **front)
{
	int			nbr;
	int			index;
	t_element	*temp;

	temp = *front;
	nbr = temp->nbr;
	index = temp->index;
	if (temp->next != NULL)
	{
		temp->nbr = temp->next->nbr;
		temp->index = temp->next->index;
		temp->next->nbr = nbr;
		temp->next->index = index;
	}
}

void	rotate(t_stack **stack)
{
	int		nbr;
	int		index;
	int		kis;
	t_stack	*temp;

	temp = *stack;
	nbr = temp->front->nbr;
	index = temp->front->index;
	kis = temp->front->keep_in_stack;
	delete_front_element(temp);
	add_element_back(temp, nbr);
	temp->back->index = index;
	temp->back->keep_in_stack = kis;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack		*temp;
	int			nbr;
	int			index;

	temp = *stack;
	nbr = temp->back->nbr;
	index = temp->back->index;
	delete_back_element(temp);
	add_element_front(temp, nbr);
	temp->front->index = index;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*f_stack;
	t_stack	*t_stack;

	f_stack = *from;
	t_stack = *to;
	add_element_front(t_stack, f_stack->front->nbr);
	t_stack->front->index = f_stack->front->index;
	delete_front_element(f_stack);
}
