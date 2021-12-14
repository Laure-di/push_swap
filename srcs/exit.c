/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:11:27 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/06 10:29:28 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	destroy_stack(t_stack *stack)
{
	while (stack != NULL && stack->front != NULL)
		delete_front_element(stack);
	free(stack);
}

void	destroy_data(t_data *stacks)
{
	destroy_stack(stacks->stack_a);
	destroy_stack(stacks->stack_b);
}

void	destroy_info(t_move_info *info)
{
	free(info);
}

void	manage_error(t_stack **stack_a)
{
	t_stack	*delete;

	if (stack_a)
	{
		delete = *stack_a;
		destroy_stack(delete);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
