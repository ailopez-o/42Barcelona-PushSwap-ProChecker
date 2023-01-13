/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:02:41 by aitorlope         #+#    #+#             */
/*   Updated: 2023/01/13 23:23:21 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../libs/miniliblx/minilibx_macos/mlx.h"
#include "../inc/gui.h"
#include "../inc/gui_utils.h"
#include "../inc/exec_ops.h"

void	gui_init(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx, WINX, WINY, \
	"push_swap :: PRO CHECKER :: by ailopez-");
	meta->bitmap.img = mlx_new_image(meta->vars.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
			&meta->bitmap.bitxpixel, &meta->bitmap.lines, &meta->bitmap.endian);
}

void	gui_loop(t_meta *meta)
{
	draw_push_swap(meta);
	mlx_hook(meta->vars.win, 2, 0, key_press, meta);
	mlx_hook(meta->vars.win, 17, 0, terminate_program, meta);
	mlx_loop_hook(meta->vars.mlx, run_ops, meta);
	mlx_loop(meta->vars.mlx);
}
