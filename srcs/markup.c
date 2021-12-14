/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 20:22:54 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/06 10:31:29 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_keep_in_stack(t_element *element, int *index)
{
	if (*index <= element->index)
	{
		*index = element->index;
		element->keep_in_stack = 1;
	}
	else
		element->keep_in_stack = 0;
}

void	keep_in_stack(t_element *markup, t_element *element,
		int index_markup)
{
	t_element	*next;
	t_element	*previous;
	int			index;

	next = markup;
	previous = element;
	index = index_markup;
	while (next)
	{
		set_keep_in_stack(next, &index);
		next = next->next;
	}
	while (previous && previous->index != index_markup)
	{
		set_keep_in_stack(previous, &index);
		previous = previous->next;
	}
}

void	count_kis(t_element *element, int *index, int *i)
{
	if (*index <= element->index)
	{
		*index = element->index;
		(*i)++;
	}
}

int	count_keep_in_stack(t_element *markup, t_element *element,
	int index_markup)
{
	t_element	*next;
	t_element	*previous;
	int			i;
	int			index;

	next = markup;
	previous = element;
	i = 0;
	index = index_markup;
	while (next)
	{
		count_kis(next, &index, &i);
		next = next->next;
	}
	while (previous && previous->index != index_markup)
	{
		count_kis(previous, &index, &i);
		previous = previous->next;
	}
	return (i);
}

t_element	*find_markup(t_element *element)
{
	t_element	*markup;
	int			index_markup;
	int			current;
	int			to_compare;

	markup = element;
	index_markup = markup->index;
	current = count_keep_in_stack(markup, element, index_markup);
	while (markup)
	{
		to_compare = count_keep_in_stack(markup, element, markup->index);
		if (current < to_compare)
		{
			current = to_compare;
			index_markup = markup->index;
		}
		markup = markup->next;
	}
	return (find_element_index(element, index_markup));
}
