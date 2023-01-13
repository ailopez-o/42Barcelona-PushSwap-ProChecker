/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:36:01 by aitoraudi         #+#    #+#             */
/*   Updated: 2023/01/13 23:33:56 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../libs/miniliblx/minilibx_macos/mlx.h"
#include "../libs/libft/libft.h"
#include "../inc/instructions.h"
#include "../inc/lst_utils.h"
#include "../inc/gui.h"
#include "../inc/gui_utils.h"
#include "../inc/print.h"
#include "../inc/exec_ops.h"


int	key_press(int key, void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (key == KEY_ESC)
		terminate_program(meta);
	if (key == KEY_1)
		sa(meta);
	if (key == KEY_2)
		sb(meta);
	if (key == KEY_3)
		ra(meta);
	if (key == KEY_4)
		rb(meta);
	if (key == KEY_5)
		rra(meta);
	if (key == KEY_6)
		rrb(meta);
	if (key == KEY_7)
		pa(meta);
	if (key == KEY_8)
		pb(meta);
	if (key == KEY_I)
		execute_next_op(meta);
	if (key == KEY_S)
		meta->run = 1;
	if (key == KEY_P)
		meta->run = 0;
	gui(meta);
	return (1);
}

void	load_colors_stacks(t_bar *bar, int stack)
{
	if (stack == STACKA)
	{
		bar->start.color = FUCSIA;
		bar->end.color = AZUL;
	}
	if (stack == STACKB)
	{
		bar->start.color = FLAMINGO;
		bar->end.color = VERDE;
	}	
}

float	bar_len(int value, int max, int neg)
{
	float	line_len;
	int		abs_value;

	abs_value = value;
	if (abs_value < 0)
		abs_value = -abs_value;
	line_len = WINX / 2;
	if (neg)
		line_len = WINX / 4;
	line_len = line_len * abs_value;
	line_len = line_len / max;
	return (line_len);
}

int	gui(t_meta *meta)
{
	if (meta->gui)
		draw_push_swap(meta);
	if (meta->print_stack)
		print_stack (meta->stack_a, meta->stack_b);
	return (1);
}
