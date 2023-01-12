/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:37:53 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:37:55 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/defines.h"

void	pa(t_meta *meta)
{
	t_stack	*stack_orgtop;
	t_stack	**org;
	t_stack	**dest;

	org = &meta->stack_b;
	dest = &meta->stack_a;
	if (*org == NULL)
		return ;
	stack_orgtop = (*org)->next;
	if (*dest == NULL)
		(*org)->next = NULL;
	else
	{
		(*org)->next = *dest;
		(*dest)->pre = (*org);
	}
	*dest = *org;
	*org = stack_orgtop;
	if (*org)
		(*org)->pre = NULL;
}

void	pb(t_meta *meta)
{
	t_stack	*stack_orgtop;
	t_stack	**org;
	t_stack	**dest;

	org = &meta->stack_a;
	dest = &meta->stack_b;
	if (*org == NULL)
		return ;
	stack_orgtop = (*org)->next;
	if (*dest == NULL)
		(*org)->next = NULL;
	else
	{
		(*org)->next = *dest;
		(*dest)->pre = (*org);
	}
	*dest = *org;
	*org = stack_orgtop;
	if (*org)
		(*org)->pre = NULL;
}
