/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitoraudicana <aitoraudicana@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:22:49 by aitorlope         #+#    #+#             */
/*   Updated: 2023/01/12 23:55:43 by aitoraudica      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_OPS_H
# define EXEC_OPS_H

int		exec_ops(t_meta *meta, char *op);
void	get_instructions(t_meta *meta);
int		execute_next_op(t_meta *meta);

#endif
