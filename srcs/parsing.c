/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:47:58 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/14 17:28:54 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init(t_data *data, int argc, char **argv)
{
	data->stack_a = parse_stack(argv, argc);
	if (data->stack_a == NULL)
		return (0);
	data->stack_b = create_stack();
	data->length = argc - 1;
	return (1);
}

void	check_format(t_stack *stack, int nbr)
{
	if (nbr < -2147483648 || 2147483647 < nbr)
		manage_error(&stack);
	if (is_duplicate(stack, nbr))
		manage_error(&stack);
	if (add_element_back(stack, nbr) == -1)
		manage_error(&stack);
}

t_stack	*parse_stack(char **argv, int argc)
{
	int		i;
	int		nbr;
	t_stack	*stack_a;

	i = 1;
	nbr = 0;
	stack_a = create_stack();
	(void)argc;
	while (argv[i])
	{
		if (is_num(argv[i]))
		{
			nbr = ft_atoi(argv[i]);
			check_format(stack_a, nbr);
		}
		else
			manage_error(&stack_a);
		i++;
	}
	get_index(&stack_a->front, &stack_a->front);
	return (stack_a);
}
