/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:12:20 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/31 18:12:23 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/lst_utils.h"

static void	rr(t_stack *stack)
{
	int	num;
	int	index;

	if (!stack)
		return ;
	stack = stack_lstlast(stack);
	num = stack->num;
	index = stack->index;
	while (stack)
	{
		if (stack->pre == NULL)
		{			
			stack->num = num;
			stack->index = index;
		}
		else
		{
			stack->num = stack->pre->num;
			stack->index = stack->pre->index;
		}
		stack = stack->pre;
	}
}

void	rra(t_meta *meta)
{
	rr(meta->stack_a);
}

void	rrb(t_meta *meta)
{
	rr(meta->stack_b);
}

void	rrr(t_meta *meta)
{
	rr(meta->stack_a);
	rr(meta->stack_b);
}
