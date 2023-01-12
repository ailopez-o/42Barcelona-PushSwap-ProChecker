/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:39:14 by aitoraudi         #+#    #+#             */
/*   Updated: 2022/08/03 21:39:18 by aitoraudi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DRAW_H
# define DRAW_H

int	draw_line(t_meta *meta, t_point start, t_point end);
int	my_putpixel(t_meta *meta, t_point pixel);
int	generate_background(t_meta *meta, int backcolor);

#endif
