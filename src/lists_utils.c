/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:40 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/09/20 00:25:07 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"

int	stack_is_sorted(t_stack *first)
{
	t_stack	*stack;

	if (!first)
		return (1);
	stack = first;
	while (stack->next)
	{
		if (stack->num >= stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_lstsize(t_stack *lst)
{
	int	len;

	if (!lst)
		return (0);
	len = 1;
	while (lst->next)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	index_list(t_stack *stack)
{
	int		index;
	t_stack	*top;
	t_stack	*tmp;

	index = 0;
	top = stack;
	while (stack)
	{
		tmp = top;
		while (tmp)
		{
			if (tmp->num < stack->num)
				index++;
			tmp = tmp->next;
		}
		stack->index = index;
		stack = stack->next;
		index = 0;
	}
}
