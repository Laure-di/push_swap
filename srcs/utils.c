/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:51:36 by lauremass         #+#    #+#             */
/*   Updated: 2021/12/14 17:26:35 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sorted(t_stack *stack, int length)
{
	int			i;
	t_element	*temp;

	i = 0;
	temp = stack->front;
	while (temp && temp->index == i)
	{
		i++;
		temp = temp->next;
		if (i == length)
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char stack_name)
{
	char	*cmd;
	int		i;
	int		j;

	j = 0;
	if (!s1)
		return (NULL);
	i = ft_strlen(s1) + 1;
	cmd = malloc(sizeof(char *) * i + 1);
	i = 0;
	if (!cmd)
		return (NULL);
	while (s1[i])
	{
		cmd[i] = s1[i];
		i++;
	}
	cmd[i++] = stack_name;
	cmd[i] = '\0';
	return (cmd);
}

void	ps_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
