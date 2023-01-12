/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:09:33 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/31 18:09:36 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/lst_utils.h"

static void	r(t_stack *stack)
{
	int	num;
	int	index;

	if (!stack)
		return ;
	num = stack->num;
	index = stack->index;
	while (stack)
	{
		if (stack->next == NULL)
		{
			stack->num = num;
			stack->index = index;
		}
		else
		{
			stack->num = stack->next->num;
			stack->index = stack->next->index;
		}
		stack = stack->next;
	}
}

void	ra(t_meta *meta)
{
	r(meta->stack_a);
}

void	rb(t_meta *meta)
{
	r(meta->stack_b);
}

void	rr(t_meta *meta)
{
	r(meta->stack_a);
	r(meta->stack_b);
}
