/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <aitoraudicana@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:00:26 by aitorlope         #+#    #+#             */
/*   Updated: 2023/01/12 23:11:53 by aitoraudica      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../libs/libft/libft.h"
#include "../inc/instructions.h"
#include "../inc/lst_utils.h"
#include "../inc/utils.h"

static void	get_values(t_meta *meta)
{
	meta->stack_size = stack_lstsize(meta->stack_a);
	meta->max = get_max(meta->stack_a);
	meta->min = get_min(meta->stack_a);
	meta->abs = get_abs(meta->min, meta->max);
	meta->neg = are_negatives(meta->stack_a);
	meta->numops = 0;
}

static int	duplicate_values(t_stack *stack)
{
	t_stack	*stack_loop;

	while (stack)
	{
		stack_loop = stack->next;
		while (stack_loop)
		{
			if (stack->num == stack_loop->num)
				return (1);
			stack_loop = stack_loop->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	stack_ini(t_meta *meta, char **values)
{
	int		i;
	int		num;
	t_stack	*new;

	meta->stack_a = NULL;
	meta->stack_b = NULL;
	i = 1;
	while (values[i])
	{
		if (ft_atoi_ex(values[i], &num) == 0)
			return (EXIT_FAILURE);
		new = stack_lstnew(num);
		stack_lstadd_back(&meta->stack_a, new);
		i++;
	}
	if (duplicate_values(meta->stack_a))
		return (EXIT_FAILURE);
	meta->stack_size = stack_lstsize(meta->stack_a);
	get_values(meta);
	return (EXIT_SUCCESS);
}
