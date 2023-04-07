/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:56:23 by aitoraudi         #+#    #+#             */
/*   Updated: 2023/01/14 00:01:05 by ailopez-         ###   ########.fr       */
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
void	print_controls(int num_ops_load);

int	main(int argv, char **argc)
{
	t_meta	meta;

	if (argv == 1)
		return (0);
	meta.print_ops = 1;
	meta.print_stack = 0;
	meta.gui = 1;
	meta.run = 0;
	gui_init(&meta);
	if (stack_ini(&meta, argc))
		end_program ("Error");
	index_list(meta.stack_a);
	load_instructions(&meta);
	print_controls(meta.numops_load);
	gui_loop(&meta);
	return (0);
}

void	print_controls(int num_ops_load)

{
 	printf("%s ___  ___   ___     ___  _  _  ___  ___  _  __ ___  ___ \n", KGRN);
 	printf("| _ \\| _ \\ / _ \\   / __|| || || __|/ __|| |/ /| __|| _ \n");
 	printf("|  _/|   /| (_) | | (__ | __ || _|| (__ | ' < | _| |   /\n");
 	printf("|_|  |_|_\\ \\___/   \\___||_||_||___|\\___||_|\\_\\|___||_|_\n%s", DEF_COLOR);
 	printf("\nby @ailopez-\n");

	printf("\n\n");
	printf("%s[%d] instructions loaded'\n", KYEL, num_ops_load);
	printf("%s::: Readed ops Sort :::\n", KCYN);
	printf("%sKey I :: Step by step\n", KWHT);
	printf("%sKey S :: Run all the ops\n", KWHT);
	printf("%sKey P :: Pause\n", KWHT);	
	printf("%s::: Manual Sort :::\n", KCYN);
	printf("%sKey 1 :: Exec 'sa'\n", KWHT);	
	printf("%sKey 2 :: Exec 'sb'\n", KWHT);	
	printf("%sKey 3 :: Exec 'ra'\n", KWHT);	
	printf("%sKey 4 :: Exec 'rb'\n", KWHT);
	printf("%sKey 5 :: Exec 'rra'\n", KWHT);	
	printf("%sKey 6 :: Exec 'rrb'\n", KWHT);
	printf("%sKey 7 :: Exec 'pa'\n", KWHT);	
	printf("%sKey 8 :: Exec 'pb'\n", KWHT);
	printf("%s\n",DEF_COLOR);
}

void	load_instructions(t_meta *meta)
{
	char	*op;
	t_op	*new_op;
	t_op	*temp;

	new_op = NULL;
	op = get_next_line(STDIN_FILENO);
	meta->ops = NULL;
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
	meta->numops_load = 0;
	temp = meta->ops;
	while (temp)
	{	
		temp = temp->next;
		meta->numops_load++;
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
