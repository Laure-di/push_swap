/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:07:22 by lmasson           #+#    #+#             */
/*   Updated: 2021/12/01 21:37:31 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_move_info	*init_info(void)
{
	t_move_info	*info;

	info = malloc(sizeof(t_move_info));
	if (!info)
		return (NULL);
	info->a = NULL;
	info->b = NULL;
	info->move_a = N;
	info->move_b = N;
	info->move = -1;
	return (info);
}
