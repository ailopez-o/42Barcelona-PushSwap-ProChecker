/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <aitoraudicana@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:56:23 by aitoraudi         #+#    #+#             */
/*   Updated: 2023/01/13 11:58:20 by aitoraudica      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../libs/libft/libft.h"
#include "../libs/miniliblx/minilibx_macos/mlx.h"
#include "../inc/lst_utils.h"
#include "../inc/exec_ops.h"
#include "../inc/parser.h"
#include "../inc/gui_utils.h"
#include <stddef.h>

void	end_program(char	*str);
int		terminate_program(void *param);
void	load_instructions(t_meta *meta);


int	main(int argv, char **argc)
{
	t_meta	meta;

	if (argv == 1)
		return (0);
	meta.print_ops = 1;
	meta.print_stack = 0;
	meta.gui = 1;
	gui_init(&meta);
	if (stack_ini(&meta, argc))
		end_program ("Error");
	index_list(meta.stack_a);
	load_instructions(&meta);
	gui_loop(&meta);
	return (0);
}

void	load_instructions(t_meta *meta)
{
	char	*op;
	t_op	*new_op;
	t_op	*temp;

	new_op = NULL;
	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		new_op = malloc(sizeof (t_op));
		if (new_op == NULL)
			end_program("Malloc Error");
		new_op->op = op;
		new_op->next = NULL;
		if (meta->ops)
		{
			temp->next = new_op;
			temp = new_op;
		}
		else
		{
			meta->ops = new_op;
			temp = meta->ops;
		}
		op = get_next_line(STDIN_FILENO);
	}
}


int	terminate_program(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	mlx_destroy_window(meta->vars.mlx, meta->vars.win);
	stack_lstfree(&meta->stack_a);
	stack_lstfree(&meta->stack_b);
	exit(0);
}

void	end_program(char	*str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit (0);
}
