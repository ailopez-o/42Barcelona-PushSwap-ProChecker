/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <aitoraudicana@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:39:41 by aitoraudi         #+#    #+#             */
/*   Updated: 2023/01/12 22:53:45 by aitoraudica      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

int	draw_bar(t_meta *meta, t_point start, t_point end, int with);
int	draw_stack_a(t_meta *meta);
int	draw_stack_b(t_meta *meta);
int	draw_push_swap(t_meta *meta);

#endif