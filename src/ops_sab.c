/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sab_pab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:09:42 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/07/31 18:09:44 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"
#include "../inc/instructions.h"

static void	s(t_stack *stack)
{
	int	num;
	int	index;

	if (!stack)
		return ;
	num = stack->next->num;
	index = stack->next->index;
	stack->next->num = stack->num;
	stack->next->index = stack->index;
	stack->num = num;
	stack->index = index;
}

void	sa(t_meta *meta)
{
	s(meta->stack_a);
}

void	sb(t_meta *meta)
{
	s(meta->stack_b);
}

void	ss(t_meta *meta)
{
	s(meta->stack_a);
	s(meta->stack_b);
}

void	sa_ra(t_meta *meta, int reverse)
{
	sa(meta);
	if (reverse)
		rra(meta);
	else
		ra(meta);
}
