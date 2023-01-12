/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <aitoraudicana@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:42:48 by aitoraudi         #+#    #+#             */
/*   Updated: 2023/01/12 23:28:46 by aitoraudica      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max_index(t_stack *stack);
int		get_min_index(t_stack *stack);
int		get_abs(int max, int min);
int		are_negatives(t_stack *stack);
int		ft_round(double num);
void	end_program(char *str);

#endif
