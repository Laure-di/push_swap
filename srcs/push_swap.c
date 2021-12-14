/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:44:44 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/14 17:40:52 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!init(&data, argc, argv))
		exit(EXIT_FAILURE);
	if (is_sorted(data.stack_a, data.length))
		exit(EXIT_SUCCESS);
	sort(&data);
	destroy_data(&data);
}
