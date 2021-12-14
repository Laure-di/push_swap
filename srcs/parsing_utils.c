/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:26:11 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/14 17:28:05 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(48 <= str[i] && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(t_stack *stack, int nbr)
{
	int			val;
	t_element	*element;

	if (stack->front == NULL)
		return (0);
	element = stack->front;
	while (element != NULL)
	{
		val = element->nbr;
		if (val == nbr)
			return (1);
		element = element->next;
	}
	return (0);
}

void	get_index(t_element **stack, t_element **current)
{
	t_element	*temp;
	t_element	*next;
	int			i;

	i = 0;
	if (*stack == NULL || *current == NULL)
		return ;
	temp = *stack;
	next = *current;
	while (temp)
	{
		if (temp->nbr < next->nbr)
			i++;
		temp = temp->next;
	}
	next->index = i;
	next = next->next;
	get_index(stack, &next);
}
