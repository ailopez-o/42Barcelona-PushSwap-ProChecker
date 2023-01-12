/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <aitoraudicana@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 20:46:10 by aitoraudi         #+#    #+#             */
/*   Updated: 2023/01/12 22:43:18 by aitoraudica      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/lst_utils.h"
#include "../libs/libft/libft.h"

void	print_row(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	str = ft_strdup(" ");
	if (stack_a)
	{
		free (str);
		str = ft_itoa(stack_a->num);
	}
	ft_putstr_fd(str, 1);
	ft_putstr_fd(" ", 1);
	free (str);
	str = ft_strdup(" ");
	if (stack_b)
	{
		free (str);
		str = ft_itoa(stack_b->num);
	}
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
	free(str);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{	
	ft_putstr_fd("\n////////\n", 1);
	while (stack_a || stack_b)
	{
		print_row(stack_a, stack_b);
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
	ft_putstr_fd("- -\n", 1);
	ft_putstr_fd("a b\n", 1);
	ft_putstr_fd("////////\n\n", 1);
}
